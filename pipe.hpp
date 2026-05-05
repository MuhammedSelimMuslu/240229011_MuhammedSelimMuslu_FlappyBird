#ifndef Pipe_hpp
#define Pipe_hpp // Pipe_hpp etiketini oluşturur.
#include <SFML/Graphics.hpp>

class Pipe{
public:
    Pipe(float xPos,float gapY); // Borunun çıkış yeri ve aradaki boşluğun nerede olduğu.
    void update(float deltatime); // Borunun sola doğru akışı için.
    void draw(sf::RenderWindow& window); // Boruları ekranda gösterir.
    bool isOffScreen() const; // Borular sol taraftan ekrandan çıktı mı? (!!!Bellek Yönetimi)

private:
    sf::RectangleShape upperShape;
    sf::RectangleShape lowerShape;
    // Alt ve üst boruların şeklini girdik.
    float posX; // Borunu yatay koordinatı.
    const float pipeWidth = 60.f; // Boru kalınlığı.
    const float pipeGap = 160.f; // Borular arasındaki boşluk.
    const float speed = 200.f; // Boruların akış hızı.
};
#endif