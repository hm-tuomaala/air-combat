#pragma once
#include "SFML/Graphics.hpp"

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    void HighlightIndex(int index);
    int GetIndex();
    sf::Text GetText(int index);

private:
    int selectIndex;
    sf::Font font;
    sf::Text menu[3];
};
