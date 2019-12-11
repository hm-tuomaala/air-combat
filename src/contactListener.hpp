#include "Box2D/Box2D.h"
#include "plane.hpp"
#include "bullet.hpp"

class ContactListener : public b2ContactListener{
public:
    virtual void BeginContact(b2Contact* contact){
        b2Body *bodyA = contact->GetFixtureA()->GetBody();
        b2Body *bodyB = contact->GetFixtureB()->GetBody();
        void* bodyAUserData = bodyA->GetUserData();
        void* bodyBUserData = bodyB->GetUserData();
        bool ground = false;
        if ((bodyA->GetType() == b2_staticBody) || (bodyB->GetType()) == b2_staticBody){
            ground = true;
        }
        if (bodyAUserData)
            static_cast<Entity*>(bodyAUserData)->startContact(ground);
        if (bodyBUserData)
            static_cast<Entity*>(bodyBUserData)->startContact(ground);
    }
};