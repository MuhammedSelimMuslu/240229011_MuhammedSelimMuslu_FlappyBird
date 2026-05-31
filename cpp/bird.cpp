#include "bird.hpp"

Bird::Bird(const sf::Texture& texture) : bird(texture) {
    birdY = 300.f;
    velocity = 0.f; // Başlangıç düşüş hızı.
    
    bird.setScale({2.0f, 2.0f});
    bird.setOrigin({17.f, 12.f}); // Kuş aşağı yada yukarı gittiğinde merkezden dönmesi için.
    bird.setPosition({100.f, birdY});
}

void Bird::update(){
    velocity += gravity; 
    birdY += velocity; 
    bird.setPosition({100.f, birdY}); // Kuşun görüntüsünü yeni koordinata taşıması için.

    float angle = velocity * 4.0f;
    if(angle < -30.f) angle = -30.f;
    if(angle > 70.f) angle = 70.f;
    bird.setRotation(sf::degrees(angle));
    // Kuşun zıplamasına ve düşmesine göre eğim eklendi.
}   

void Bird::draw(sf::RenderWindow& window){
     window.draw(bird);  
}

void Bird::jump(){
    velocity = jumpForce; 
}

sf::Rect<float> Bird::getBounds() const {
    // Önce kuşun orijinal ve geniş sınırlarını alacağız.
    sf::Rect<float> bounds = bird.getGlobalBounds();
    
    // Etraftaki şeffaf pikselleri ve kafa eğme payını tıraşlayacağız.
    bounds.position.x += 3.f;  
    bounds.position.y += 3.f;  
    bounds.size.x -= 6.f;     
    bounds.size.y -= 6.f;     
    
    return bounds;
}

void Bird::reset() { 
    // Oyun tekrar başladığında ayarlanacak özellikleri için.
    birdY = 300.f;
    velocity = 0.f; 
    bird.setPosition({100.f, 300.f}); 
    bird.setRotation(sf::degrees(0.f)); // Burnunu düz yapması için.
}