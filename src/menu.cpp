#include "menu.hpp"
#include <iostream>
#include "global.hpp"

Menu::Menu(float width, float height){

    Global t;
    std::string path = t.GetPath();

    if (!font.loadFromFile(path + std::string("/Images/Xhume.ttf"))) {
        //error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2.4f, height / 4 * 1));
    menu[0].setCharacterSize(45);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2.4f, height / 4 * 2));
    menu[1].setCharacterSize(45);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quit");
    menu[2].setPosition(sf::Vector2f(width/2.4f, height / 4 * 3));
    menu[2].setCharacterSize(45);

    selectIndex = 0;
}

Menu::~Menu(){

}


void Menu::Draw(sf::RenderWindow &window){
    for (int i = 0; i < 3; ++i) {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp(){
    if (selectIndex - 1 >= 0) {
        menu[selectIndex].setFillColor(sf::Color::White);
        selectIndex--;
        menu[selectIndex].setFillColor(sf::Color::Red);
    }
}


void Menu::MoveDown(){
    if (selectIndex + 1 < 3) {
        menu[selectIndex].setFillColor(sf::Color::White);
        selectIndex++;
        menu[selectIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::HighlightIndex(int index){
    menu[0].setFillColor(sf::Color::White);
    menu[1].setFillColor(sf::Color::White);
    menu[2].setFillColor(sf::Color::White);
    menu[index].setFillColor(sf::Color::Red);
    selectIndex = index;
}

sf::Text Menu::GetText(int index) {
    return this->menu[index];
}

int Menu::GetIndex(){
    return selectIndex;
}
