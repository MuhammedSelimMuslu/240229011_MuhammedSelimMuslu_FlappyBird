#include <SFML/Graphics.hpp>
// SFML 3 ile birlikte Event kontrolü için optional kütüphanesini dahil etmemiz gerekiyor.
#include <optional> 

int main() {
    // SFML 3'te VideoMode artık bir vektör boyutu beklediği için değerleri { } içine almamız gerekiyor.
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy Bird - C++ & SFML");
    
    // Oyunun saniyedeki kare hızını (FPS) 60'a sabitledik.
    window.setFramerateLimit(60);

    sf::CircleShape bird(20.f); // Kuşun boyutunu 20 piksel yarıçapında olarak belirlemiş olduk.
    bird.setFillColor(sf::Color::Yellow); // Bu kodla birlikte kuşumuzun rengini sarı yapmış olduk.

    float birdY = 300.f; // Kuşun başlangıç yüksekliğini ayarlamış olduk.
    float velocity = 0.f; // Kuşun başlangıç hızını ayarlamış olduk.
    float gravity = 0.5f; // Her karede artacak olan yerçekimi.
    float jumpForce = -8.0f; // Zıplayınca hızı yukarı yönde itecek olan kuvvet.

    // Oyun döngüsü (Game Loop)
    while (window.isOpen()) {

        velocity += gravity; // Yerçekiminin hızı arttırması için.
        birdY += velocity; // Hızın kuşun konumunu değiştirmesi için.
        bird.setPosition({100.f, birdY}); // Kuşun görüntüsünü yeni koordinata taşıması için.

        // SFML 3'te Event mantığı tamamen değişti ve çok daha güvenli olan std::optional yapısına geçtik.
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            // event->is<> metodunu kullanarak olayın türünü kontrol ediyoruz.
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            
        }

        // 1. ADIM: Ekranı temizlemesi için (Açık mavi bir renk ile)
        window.clear(sf::Color(180, 230, 235));

        // 2. ADIM: Çizim işlemleri (Kuş, borular, zemin vb. buraya gelecek).
        window.draw(bird);  // Bu kod kuşumuzu çizdirmek için.

        // 3. ADIM: Çizilenleri ekrana yansıtmak için
        window.display();
    }

    return 0;
}