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
        if (pipeClock.getElapsedTime().asSeconds() > 2.0f) {
            float randomY = static_cast<float>(std::rand() % 200 + 150); // 150 ile 350 arasında rastgele yükseklik olacak.
            // Borular hep aynı hizada gelmesin diye 150 ile 350 arasında rastgele bir Y koordinatı seçtik.
            pipes.emplace_back(800.f, randomY);
            // Yeni boruyu hafızada kopyalama hatası olmasın diye emplace_back ile doğrudan listede yarattık.
            pipeClock.restart();
        }
       flappy.update();

        // Borularin pozisyonunu guvenli sekilde guncelle (Sola kaydir)
        for (size_t i = 0; i < pipes.size(); i++) {
            pipes[i].update(0.016f);
        }

        // HAFIZA YÖNETİMİ: Ekrandan çıkan boruları temizle
        if (!pipes.empty() && pipes.front().isOffScreen()) {
            pipes.erase(pipes.begin());
        }

        // ÇARPIŞMA KONTROLÜ: SFML 3'e uygun şekilde kuşun sınır kutusunu (Rect) alıyoruz
        sf::Rect<float> birdBounds = flappy.getBounds(); 
        
        // Listede o an aktif olan tüm boruları tek tek dönüp kuşa çarpmış mı bakıyoruz
        for (size_t i = 0; i < pipes.size(); i++) {
            if (pipes[i].checkCollision(birdBounds)) {
                window.close(); // Çarpışma varsa pencereyi anında kapat!
            }
        }

        // 1. ADIM: Ekranı temizlemesi için (Açık mavi bir renk ile).
        window.clear(sf::Color(135, 206, 235));
        flappy.draw(window);
        // Boruyu ekrana çizelim.
        for (size_t i = 0; i < pipes.size(); i++) {
            pipes[i].draw(window);
        }

        // 2. ADIM: Çizilenleri ekrana yansıtmak için.
        window.display();
    }

    return 0;
}