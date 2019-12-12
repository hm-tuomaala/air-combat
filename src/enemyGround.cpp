#include "enemyGround.hpp"

enemyGround::enemyGround(b2World *world, Projectiles *projectile, sf::Texture& texture):
world_(world), projectiles_(projectile), texture_(texture){}

void enemyGround::step(){
    for(auto i : groundUnit_){
        if(i->groundUnitStep() <= 0){
            groundUnitToRemove_.push_back(i);
        }
    }
}
enemyGround::~enemyGround(){
    for (auto it : groundUnit_){
        delete it;
    }
}

void enemyGround::create(sf::Texture& texture){
    groundUnit_.push_back(new groundUnit(world_, texture_));
}

const int enemyGround::toRemove(){
    for(auto i = groundUnitToRemove_.begin(); i != groundUnitToRemove_.end(); i++){
        groundUnit* deadUnit = *i;
        delete deadUnit;

        std::list<groundUnit*>::iterator it = std::find(groundUnit_.begin(), groundUnit_.end(), deadUnit);
        if(it != groundUnit_.end()){
            groundUnit_.erase(it);
        }
    }
    groundUnitToRemove_.clear();
    return groundUnit_.size();
}

const std::list<sf::Sprite> enemyGround::getSprites() const{
    std::list<sf::Sprite> sprites;
    for (auto unit : groundUnit_){
        sprites.push_back(unit->getSprite());
    }
    return sprites;
}

void enemyGround::shotDirection(float32 playerDirection, b2Vec2 playerPosition){
    for(auto enemy : groundUnit_){
        enemy->shoot(projectiles_, playerDirection, playerPosition);
    }
}