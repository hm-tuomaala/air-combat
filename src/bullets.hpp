#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <list>

class Bullet{
public:
    Bullet(b2World *world);
    void bulletStep();
    void speed();

private:
    b2Body *body;
    sf::Sprite *bullet_sprite;
};