#include "Box2D/Box2D.h"
#include "plane.hpp"
#include "bullet.hpp"

class ContactListener : public b2ContactListener{
public:
    virtual void BeginContact(b2Contact* contact){
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Entity*>(bodyUserData)->startContact();
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Entity*>(bodyUserData)->startContact();
    }
};