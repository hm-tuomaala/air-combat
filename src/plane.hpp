#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Plane{
public:
    Plane(world *world);
    b2Vec2 getPosition();
    sf::Sprite &getSprite();
}