#include <SFML/Graphics.hpp>
// SFML 3 ile birlikte Event kontrolü için optional kütüphanesini dahil etmemiz gerekiyor
#include <optional> 

int main() {
    // SFML 3'te VideoMode artık bir vektör boyutu beklediği için değerleri { } içine alıyoruz
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy Bird - C++ & SFML");
    
    // Oyunun saniyedeki kare hızını (FPS) 60'a sabitliyoruz
    window.setFramerateLimit(60);

    // Oyun döngüsü (Game Loop)
    while (window.isOpen()) {
        
        // SFML 3'te Event mantığı tamamen değişti ve çok daha güvenli olan std::optional yapısına geçildi
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            // event->is<> metodunu kullanarak olayın türünü kontrol ediyoruz
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // 1. ADIM: Ekranı temizle (Gökyüzü mavisi bir renk ile)
        window.clear(sf::Color(135, 206, 235));

        // 2. ADIM: Çizim işlemleri (Kuş, borular, zemin vb. buraya gelecek)

        // 3. ADIM: Çizilenleri ekrana yansıt
        window.display();
    }

    return 0;
}