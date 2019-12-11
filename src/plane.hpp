#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"
#include "entity.hpp"
#include "projectiles.hpp"

class Plane : public Entity{
public:
    Plane(b2World *world);
    ~Plane();
    const b2Vec2 getPosition() const;
    const float32 getDirection() const;
    const sf::Sprite &getSprite() const;
    const int getHealth() const;
    const int planeStep();
    void accelerate();
    void pitch(const int x);
    void startContact();
    int getEntityType() {return 1;}
    void shoot(Projectiles *projectiles);
private:
    b2Body *body_;
    sf::Sprite *sprite_;
    int health_;
    int shotDelay_;
};
