#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Entity{
    virtual int getEntityType() = 0;
};