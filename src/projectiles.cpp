#include "projectiles.hpp"

Projectiles::Projectiles(b2World *world){
    world_ = world;
}

Projectiles::~Projectiles(){
    for (auto it : bullets){
        delete it;
    }
}

void Projectiles::create(b2Vec2 position, float32 direction ){
    bullets.push_back(new Bullet(world_, position, direction));
}

void Projectiles::remove(){
    for(auto i : toRemove_){
        Bullet* deadbullet = i;
        delete deadbullet;

        std::list<Bullet*>::iterator it = std::find(bullets.begin(), bullets.end(), deadbullet);
        if(it != bullets.end()){
            bullets.remove(i);
        }
    }
    toRemove_.clear();
}

const std::list<sf::Sprite> Projectiles::getSprites() const{
    std::list<sf::Sprite> bullet_sprites;
    for (auto Bullet : bullets){
        bullet_sprites.push_back(Bullet->getSprite());
    }
    return bullet_sprites;
}

void Projectiles::projectileStep(){
    for(auto Bullet : bullets){
        if(Bullet->bulletStep() > 180 || Bullet->getContact() == true){
            toRemove_.push_back(Bullet);
        }
    }
}