#include "SFML/Graphics.hpp"

class Win {
public:
    Win(float width, float height);
    ~Win();
    void Draw(sf::RenderWindow& window);
private:
    sf::Text victory_;
    sf::Font font_;
};
