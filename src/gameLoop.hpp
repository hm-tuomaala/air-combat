#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Box2D/Box2D.h"
#include "world.hpp"
#include "enemyair.hpp"
#include "menu.hpp"
#include "projectiles.hpp"
#include "player.hpp"
#include "global.hpp"

class gameLoop{
public:
    gameLoop();
    ~gameLoop();
    void startMenu();
    void worldStep();
    void draw();
    void setup();
    void loop();

private:
    sf::RenderWindow window;
    sf::Event event;
    sf::View view;

    Menu *menu;
    World *fighterWorld;
    Player *player;
    EnemyAir *enPlanes;
    Projectiles *bullets;

    bool renderMenu;
    std::string path;
    sf::Font f;

    int hudXPos;
    int hudYPos;

    std::string hp;
    std::string lives;
    sf::Text hpText;
    sf::Text livesText;


};