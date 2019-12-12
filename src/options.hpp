#include "SFML/Graphics.hpp"

class Options {
public:
    Options(float width, float height);
    ~Options();

    void Draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    //
    void HighlightCurDif(int current);

    void ChangeDifficulty(int newDif);
    int GetDifficulty();

private:
    sf::Text options_[3];
    sf::Text back_;
    sf::Text info_;
    sf::Font font_;
    int curDif_;
};
