#include "plane.hpp"

int CEILING = 400;

Plane::Plane(b2World *world, int difficulty){
    //difficulty 5 is player and affects the spawn point
    health_ = difficulty * 20;
    shotInterval_ = 100/difficulty;
    shotDelay_ = 0;

    //creation and setup of the physics body of the plane
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    if (difficulty == 5){
        bodyDef.position.Set(-300.0f, 10.0f);
        ammo_ = 50;
    }
    else {
        bodyDef.position.Set(300.0f, 10.0f);
        ammo_ = 1000;
    }
    body_ = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 5.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.02f;
    body_->CreateFixture(&fixtureDef);
    body_->SetAngularDamping(2.0f);
    body_->SetUserData(this);
    if (difficulty != 5){
        body_->SetTransform(body_->GetPosition(), 3.14f);
    }

    //create plane sprite
    sf::Texture plane_texture;
    //plane_texture.loadFromFile("../Images/fighter.png");
    plane_texture.create(20, 10);
    sprite_ = new sf::Sprite(plane_texture);
    sprite_->setOrigin(10.f, 5.f);
    sprite_->setTexture(plane_texture);
    //sprite->setScale(0.01f, 0.01f);
    sprite_->setColor(sf::Color::Magenta);
}

Plane::~Plane(){
    body_->GetWorld()->DestroyBody(body_);
}

const int Plane::planeStep(){
    b2Vec2 position = body_->GetPosition();
    float32 angle = body_->GetAngle();
    shotDelay_ ++;

    //adding some force to make plane resist traveling in directions other than forward
    b2Vec2 linVel = body_->GetLinearVelocity();
    b2Vec2 lift = b2Vec2(0, 1 * std::abs(linVel.x * 0.5));
    float32 speed = linVel.Normalize();
    linVel *= 2;
    b2Vec2 steering = (b2Rot(body_->GetAngle()).GetXAxis() - linVel);
    steering *= speed*2;
    body_->ApplyForceToCenter(lift + steering, true);

    // a soft ceiling limit
    if (position.y > CEILING)
        body_->ApplyForceToCenter(b2Vec2(0, -100), true);

    //update sprite position
    sprite_->setPosition(position.x, position.y);
    sprite_->setRotation(angle * 180.f / 3.14f);

    //returns the health of the plane
    return health_;
}

const b2Vec2 Plane::getPosition() const{
    return body_->GetPosition();
}

const float32 Plane::getDirection() const{
    return body_->GetAngle();
}

const sf::Sprite &Plane::getSprite() const{
    return *sprite_;
}

const int Plane::getHealth() const{
    return health_;
}

void Plane::accelerate(){
    b2Vec2 dir = b2Rot(body_->GetAngle()).GetXAxis();
    dir *= 200;
    if(std::abs(body_->GetLinearVelocity().x) < 80 && (body_->GetPosition().y < CEILING || dir.y < 0))
        body_->ApplyForceToCenter(dir, true);
    //body->ApplyLinearImpulseToCenter(dir, true);
}

void Plane::pitch(const int x){
    if (x==0){
        body_->ApplyAngularImpulse(15, true);
    }
    else if (x==1){
        body_->ApplyAngularImpulse(-15, true);
    }
}

void Plane::startContact(bool ground){
    b2Vec2 linVel = body_->GetLinearVelocity();
    if(!ground || std::abs(linVel.y) > 50)
        health_ -= 10;
    sprite_->setColor(sf::Color::Green);
}

const int Plane::shoot(Projectiles *projectiles){
    if (shotDelay_ >= shotInterval_ && ammo_ >= 0){ 
        projectiles->create(getPosition(), getDirection());
        shotDelay_ = 0;
        ammo_--;
    }
    return ammo_;
}