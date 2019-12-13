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
    ground = sf::RectangleShape(sf::Vector2f(1000,20));
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(-500.0f, -10.0f);

    b2BodyDef bodyDef;
    bodyDef.position.Set(-490.0f, 260.0f);
    b2Body* body = newWorld->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 250.0f);
    body->CreateFixture(&dynamicBox, 0.0f);
    wallleft = sf::RectangleShape(sf::Vector2f(20,500));
    wallleft.setFillColor(sf::Color::Black);
    wallleft.setPosition(-500.0f, 10.0f);

    b2BodyDef bodyDef1;
    bodyDef1.position.Set(490.0f, 260.0f);
    b2Body* body1 = newWorld->CreateBody(&bodyDef1);
    b2PolygonShape dynamicBox1;
    dynamicBox1.SetAsBox(10.0f, 250.0f);
    body1->CreateFixture(&dynamicBox1, 0.0f);
    wallright = sf::RectangleShape(sf::Vector2f(20,500));
    wallright.setFillColor(sf::Color::Black);
    wallright.setPosition(480.0f, 10.0f);

    newContactListener = ContactListener();
    newWorld->SetContactListener(&newContactListener);
}

World::~World(){
    delete newWorld;
}

b2World &World::get2bWorld(){
    return *newWorld;
}

const sf::RectangleShape& World::getGround() const{
    return ground;
}

const sf::RectangleShape& World::getWallLeft() const{
    return wallleft;
}

const sf::RectangleShape& World::getWallRight() const{
    return wallright;
}

void World::worldStep(){
    
    newWorld->Step(1.0f/60.0f, 8, 3);
}