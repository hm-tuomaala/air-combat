#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <list>
#include "bullet.hpp"

class Projectiles{
public:
    Projectiles(b2World *world);
    ~Projectiles();
    void create(b2Vec2 position, float32 direction);
    const std::list<sf::Sprite> getSprites() const;
    void projectileStep();
    void remove();
    

private:
    b2World *world_;
    std::list<Bullet*> bullets;
    std::list<Bullet*> toRemove_;
};