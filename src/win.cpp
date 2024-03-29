#include "win.hpp"
#include "global.hpp"

Win::Win(float width, float height){
    Global g;
    std::string path = g.GetPath();

    if (!font_.loadFromFile(path + std::string("/Images/Xhume.ttf"))) {
        //error
    }

    victory_.setFont(font_);
    victory_.setFillColor(sf::Color::Green);
    victory_.setString("VICTORY");
    victory_.setPosition(sf::Vector2f(width/4, height/2.5f));
    victory_.setCharacterSize(100);

    info_.setFont(font_);
    info_.setFillColor(sf::Color::White);
    info_.setString("Press ENTER to continue...");
    info_.setPosition(sf::Vector2f(width/4.3f, height/1.2f));
    info_.setCharacterSize(30);
}

Win::~Win(){
    
}

void Win::Draw(sf::RenderWindow& window){
    window.draw(victory_);
    window.draw(info_);
}
