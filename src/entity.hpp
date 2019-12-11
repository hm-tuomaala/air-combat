#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Entity{
public:
    virtual int getEntityType() = 0;
    virtual void startContact(bool ground){}
};