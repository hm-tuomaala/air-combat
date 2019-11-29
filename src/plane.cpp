#include "plane.hpp"

Plane::Plane(b2World *world){
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 100.0f);
    body = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(3.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.1f;
    body->CreateFixture(&fixtureDef);
    body->SetAngularDamping(2.0f);

    sf::Texture plane_texture;
    //plane_texture.loadFromFile("Images/fighter.png");
    plane_texture.create(200, 200);
    sprite = new sf::Sprite(plane_texture);
    sprite->setOrigin(50.f, 50.f);
    sprite->setTexture(plane_texture);
    sprite->setScale(0.1f, 0.1f);
    sprite->setColor(sf::Color::Magenta);
}

void Plane::planeStep() {
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    sprite->setPosition(position.x, position.y);
    sprite->setRotation(angle * 180.f / 3.14f);
}

b2Vec2 Plane::getPosition() {
    return body->GetPosition();
}

float32 Plane::getDirection(){
    return body->GetAngle();
}

sf::Sprite &Plane::getSprite(){
    return *sprite;
}

void Plane::accelerate(){
    body->ApplyLinearImpulseToCenter(b2Rot(body->GetAngle()).GetXAxis(), true);
}

void Plane::pitch(const int x){
    if (x==0){
        body->ApplyAngularImpulse(0.50, true);
    }
    else if (x==1){
        body->ApplyAngularImpulse(-0.50, true);
    }
}