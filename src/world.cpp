#include "world.hpp"

World::World(){
    b2Vec2 gravity(0.0f, -9.81f);
    newWorld = new b2World(gravity);
    b2BodyDef groundBodyDefine;
    groundBodyDefine.position.Set(0.0f, -15.0f);
    b2Body* groundBody = newWorld->CreateBody(&groundBodyDefine);
    b2PolygonShape groundAsBox;
    groundAsBox.SetAsBox(400.0f, 20.0f);
    groundBody->CreateFixture(&groundAsBox, 0.0f);

    ground  = new sf::RectangleShape(sf::Vector2f(2000,10));
    ground->setFillColor(sf::Color::Black);
    ground->setPosition(-1000.f, -30.0f);

}

b2World &World::get2bWorld(){
    return *newWorld;
}

sf::RectangleShape World::getGround(){
    return *ground;
}

void World::worldStep(){
    
    newWorld->Step(1.0f/60.0f, 8, 3);
}