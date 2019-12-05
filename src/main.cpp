#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Box2D/Box2D.h"
#include "world.hpp"
#include "enemyair.hpp"
#include "menu.cpp"

int main(){
    //windowsetup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Air combat");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::View view;

    Menu menu(window.getSize().x, window.getSize().y);

    World *fighterWorld = new World();
    Plane *plane = new Plane(&fighterWorld->get2bWorld());
    EnemyAir *enPlanes = new EnemyAir(&fighterWorld->get2bWorld());
    enPlanes->liftoff();
    enPlanes->liftoff();
    enPlanes->liftoff();

    bool renderMenu = true;

    while(window.isOpen()){

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.MoveUp();
                    break;
                } else if (event.key.code == sf::Keyboard::Down) {
                    menu.MoveDown();
                    break;
                } else if (event.key.code == sf::Keyboard::Return && menu.GetIndex() == 0) {
                    renderMenu = false;
                } else if (event.key.code == sf::Keyboard::Return && menu.GetIndex() == 2) {
                    window.close();
                }
            }
        }

        if (!renderMenu) {
            fighterWorld->worldStep();

            plane->planeStep();
            enPlanes->step();
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
        }

        //Draw
        window.clear(sf::Color::Blue);
        if (!renderMenu) {
            window.draw(fighterWorld->getGround());
            window.draw(plane->getSprite());
            for (auto i : enPlanes->getSprites()){
                window.draw(i);
            }
        } else {
            menu.Draw(window);
        }
        window.display();
    }

}
