#include "options.hpp"
#include "global.hpp"

Options::Options(float width, float height){
    Global t;
    std::string path = t.GetPath();

    if (!font_.loadFromFile(path + std::string("/Images/Xhume.ttf"))) {
        //error
    }

    options_[0].setFont(font_);
    options_[0].setFillColor(sf::Color::White);
    options_[0].setString("Easy");
    options_[0].setPosition(sf::Vector2f(width/2.4f, height / 5 * 2));
    options_[0].setCharacterSize(35);

    options_[1].setFont(font_);
    options_[1].setFillColor(sf::Color::White);
    options_[1].setString("Meduim");
    options_[1].setPosition(sf::Vector2f(width/2.4f, height / 5 * 3));
    options_[1].setCharacterSize(35);

    options_[2].setFont(font_);
    options_[2].setFillColor(sf::Color::White);
    options_[2].setString("Hard");
    options_[2].setPosition(sf::Vector2f(width/2.4f, height / 5 * 4));
    options_[2].setCharacterSize(35);

    back_.setFont(font_);
    back_.setString("OK");
    back_.setPosition(sf::Vector2f(55, height / 4 * 3.5));
    back_.setCharacterSize(45);

    info_.setFont(font_);
    info_.setString("Select difficulty:");
    info_.setPosition(sf::Vector2f(200, height / 5 * 1));
    info_.setCharacterSize(40);

    // current difficulty is easy
    curDif_ = 0;

    HighlightCurDif(curDif_);
}

Options::~Options(){

}

void Options::Draw(sf::RenderWindow& window){
    for (int i = 0; i < 3; ++i) {
        window.draw(options_[i]);
    }
    window.draw(back_);
    window.draw(info_);
}

void Options::ChangeDifficulty(int newDif){
    this->curDif_ = newDif;
    HighlightCurDif(this->curDif_);
}

int Options::GetDifficulty(){
    return this->curDif_;
}

void Options::HighlightCurDif(int current){
    options_[0].setFillColor(sf::Color::White);
    options_[1].setFillColor(sf::Color::White);
    options_[2].setFillColor(sf::Color::White);
    options_[current].setFillColor(sf::Color::Red);
}


void Options::MoveUp(){
    if (curDif_ - 1 >= 0) {
        options_[curDif_].setFillColor(sf::Color::White);
        curDif_--;
        options_[curDif_].setFillColor(sf::Color::Red);
    }
}


void Options::MoveDown(){
    if (curDif_ + 1 < 3) {
        options_[curDif_].setFillColor(sf::Color::White);
        curDif_++;
        options_[curDif_].setFillColor(sf::Color::Red);
    }
}
