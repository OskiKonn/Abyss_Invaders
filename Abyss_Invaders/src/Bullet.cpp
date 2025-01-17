#include "Bullet.h"
#include <iostream>

Bullet::Bullet() : speed(0, -600.f)
{
	body.setSize(sf::Vector2f(8.0f, 14.0f));
	body.setFillColor(sf::Color::White);
	body.setPosition(390.0f, 250.0f);
}

void Bullet::fireUp(sf::Vector2f &barell)
{
	body.setPosition(barell);
}

void Bullet::fireDown(sf::Vector2f &barell)
{
	body.setPosition(barell);
	speed = -speed;
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
}
