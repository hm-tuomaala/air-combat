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

const std::list<sf::Sprite> EnemyAir::getSprites() const{
    std::list<sf::Sprite> sprites;
    for (auto plane : planes_){
        sprites.push_back(plane->getSprite());
    }
    return sprites;
}

void EnemyAir::planeControl(b2Vec2 pPos, float32 pDir){
    for (auto plane : planes_){
        b2Vec2 sep =pPos - plane->getPosition();
        sep.Normalize();
        b2Vec2 dir = b2Rot(plane->getDirection()).GetXAxis();
        if (dir.x > 0){
            if (sep.x > 0){
                if (sep.y > dir.y){
                    plane->pitch(0);
                }
                else {
                    plane->pitch(1);
                }
            }
            else{
                plane->pitch(0);
            }
        }
        else if (dir.x <= 0){
            if (sep.x < 0){
                if (sep.y > dir.y){
                    plane->pitch(1);
                }
                else {
                    plane->pitch(0);
                }
            }
            else{
                plane->pitch(1);
            }
        }
        if ((dir - sep).Length() < 0.2){
            plane->accelerate();
        }
        
    }
}