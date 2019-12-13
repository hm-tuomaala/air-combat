#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>  
#include <iostream>
#include "Box2D/Box2D.h"
#include "entity.hpp"
#include "projectiles.hpp"

class groundUnit : public Entity{
public:
    groundUnit(b2World *world, sf::Texture& texture);
    ~groundUnit();
    b2Vec2 getPosition();
    float32 getDirection();
    int groundUnitStep();
    sf::Sprite &getSprite();
    void startContact(bool ground);
    void shoot(Projectiles *projectile, float32 playerDirection, b2Vec2 playerPosition);
    void turn(const int x);
    int getEntityType(){return 2;}

    
private:
    b2Body *body_;
    sf::Sprite groundUnitSprite;
    int shotInterval;
    int delay;
    int health;
};