#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"
#include "groundUnit.hpp"
#include "plane.hpp"

class enemyGround{
/*Store and control enemy ground units*/
public:
    enemyGround(b2World *world, Projectiles *projectile, sf::Texture& texture);
    ~enemyGround();
    void create(sf::Texture& texture);
    void step();
    const int toRemove();
    const std::list<sf::Sprite> getSprites() const;
    void shotDirection(float32 playerDirection, b2Vec2 playerPosition);


private:
    std::list<groundUnit*> groundUnit_;
    std::list<groundUnit*> groundUnitToRemove_;
    sf::Texture texture_;
    b2World *world_;
    Projectiles *projectiles_;
};