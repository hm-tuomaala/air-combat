#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Box2D/Box2D.h"
#include "world.hpp"
#include "plane.hpp"

int main(){
    //windowsetup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Air combat");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::View view;

    World *fighterWorld = new World();
    Plane *plane = new Plane(&fighterWorld->get2bWorld());


    while(window.isOpen()){

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        fighterWorld->worldStep();

        plane->planeStep();
        view.setCenter(plane->getSprite().getPosition().x, plane->getSprite().getPosition().y);
        view.setSize(800, -600);
		window.setView(view);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            plane->accelerate();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            plane->pitch(0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            plane->pitch(1);
        }

        //Draw
        window.clear(sf::Color::Blue);
        window.draw(fighterWorld->getGround());
        window.draw(plane->getSprite());
        window.display();
    }

}