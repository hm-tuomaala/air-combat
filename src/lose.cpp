#include "global.hpp"
#include "lose.hpp"

Lose::Lose(float width, float height){
    Global g;
    std::string path = g.GetPath();

    if (!font_.loadFromFile(path + std::string("/Images/Xhume.ttf"))) {
        //error
    }

    lost_.setFont(font_);
    lost_.setFillColor(sf::Color::Red);
    lost_.setString("YOU LOST");
    lost_.setPosition(sf::Vector2f(width/4.8, height/2.5f));
    lost_.setCharacterSize(100);

    info_.setFont(font_);
    info_.setFillColor(sf::Color::White);
    info_.setString("Press ENTER to continue...");
    info_.setPosition(sf::Vector2f(width/4.3f, height/1.2f));
    info_.setCharacterSize(30);
}

Lose::~Lose(){

}

void Lose::Draw(sf::RenderWindow& window){
    window.draw(lost_);
    window.draw(info_);
}
