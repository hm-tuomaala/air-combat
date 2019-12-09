#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <list>
#include "bullet.hpp"

class Projectiles{
public:
    Projectiles(b2World *world);
    void create(b2Vec2 position, float32 direction);
    const std::list<sf::Sprite> getSprites() const;
    void projectileStep();


private:
    b2World *world_;
    std::list<Bullet*> bullets;


};