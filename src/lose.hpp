#include "SFML/Graphics.hpp"

class Lose {
public:
    Lose(float width, float height);
    ~Lose();
    void Draw(sf::RenderWindow& window);
private:
    sf::Text lost_;
    sf::Text info_;
    sf::Font font_;
};
