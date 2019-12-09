#include "player.hpp"

Player::Player(b2World *world)
    : world_(world) {
    plane_ = new Plane(world_);
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

void Player::respawn(){
    delete plane_;
    plane_ = new Plane(world_);
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