#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"
#include "entity.hpp"
#include "projectiles.hpp"

class groundUnit : public Entity{
public:
    groundUnit(b2World *world, int difficulty);
    ~groundUnit();
    b2Vec2 getPosition();
    float32 getDirection();
    int groundUnitStep();
    sf::Sprite &getSprite();
    void startContact(bool ground);
    void shoot(Projectiles *projectile);
    void turn(const int x);
    int getEntityType(){return 2;}

    
private:
    b2Body *body_;
    sf::Sprite *groundUnitSprite;
    int shotInterval;
    int delay;
    int health;
};