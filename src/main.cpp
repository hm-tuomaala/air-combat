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
    sf::Texture texture;
    texture.loadFromFile("Images/fighter.png");
    
    sf::Sprite player(texture);
    player.setTextureRect(sf::IntRect(40,0,40,40));
    player.setOrigin(20,20);

    World *fighterWorld = new World();

    while(window.isOpen()){

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        fighterWorld->worldStep();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){}

        //Draw
        window.clear(sf::Color::White);
        window.draw(fighterWorld->getGround());
        window.draw(player);
        window.display();
    }

}