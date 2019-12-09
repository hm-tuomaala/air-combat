#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"

class Plane{
public:
    Plane(b2World *world);
    ~Plane();
    const b2Vec2 getPosition() const;
    const float32 getDirection() const;
    const sf::Sprite &getSprite() const;
    const int getHealth() const;
    const int planeStep() const;
    void accelerate();
    void pitch(const int x);
    void startContact();
private:
    b2Body *body;
    sf::Sprite *sprite;
    int health;
};
