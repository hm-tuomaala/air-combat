#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
class Bullet{
public:
    Bullet(b2World *world, b2Vec2 position, float32 direction);
    ~Bullet();
    int bulletStep();
    void speed(float32 direction);
    b2Vec2 getPosition();
    float32 getDirection();
    sf::Sprite &getSprite();

private:
    b2Body *body;
    sf::Sprite *bullet_sprite;
    int counter;
};
