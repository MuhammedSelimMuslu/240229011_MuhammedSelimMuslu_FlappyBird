#include "bird.hpp"

Bird::Bird(const sf::Texture& texture) : bird(texture) {
    birdY = 300.f;
    velocity = 0.f;
    
    bird.setScale({2.0f, 2.0f});
    bird.setOrigin({17.f, 12.f});
    bird.setPosition({100.f, birdY});
}

void Bird::update(){
    velocity += gravity; // Yerçekiminin hızı arttırması için.
    birdY += velocity; // Hızın kuşun konumunu değiştirmesi için.
    bird.setPosition({100.f, birdY}); // Kuşun görüntüsünü yeni koordinata taşıması için.

    float angle = velocity * 4.0f;
    if(angle < -30.f) angle = -30.f;
    if(angle > 70.f) angle = 70.f;
    bird.setRotation(sf::degrees(angle));
    // Kuşun zıplamasına ve düşmesine göre eğim eklendi.
}   

void Bird::draw(sf::RenderWindow& window){
     window.draw(bird);  // Bu kod kuşumuzu çizdirmek için.
}

void Bird::jump(){
    velocity = jumpForce; // Zıplayınca kuş yukarı yöne gitsin.
}

sf::Rect<float> Bird::getBounds() const {
    // 1. Önce kuşun orijinal ve geniş sınırlarını alıyoruz
    sf::Rect<float> bounds = bird.getGlobalBounds();
    
    // 2. Etraftaki şeffaf pikselleri ve kafa eğme payını tıraşlıyoruz (Daha affedici Hitbox)
    bounds.position.x += 3.f;  // Soldan 3 piksel daralttık.
    bounds.position.y += 3.f;  // Üstten 3 piksel daralttık
    bounds.size.x -= 6.f;     // Toplam genişliği 6 piksel küçülttük.
    bounds.size.y -= 6.f;     // Toplam yüksekliği 6 piksel küçülttük.
    
    return bounds;
}

void Bird::reset() {
    birdY = 300.f;
    velocity = 0.f; // Kuşun başlangıçta olacak olan aşağı düşüş hızı.
    bird.setPosition({100.f, 300.f}); // Kuşu ekranın solunda ve dikeyde ortada olacak şekilde başlatıyoruz.
    bird.setRotation(sf::degrees(0.f));
}