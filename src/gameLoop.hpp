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
// #include "lose.hpp"

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

    bool difficultySetup;

    bool renderMenu;
    bool renderOptions;
    bool renderWin;
    bool renderLose;
    std::string path;
    sf::Font f;

    int hudXPos;
    int hudYPos;


    std::string hp;
    std::string lives;
    std::string ammos;
    sf::Text hpText;
    sf::Text livesText;
    sf::Text ammosText;

    sf::Texture planeTexture;
    sf::Texture enemyTexture;

    int ending;
    int enemyAirToSpawn;
    int enemyGroundToSpawn;
    int spawnTimer;
    bool allSpawned;
};
