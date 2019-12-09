#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"

class Plane{
public:
    Plane(b2World *world);
    ~Plane();
    const b2Vec2 getPosition() const;
    const float32 getDirection() const;
    const sf::Sprite &getSprite() const;
    void planeStep();
    void accelerate();
    void pitch(const int x);
private:
    b2Body *body;
    sf::Sprite *sprite;
};
