#include "groundUnit.hpp"

groundUnit::groundUnit(b2World *world, int difficulty, sf::Texture& texture){
    //attributes based on difficulty chosen
    health = 20;
    shotInterval = 60/difficulty;
    delay = 0;
    float xcoord = rand()%500 +(-250);
    //creation of body, setup of body physics
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(xcoord, 15.0f);
    bodyDef.angle = 180;

    body_ = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 5.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.02f;
    body_->CreateFixture(&fixtureDef);
    body_->SetUserData(this);


    //creation of sprite
    //sf::Texture groundEnemyTexture;
    //groundEnemyTexture.create(20, 10);
    groundUnitSprite = new sf::Sprite(texture);
    groundUnitSprite->setOrigin(10.0f, 5.0f);
    groundUnitSprite->setScale(2.0f/15.0f, 2.0f/15.0f);
    /*groundUnitSprite->setTexture(groundEnemyTexture);
    groundUnitSprite->setColor(sf::Color::Red);*/

}

groundUnit::~groundUnit(){
    body_->GetWorld()->DestroyBody(body_);
}

b2Vec2 groundUnit::getPosition() {
    return body_->GetPosition();
}

float32 groundUnit::getDirection(){
    return body_->GetAngle();
}
int groundUnit::groundUnitStep(){
    b2Vec2 position = body_->GetPosition();
    float32 angle = body_->GetAngle();
    delay++;
    //update sprite position
    groundUnitSprite->setPosition(position.x, position.y);
    groundUnitSprite->setRotation(angle * 180.f / 3.14f);
    return health;
}

sf::Sprite &groundUnit::getSprite(){
    return *groundUnitSprite;
}

void groundUnit::turn(const int x){
    if(x == 0){
        body_->ApplyAngularImpulse(40, true);
    }
    else if(x == 1){
        body_->ApplyAngularImpulse(-40, true);
    }
}

void groundUnit::shoot(Projectiles *projectile){
    if(delay >= 7){
        projectile->create(b2Vec2(getPosition().x, getPosition().y+100), getDirection());
        delay = 0;
    }
}

void groundUnit::startContact(bool ground){
    b2Vec2 linVel = body_->GetLinearVelocity();
    if(!ground || std::abs(linVel.y) > 50)
        health -= 10;
}
