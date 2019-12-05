#include "enemyair.hpp"

EnemyAir::EnemyAir(b2World *world)
    : world_(world){
}

void EnemyAir::liftoff(){
    planes_.push_back(new Plane(world_));
}

void EnemyAir::step(){
    for (auto plane : planes_){
        plane->planeStep();
    }
}

std::list<sf::Sprite> EnemyAir::getSprites(){
    std::list<sf::Sprite> sprites;
    for (auto plane : planes_){
        sprites.push_back(plane->getSprite());
    }
    return sprites;
}

void EnemyAir::planeControl(){}
