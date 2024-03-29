#include <SFML/Graphics.hpp>
#include <list>
#include "contactListener.hpp"
#include "Box2D/Box2D.h"


class World{
public:
    World();
    World(const World&) = delete;
    World& operator=(const World&) = delete;
    ~World();
    void setUpMap();
    void worldStep();
    b2World &get2bWorld();
    const sf::RectangleShape& getGround() const;
    const sf::RectangleShape& getWallLeft() const;
    const sf::RectangleShape& getWallRight() const;
    

protected:
    ContactListener newContactListener;
    b2World* newWorld;
    sf::RectangleShape ground;
    sf::RectangleShape wallleft;
    sf::RectangleShape wallright;
    sf::Texture backgroundTexture;
    sf::Sprite spriteBackground;
};