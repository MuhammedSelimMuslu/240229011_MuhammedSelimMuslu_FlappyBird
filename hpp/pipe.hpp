#ifndef Pipe_hpp
#define Pipe_hpp // Pipe_hpp etiketini oluşturur.
#include <SFML/Graphics.hpp>

class Pipe{
public:

    Pipe(float xPos,float gapY); // Borunun çıkış yeri ve aradaki boşluğun nerede olduğu.
    void update(float deltatime); // Borunun sola doğru akışı için.
    void draw(sf::RenderWindow& window); // Boruları ekranda gösterir.
    bool isOffScreen() const; // Borular sol taraftan ekrandan çıktı mı? (!!!Bellek Yönetimi)
    bool checkCollision(const sf::Rect<float>& birdBounds) const; // Kuş boruya çarptı mı?
    bool passed = false; // Borunun kuşu geçip geçmediğini anlamak için (skor sayısı).

    sf::Rect<float> getUpperBounds() const {
        return upperShape.getGlobalBounds();
    }

private:

    sf::RectangleShape upperShape;
    sf::RectangleShape lowerShape;
    // Alt ve üst boruların şeklini girdik.

    float posX; // Borunu yatay koordinatı.
    float pipeWidth = 60.f; // Boru kalınlığı.
    float pipeGap = 160.f; // Borular arasındaki boşluk.
    float speed = 200.f; // Boruların akış hızı.
};
#endif