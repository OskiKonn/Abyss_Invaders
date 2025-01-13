#pragma once

#include "Actor.h"

Actor::Actor(std::string texture_path, int hp)
{
	texture.loadFromFile(texture_path);
	sprite.setTexture(texture);
	this->hp = hp;
}

void Actor::getDamage(unsigned int damage)
{
	hp = hp - damage;
}
