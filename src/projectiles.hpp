#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <list>
#include "bullet.hpp"

class Projectiles{
public:
    Projectiles(b2World *world);
    void create(b2Vec2 position, float32 direction);
    std::list<sf::Sprite> getSprites();
    void projectileStep();


private:
    b2World *world_;
    std::list<Bullet*> bullets;


};