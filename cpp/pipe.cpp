#include "pipe.hpp"

Pipe::Pipe(float xPos, float gapY) : posX(xPos){ // Boru oluştuğunda olacak özellikleri.
    // | Üst boru |
    upperShape.setSize({pipeWidth, gapY}); // Genişliği ve yüksekliği.
    upperShape.setFillColor(sf::Color::Green); // Rengi.
    upperShape.setPosition({posX, 0.f}); // Ekranın üst tarfına çizmesi için.

    // | Alt boru |
    lowerShape.setSize({pipeWidth, 600.f - (gapY + pipeGap)}); // Genişliği ve yüksekliği.
    lowerShape.setFillColor(sf::Color::Green); // Rengi.
    lowerShape.setPosition({posX, gapY + pipeGap}); // Üst boru ve boşluktan sonra alta çiz.
};

void Pipe::update(float deltaTime){ // Zamana göre hareketleri.
    posX -= speed * deltaTime; // Hız x Zaman formülü ile sol tarafa doğru kaydırması için.
    upperShape.setPosition({posX, upperShape.getPosition().y});
    lowerShape.setPosition({posX, lowerShape.getPosition().y});
};

void Pipe::draw(sf::RenderWindow& window){ // Boruların çizimi.
    window.draw(upperShape);
    window.draw(lowerShape);
}

bool Pipe::isOffScreen() const{
    return (posX + pipeWidth) < 0; // Borunun sağ ucu ekrandan çıkınca boru silinir.
}