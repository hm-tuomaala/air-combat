#include <SFML/Graphics.hpp>
#include <list>

#include "Box2D/Box2D.h"
#include "plane.hpp"

class EnemyAir{
public:
    EnemyAir(b2World *world);
    void liftoff();
    void planeControl();
    void step();
    std::list<sf::Sprite> getSprites();

private:
    std::list<Plane*> planes_;
    b2World *world_;
};
