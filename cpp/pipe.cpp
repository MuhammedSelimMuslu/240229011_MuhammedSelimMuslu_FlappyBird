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

bool Pipe::checkCollision(const sf::Rect<float>& birdBounds) const {
    // SFML 3 standartlarinda (position ve size kullanarak) iki kutunun 
    // birbirinin icine girip girmedigini (AABB) matematiksel olarak kontrol ediyoruz.
    
    sf::Rect<float> upperBounds = upperShape.getGlobalBounds();
    sf::Rect<float> lowerBounds = lowerShape.getGlobalBounds();

    // Kus ile ust borunun carpisma hesabi
    bool upperCollide = birdBounds.position.x < upperBounds.position.x + upperBounds.size.x &&
                        birdBounds.position.x + birdBounds.size.x > upperBounds.position.x &&
                        birdBounds.position.y < upperBounds.position.y + upperBounds.size.y &&
                        birdBounds.position.y + birdBounds.size.y > upperBounds.position.y;

    // Kus ile alt borunun carpisma hesabi
    bool lowerCollide = birdBounds.position.x < lowerBounds.position.x + lowerBounds.size.x &&
                        birdBounds.position.x + birdBounds.size.x > lowerBounds.position.x &&
                        birdBounds.position.y < lowerBounds.position.y + lowerBounds.size.y &&
                        birdBounds.position.y + birdBounds.size.y > lowerBounds.position.y;

    // Kus iki borudan birine bile teget gectiyse veya icine girdiyse true doner
    if (upperCollide || lowerCollide) {
        return true;
    }
    return false;
}

   