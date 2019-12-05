#include "bullet.hpp"

Bullet::Bullet(b2World *world, b2Vec2 position, float32 direction){
    b2BodyDef blt;
    blt.type = b2_dynamicBody;
    blt.bullet = true;
    blt.position.Set(position.x + 20, position.y + 20);
    b2CircleShape circleShape;
    circleShape.m_p.Set(1.0f, 3.0f);
    circleShape.m_radius = 0.5f;

    body = world->CreateBody(&blt);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 0.1f;
    body->CreateFixture(&fixtureDef);

    sf::Texture bullet_texture;
    bullet_texture.create(8,8);
    
    bullet_sprite = new sf::Sprite(bullet_texture);
    bullet_sprite->setTexture(bullet_texture);
    bullet_sprite->setScale(0.1, 0.1);
    bullet_sprite->setColor(sf::Color::White);
    speed(direction);


}
b2Vec2 Bullet::getPosition() {
    return body->GetPosition();
}

float32 Bullet::getDirection(){
    return body->GetAngle();
}
void Bullet::bulletStep(){
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    bullet_sprite->setPosition(position.x, position.y);
    bullet_sprite->setRotation(angle * 180.f / 3.14f);
}

void Bullet::speed(float32 direction){
    body->ApplyLinearImpulseToCenter((b2Rot(direction*2).GetXAxis()), true);
    body->ApplyLinearImpulseToCenter((b2Rot(direction*2).GetXAxis()), true);
    body->ApplyLinearImpulseToCenter((b2Rot(direction*2).GetXAxis()), true);
}

sf::Sprite &Bullet::getSprite(){
    return *bullet_sprite;
}