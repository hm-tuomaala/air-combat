#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

#include "Box2D/Box2D.h"
#include "plane.hpp"

class Player{
// class to store and control player specific stats
public:
    Player(b2World *world);
    ~Player();
    void respawn();
    void planePitch(const int x);
    void planeAccelerate();
    void step();
    const sf::Sprite getSprite() const;
    const b2Vec2 getPosition() const;
    const float32 getDirection() const;
    const int getHp() const;
    const int getLives() const;

private:
    int lives_;
    Plane *plane_;
    b2World *world_;
};
