#include <iostream>
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <stdio.h>
#include "world.hpp"

int main(){
    //windowsetup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Air combat");
    window.setFramerateLimit(60);
    sf::Event event;
    /*sf::Texture texture;
    texture.loadFromFile("Images/fighter_for_cpp.png");
    
    sf::Sprite(texture);
    */

    World *fighterWorld = new World();

    while(window.isOpen()){

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        fighterWorld->worldStep();
        window.clear(sf::Color::White);
        window.draw(fighterWorld->getGround());
        window.display();
    }

}