#ifndef Pipe_hpp
#define Pipe_hpp // Pipe_hpp etiketini oluşturur.
#include <SFML/Graphics.hpp>

class Pipe{
public:

    Pipe(float xPos,float gapY, const sf::Texture& texture); // Borunun çıkış yeri ve aradaki boşluğun nerede olduğu.
    void update(float deltatime); // Borunun sola doğru akışı için.
    void draw(sf::RenderWindow& window); 
    bool isOffScreen() const; // Borular sol taraftan ekrandan çıktı mı? (!!!Bellek Yönetimi)
    bool checkCollision(const sf::Rect<float>& birdBounds) const; // Kuş boruya çarptı mı?
    bool passed = false; // Borunun kuşu geçip geçmediğini anlamak için (skor sayısı).

    sf::Rect<float> getUpperBounds() const {
        return upperShape.getGlobalBounds(); 
        // Borunun konumunu anlamak için üst borunun sınırlarını dışarı aktarır.
    }

private:

    sf::Sprite upperShape;
    sf::Sprite lowerShape;

    float posX; 
    float pipeWidth = 150.f; 
    float pipeGap = 175.f; 
    float speed = 200.f; 
    // Boru değerleri ayarlandı.
};
#endif