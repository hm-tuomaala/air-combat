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
#include "options.hpp"
#include "enemyGround.hpp"
#include "win.hpp"
#include "lose.hpp"

class gameLoop{
public:
    gameLoop();
    ~gameLoop();
    void startMenu();
    void worldStep();
    void draw();
    void setup();
    void endScreen();
    int enemySpawn();
    void loop();
    void difficultySpawns();


private:
    sf::RenderWindow window;
    sf::Event event;
    sf::View view;

    Menu *menu;
    Options *options;
    World *fighterWorld;
    Player *player;
    EnemyAir *enPlanes;
    Projectiles *bullets;
    enemyGround *enGround;
    Win *win;
    Lose *lose;

    bool difficultySetup;

    bool renderMenu = true;
    bool renderOptions = false;
    bool renderWin = false;
    bool renderLose = false;
    std::string path;
    sf::Font f;

    int hudXPos = 370;
    int hudYPos = -280;


    std::string hp;
    std::string lives;
    std::string ammos;
    sf::Text hpText;
    sf::Text livesText;
    sf::Text ammosText;

    sf::Texture planeTexture;
    sf::Texture enemyTexture;
    sf::Texture backgroundTexture;
    sf::Sprite spriteBackground;
    

    int ending = 0;
    int enemyAirToSpawn = 0;
    int enemyGroundToSpawn = 0;
    int spawnTimer = 120;
    bool allSpawned = false;
};
