#ifndef Bird_hpp
#define Bird_hpp

#include <SFML/Graphics.hpp>

class Bird {
    public:

    explicit Bird(const sf::Texture& texture); // Başlangıç değerleri için.
    void update(); 
    void draw(sf::RenderWindow& window); 
    void jump(); 
    void reset(); 
    sf::Rect<float> getBounds() const;

    private:

    sf::Sprite bird; // Kuşun görsel nesnesi için.

    float birdY = 300.f; // Kuşun başlangıç yüksekliği ve hızı ayarlandı.
    float velocity = 0.f; 
    const float gravity = 0.5f; // Her karede artacak olan yerçekimi.
    const float jumpForce = -8.0f; // Zıplayınca hızı yukarı yönde itecek olan kuvvet.

};

#endif