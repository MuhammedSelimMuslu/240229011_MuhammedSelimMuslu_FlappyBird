#ifndef Bird_hpp
#define Bird_hpp

#include <SFML/Graphics.hpp>

class Bird {
    public:

    explicit Bird(const sf::Texture& texture); // Başlangıç değerleri için.
    void update(); // Hareket ve yer çekimi hesabı için.
    void draw(sf::RenderWindow& window); // Ekrana çizer.
    void jump(); // Zıplaması için.
    void reset(); // Kuşun başlangıç pozisyonuna gitmesini ve hızının sıfırlanmasını sağlayan fonksiyon.
    sf::Rect<float> getBounds() const;

    private:

    sf::Sprite bird;

    float birdY = 300.f; // Kuşun başlangıç yüksekliğini ayarlamış olduk.
    float velocity = 0.f; // Kuşun başlangıç hızını ayarlamış olduk.
    const float gravity = 0.5f; // Her karede artacak olan yerçekimi.
    const float jumpForce = -8.0f; // Zıplayınca hızı yukarı yönde itecek olan kuvvet.

};

#endif