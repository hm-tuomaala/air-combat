#include <SFML/Graphics.hpp>
#include <list>
#include "contactListener.hpp"
#include "Box2D/Box2D.h"

class World{
public:
    World();
    ~World();
    void setUpMap();
    void worldStep();
    b2World &get2bWorld();
    const sf::RectangleShape getGround() const;

protected:
    b2World* newWorld;
    sf::RectangleShape *ground;
};