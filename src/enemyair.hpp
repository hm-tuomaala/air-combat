#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <iostream>

#include "Box2D/Box2D.h"
#include "plane.hpp"

class EnemyAir{
/*Stores and controls enemy air units*/
public:
    EnemyAir(b2World *world, Projectiles *projectiles);
    void liftoff(sf::Texture& texture);
    void planeControl(b2Vec2 pPos, float32 pDir);
    void step();
    const std::list<sf::Sprite> getSprites() const;
    const int removal();

private:
    std::list<Plane*> planes_;
    std::list<Plane*> planesToRemove_;
    b2World *world_;
    Projectiles *projectiles_;
};
