#include "pipe.hpp"

Pipe::Pipe(float xPos, float gapY, const sf::Texture& texture) 
: upperShape(texture), lowerShape(texture), posX(xPos){ // Boru oluştuğunda olacak özellikleri.

    // 900 piksel olan resmi 60 piksele düşürmek için X ölçek katsayısı ayarladık.
    float scaleX = pipeWidth / 900.f;

    // ÜST BORU (döndürülmüş şekilde)
    float topScaleY = gapY / 712.f; 
    upperShape.setScale({scaleX, -topScaleY}); // Y ekseni (-) olduğu için resim ters dönecek.
    upperShape.setPosition({posX, gapY}); 

    // ALT BORU 
    float bottomY = gapY + pipeGap;
    float bottomHeight = 600.f - bottomY;
    float bottomScaleY = bottomHeight / 712.f;
    lowerShape.setScale({scaleX, bottomScaleY}); // Borunun ölçeklendirmesi.
    lowerShape.setPosition({posX, bottomY});
    
    passed = false;
}

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

    sf::Rect<float> upperBounds = upperShape.getGlobalBounds();
    sf::Rect<float> lowerBounds = lowerShape.getGlobalBounds();

    // Kuş ile üst borunun çarpışma hesabını yapacağız.
    bool upperCollide = birdBounds.position.x < upperBounds.position.x + upperBounds.size.x &&
                        birdBounds.position.x + birdBounds.size.x > upperBounds.position.x &&
                        birdBounds.position.y < upperBounds.position.y + upperBounds.size.y &&
                        birdBounds.position.y + birdBounds.size.y > upperBounds.position.y;

    // Kuş ile alt borunun çarpışma hesabını yapacağız.
    bool lowerCollide = birdBounds.position.x < lowerBounds.position.x + lowerBounds.size.x &&
                        birdBounds.position.x + birdBounds.size.x > lowerBounds.position.x &&
                        birdBounds.position.y < lowerBounds.position.y + lowerBounds.size.y &&
                        birdBounds.position.y + birdBounds.size.y > lowerBounds.position.y;

    if(birdBounds.findIntersection(upperShape.getGlobalBounds())) {
        return true; // Kuş üst boruya çarptı mı?
    }

    if (birdBounds.findIntersection(lowerShape.getGlobalBounds())) {
        return true; // Kuş alt boruya çarptı mı?
    }

    return false; // Hiçbirine çarpmadıysa güvende demektir.

    // Kuş iki borudan birine bile teğet geçtiyse veya içine girdiyse true döner.
    if (upperCollide || lowerCollide) {
        return true;
    }
    return false;
}

   