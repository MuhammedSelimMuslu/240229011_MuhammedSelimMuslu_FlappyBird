#ifndef Bird_hpp
#define Bird_hpp

#include <SFML/Graphics.hpp>

class Bird {
    public:

    Bird(); // Başlangıç değerleri için.
    void update(); // Hareket ve yer çekimi hesabı için.
    void draw(sf::RenderWindow& window); // Ekrana çizer.
    void jump(); // Zıplaması için.
    sf::Rect<float> getBounds() const;

    private:

    sf::CircleShape bird; // Kuşun boyutunu 20 piksel yarıçapında olarak belirlemiş olduk.
    float birdY = 300.f; // Kuşun başlangıç yüksekliğini ayarlamış olduk.
    float velocity = 0.f; // Kuşun başlangıç hızını ayarlamış olduk.
    const float gravity = 0.5f; // Her karede artacak olan yerçekimi.
    const float jumpForce = -8.0f; // Zıplayınca hızı yukarı yönde itecek olan kuvvet.

};

#endif