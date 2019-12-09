#include "projectiles.hpp"

Projectiles::Projectiles(b2World *world){
    world_ = world;
}

void Projectiles::create(b2Vec2 position, float32 direction ){
    bullets.push_back(new Bullet(world_, position, direction));
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
        Bullet->bulletStep();
    }
}