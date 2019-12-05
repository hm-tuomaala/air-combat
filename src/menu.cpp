#include "menu.hpp"
#include <iostream>
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

Menu::Menu(float width, float height){

    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){
        //err
    }

    std::cout << cCurrentPath << std::endl;

    if (!font.loadFromFile(cCurrentPath + std::string("/Image/arial.ttf"))) {
        //error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height / 4 * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2, height / 4 * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quit");
    menu[2].setPosition(sf::Vector2f(width/2, height / 4 * 3));

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

int Menu::GetIndex(){
    return selectIndex;
}
