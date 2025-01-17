#include "Player.h"
#include <iostream>
#include "Bullet.h"

void Player::shoot(std::shared_ptr<Bullet> bullet)
{
	sf::FloatRect bounds = sprite.getGlobalBounds();
	sf::Vector2f barell(bounds.left + bounds.width / 2.0f, bounds.top);
	bullet->fireUp(barell);
}
