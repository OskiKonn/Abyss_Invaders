#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.h"

class Enemy : public Actor
{
public:

	enum class EnemyType {
		Soldier,
		Officer
	};

	Enemy(EnemyType type) : Actor(1, type == EnemyType::Soldier ? "assets/textures/enemy_soldier.png" : "") { };
	~Enemy() = default;

	virtual void shoot(std::shared_ptr<Bullet> bullet) override;
};