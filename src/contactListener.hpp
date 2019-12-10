#include "Box2D/Box2D.h"
#include "plane.hpp"
#include "bullet.hpp"

class ContactListener : public b2ContactListener{
public:
    virtual void BeginContact(b2Contact* contact){
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Plane*>(bodyUserData)->startContact();
        if(bodyUserData)
            static_cast<Bullet*>(bodyUserData)->contact();
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Plane*>(bodyUserData)->startContact();
        if (bodyUserData)
            static_cast<Bullet*>(bodyUserData)->contact();
    }
};