#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "Box2D/Box2D.h"
#include "plane.hpp"

class Player{
// class to store and control player specific stats and plane oblject
public:
    Player(b2World *world, sf::Texture& texture);
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    ~Player();
    void respawn();
    void planePitch(const int x);
    void planeAccelerate();
    const int planeShoot(Projectiles *projectiles);
    void step();
    const sf::Sprite getSprite() const;
    const b2Vec2 getPosition() const;
    const float32 getDirection() const;
    const int getHp() const;
    const int getLives() const;
    const int getAmmo() const;

private:
    int lives_;
    Plane *plane_;
    b2World *world_;
    sf::Texture& texture_;
};
