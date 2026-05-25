#include <SFML/Graphics.hpp>
// SFML 3 ile birlikte Event kontrolü için optional kütüphanesini dahil etmemiz gerekiyor.
#include <optional> 
#include <vector>
#include "pipe.hpp"
#include <cstdlib> // Rastgele sayı üretmek (rand) için eklendi.
#include <ctime>   // Rastgele süre üretmek (time) için eklendi.
#include "bird.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // SFML 3'te VideoMode artık bir vektör boyutu beklediği için değerleri { } içine almamız gerekiyor.
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy Bird - C++ & SFML");
    // Oyunun saniyedeki kare hızını (FPS) 60'a sabitledik.
    window.setFramerateLimit(60);

    bool isGameOver = false;

    // Skor sistemimiz için tanımlama yapacağız.
    int score = 0;

    // Skorumuzu ekrana yazdırabilmek için yazı fontu yükleyeceğiz.
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        // Font dosyası yüklenemezse hata vermemesi için oyunu kapatacağız.
        return -1;
    }
    
    // Ekranda gözükecek skor yazısını tanımlayıp özelliklerini yazacağız.
    sf::Text scoreText(font);
    scoreText.setString("0");
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);

    // Skorun gözükeceği yeri ayarlıyoruz.
    scoreText.setPosition({380.f, 20.f});

    Bird flappy;
    // X = 700 konumunda ve ortadaki boşluğun Y = 200 koordinatında başladığı bir boru oluşturduk.
    std::vector<Pipe> pipes;
    pipes.emplace_back(700.f, 200.f);
    sf::Clock pipeClock;
    // Oyun döngüsü (Game Loop)
    while (window.isOpen()) {

        // SFML 3'te Event mantığı tamamen değişti ve çok daha güvenli olan std::optional yapısına geçtik.
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            // event->is<> metodunu kullanarak olayın türünü kontrol ediyoruz.
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }  
            
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (keyPressed->code == sf::Keyboard::Key::Space){
                    flappy.jump();
                }
            }
        }
        
        if(!isGameOver){
            if (pipeClock.getElapsedTime().asSeconds() > 2.0f) {
            float randomY = static_cast<float>(std::rand() % 200 + 150); // 150 ile 350 arasında rastgele yükseklik olacak.
            // Borular hep aynı hizada gelmesin diye 150 ile 350 arasında rastgele bir Y koordinatı seçtik.
            pipes.emplace_back(800.f, randomY);
            // Yeni boruyu hafızada kopyalama hatası olmasın diye emplace_back ile doğrudan listede yarattık.
            pipeClock.restart();
        }}

        // Kuşun koordinatına göre ekran dışında olup olmadığını kontrol ediyoruz.
        sf::Rect<float> birdBounds = flappy.getBounds();
       
        // Kuş yere düşerse yada yukarı çarparsa oyunu bitir.
        if ((birdBounds.position.y + birdBounds.size.y > 600.f) || (birdBounds.position.y < 0.f)){
            isGameOver = true;
        }

        if(!isGameOver){
            flappy.update();
        
        // Borularin pozisyonunu güvenli şekilde güncelleyeceğiz. (Sola kaydir)
            for (size_t i = 0; i < pipes.size(); i++) {
            pipes[i].update(0.016f);
            }
        }
        

        // Boruya çarparsa oyunu bitir.
        for(size_t i = 0; i < pipes.size(); ++i){
            if (pipes[i].checkCollision(birdBounds)){
                isGameOver = true;
            }

        // Kuş boruyu geçtiğinde skoru arttıracağız.
        // Kuşun X koordinatına göre borunun X koordinatından büyükse ve boru daha geçilmediyse passed değişkenine ve pipes[i] nesnesinin boru koordinatına göre kontrol ediyoruz.
        sf::Rect<float> upperBounds = pipes[i].getUpperBounds();

            if (!pipes[i].passed && upperBounds.position.x + upperBounds.size.x < 100.f){
            score++;
            scoreText.setString(std::to_string(score)); // Ekrandaki skor yazısını güncellemek için.
            pipes[i].passed = true; // Bu kod borudan skor eklediğimizi belirtmek için sonra hata olmasın diye.
            }
        }

        // Hafıza Yönetimi: Ekrandan çıkan boruları temizliyoruz.
        if (!pipes.empty() && pipes.front().isOffScreen()) {
            pipes.erase(pipes.begin());
        }

        // Ekranı temizlemesi için (Açık mavi bir renk ile).
        window.clear(sf::Color(135, 206, 235));
        flappy.draw(window);
        // Boruyu ekrana çizelim.
        for (size_t i = 0; i < pipes.size(); i++) {
            pipes[i].draw(window);
        }

        // Skoru yazdırıyoruz.
        window.draw(scoreText);

        // Çizilenleri ekrana yansıtmak için.
        window.display();
    }

    return 0;
}