#include "player.hpp"

Player::Player(b2World *world)
    : world_(world) {
    plane_ = new Plane(world_);
}

Player::~Player(){

}

void Player::step(){
    plane_->planeStep();
}

void Player::planePitch(const int x){
    plane_->pitch(x);
}

void Player::planeAccelerate(){
    plane_->accelerate();
}

void Player::respawn(){

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