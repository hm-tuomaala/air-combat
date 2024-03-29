#include "bullet.hpp"

Bullet::Bullet(b2World *world, b2Vec2 position, float32 direction){
    //creation of bullet
    b2BodyDef blt;
    blt.type = b2_dynamicBody;
    blt.bullet = true;
    b2Vec2 dir = b2Rot(direction).GetXAxis();
    blt.position.Set(position.x + 15*dir.x, position.y + 15*dir.y);
    b2CircleShape circleShape;
    circleShape.m_p.Set(1.0f, 3.0f);
    circleShape.m_radius = 0.5f;

    //added to world and given shape
    body = world->CreateBody(&blt);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 0.01f;
    body->CreateFixture(&fixtureDef);
    body->SetUserData(this);

    sf::Texture bullet_texture;
    bullet_texture.create(20,20);

    //creation of bullet sprite
    bullet_sprite = new sf::Sprite(bullet_texture);
    bullet_sprite->setTexture(bullet_texture);
    bullet_sprite->setScale(0.1, 0.1);
    bullet_sprite->setColor(sf::Color::White);
    speed(direction);


}

Bullet::~Bullet(){
    body->GetWorld()->DestroyBody(body);
    delete bullet_sprite;
}
b2Vec2 Bullet::getPosition() {
    return body->GetPosition();
}

float32 Bullet::getDirection(){
    return body->GetAngle();
}
int Bullet::bulletStep(){
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    bullet_sprite->setPosition(position.x, position.y);
    bullet_sprite->setRotation(angle * 180.f / 3.14f);
    //counter for projectile timer
    counter++;
    return counter;
}

void Bullet::speed(float32 direction){
    b2Vec2 new_dir = b2Rot(direction).GetXAxis();
    new_dir*=10000;
    body->ApplyLinearImpulseToCenter(new_dir, true);

}

sf::Sprite &Bullet::getSprite(){
    return *bullet_sprite;
}

void Bullet::startContact(bool ground){
    bulletContact = true;
}

bool Bullet::getContact(){
    return bulletContact;
}