#include "player.hpp"

Player::Player(b2World *world, sf::Texture& texture)
    : world_(world), texture_(texture){
    plane_ = new Plane(world_, 5, texture_);
    lives_ = 12;
}

Player::~Player(){

}

void Player::step(){
    if (plane_->planeStep() <= 0)
        respawn();
}

void Player::planePitch(const int x){
    plane_->pitch(x);
}

void Player::planeAccelerate(){
    plane_->accelerate();
}

const int Player::planeShoot(Projectiles *projectiles){
    int ammo = plane_->shoot(projectiles);
    return ammo;
}

void Player::respawn(){
    delete plane_;
    plane_ = new Plane(world_, 5, texture_);
    lives_--;
}

const sf::Sprite Player::getSprite() const{
    return plane_->getSprite();
}

const b2Vec2 Player::getPosition() const{
    return plane_->getPosition();
}

const float32 Player::getDirection() const{
    return plane_->getDirection();
}

const int Player::getHp() const{
    return plane_->getHealth();
}

const int Player::getLives() const{
    return lives_;
}

const int Player::getAmmo() const{
    return plane_->getAmmo();
}
