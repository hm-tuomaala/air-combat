#include "plane.hpp"

Plane::Plane(b2World *world){
    //creation and setup of the physics body of the plane
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 100.0f);
    body = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 5.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.02f;
    body->CreateFixture(&fixtureDef);
    body->SetAngularDamping(2.0f);
    body->SetUserData(this);

    //create plane sprite
    sf::Texture plane_texture;
    //plane_texture.loadFromFile("../Images/fighter.png");
    plane_texture.create(20, 10);
    sprite = new sf::Sprite(plane_texture);
    sprite->setOrigin(10.f, 5.f);
    sprite->setTexture(plane_texture);
    //sprite->setScale(0.01f, 0.01f);
    sprite->setColor(sf::Color::Magenta);
}

Plane::~Plane(){

}

void Plane::planeStep() {
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();

    //adding some force to make plane resist traveling in directions other than forward
    b2Vec2 linVel = body->GetLinearVelocity();
    float32 speed = linVel.Normalize();
    linVel *= 2;
    b2Vec2 lift = (b2Rot(body->GetAngle()).GetXAxis() - linVel);
    lift *= speed;
    body->ApplyForceToCenter(lift, true);

    //update sprite position
    sprite->setPosition(position.x, position.y);
    sprite->setRotation(angle * 180.f / 3.14f);
}

const b2Vec2 Plane::getPosition() const{
    return body->GetPosition();
}

const float32 Plane::getDirection() const{
    return body->GetAngle();
}

const sf::Sprite &Plane::getSprite() const{
    return *sprite;
}

void Plane::accelerate(){
    b2Vec2 dir = b2Rot(body->GetAngle()).GetXAxis();
    dir *= 1000;
    body->ApplyForceToCenter(dir, true);
    //body->ApplyLinearImpulseToCenter(dir, true);
}

void Plane::pitch(const int x){
    if (x==0){
        body->ApplyAngularImpulse(15, true);
    }
    else if (x==1){
        body->ApplyAngularImpulse(-15, true);
    }
}

void Plane::startContact(){
    sprite->setColor(sf::Color::Green);
}