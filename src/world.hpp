#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <list>

class World{
public:
    World();
    b2World &get2bWorld();
    void setUpMap();
    void worldStep();
    sf::RectangleShape getGround();

protected:
    b2World* newWorld;
    sf::RectangleShape *ground;
};

