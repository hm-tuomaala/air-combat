#include "world.hpp"

World::World(){
    b2Vec2 gravity(0.0f, -9.81f);
    newWorld = new b2World(gravity);
    b2BodyDef groundBodyDefine;
    groundBodyDefine.position.Set(0.0f, 0.0f);
    b2Body* groundBody = newWorld->CreateBody(&groundBodyDefine);
    b2PolygonShape groundAsBox;
    groundAsBox.SetAsBox(500.0f, 10.0f);
    groundBody->CreateFixture(&groundAsBox, 0.0f);
    newWorld->SetContactListener( new ContactListener);

    ground = new sf::RectangleShape(sf::Vector2f(1000,20));
    ground->setFillColor(sf::Color::Black);
    ground->setPosition(-500.0f, -10.0f);
}

World::~World(){
    delete newWorld;
}

b2World &World::get2bWorld(){
    return *newWorld;
}

const sf::RectangleShape World::getGround() const{
    return *ground;
}

void World::worldStep(){
    
    newWorld->Step(1.0f/60.0f, 8, 3);
}