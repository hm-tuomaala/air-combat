#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"

class Plane{
public:
    Plane(b2World *world);
    b2Vec2 getPosition();
    float32 getDirection();
    sf::Sprite &getSprite();
    void planeStep();
    void accelerate();
    void pitch(const int x);
private:
    b2Body *body;
    sf::Sprite *sprite;
};
