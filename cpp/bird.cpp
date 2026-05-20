#include "bird.hpp"

Bird::Bird(){
    birdY = 300.f;
    velocity = 0.f;
    bird.setRadius(20.f);
    bird.setFillColor(sf::Color::Yellow);
    bird.setPosition({100.f, birdY});
}

void Bird::update(){
    velocity += gravity; // Yerçekiminin hızı arttırması için.
    birdY += velocity; // Hızın kuşun konumunu değiştirmesi için.
    bird.setPosition({100.f, birdY}); // Kuşun görüntüsünü yeni koordinata taşıması için.
}

void Bird::draw(sf::RenderWindow& window){
     window.draw(bird);  // Bu kod kuşumuzu çizdirmek için.
}

void Bird::jump(){
    velocity = jumpForce; // Zıplayınca kuş yukarı yöne gitsin.
}