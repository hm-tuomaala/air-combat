#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Entity{
/*A parent class for all moving entities in the game for the sole purpose of handling collisions*/
public:
    virtual int getEntityType() = 0;
    virtual void startContact(bool ground){}
};