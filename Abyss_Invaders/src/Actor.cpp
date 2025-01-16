#pragma once

#include "Actor.h"

Actor::Actor(int health, std::string texture_path) : velocity(1000.f, 0), hp(health)
{
	texture.loadFromFile(texture_path);
	sprite.setTexture(texture);
}

void Actor::getDamage(unsigned int damage)
{
	hp = hp - damage;
}

void Actor::goLeft(float &dT)
{
	if (sprite.getPosition().x > 200.f)
	{
		sf::Vector2f moveVector = -velocity * dT;
		sprite.move(moveVector);
	}
}

void Actor::goRight(float &dT)
{
	if (sprite.getPosition().x < 600.f)
	{
		sf::Vector2f moveVector = velocity * dT;
		sprite.move(moveVector);

	}
}
