#pragma once

#include "Enemy.h"
#include <iostream>


Enemy::Enemy(EnemyType type) : Actor(1, type == EnemyType::Soldier ? "assets/textures/enemy_soldier.png" : "")
{
	velocity.x = 50.f;
	velocity.y = 0.f;
}

void Enemy::shoot(std::shared_ptr<Bullet> bullet)
{
	sf::FloatRect bounds = sprite.getGlobalBounds();
	sf::Vector2f barell(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height + 5.0f);
	bullet->fireDown(barell);
}


