#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "Bullet.h"

class Enemy : public Actor
{
public:

	bool canShoot = false;

	enum class EnemyType {
		Soldier,
		Officer
	};

	Enemy(EnemyType type);
	~Enemy() = default;

	virtual void shoot(std::shared_ptr<Bullet> bullet) override;

};