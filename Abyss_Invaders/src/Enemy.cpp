#pragma once

#include "Enemy.h"
#include <iostream>


void Enemy::shoot(std::shared_ptr<Bullet> bullet)
{
	std::cout << '\n' << "Enemy shooting logic";
}
