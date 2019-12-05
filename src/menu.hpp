#pragma once
#include "SFML/Graphics.hpp"

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetIndex();

private:
    int selectIndex;
    sf::Font font;
    sf::Text menu[3];
};
