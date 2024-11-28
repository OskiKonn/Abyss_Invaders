#include "Player.h"
#include <iostream>

#define GREEN   "\033[32m"
#define RESET   "\033[0m"


Player::Player() :
	velocity(165.f, 0.f)

{
	if (!m_playerTexture.loadFromFile(m_texture_path))
	{
		std::cerr << "\nFailed loading player texture\n";
	}

	playerSprite.setTexture(m_playerTexture);

	// Scales player sprite to be 30x30
	playerSprite.setScale(30.f / m_playerTexture.getSize().x, 30.f / m_playerTexture.getSize().y);
	
}

void Player::move(Direction direction, const float &deltaTime)
{
	switch (direction)
	{
		case Direction::Left:
			velocity.x = -165.f;
			break;
		
		case Direction::Right:
			velocity.x = 165.f;
			break;
	}

	playerSprite.move(velocity * deltaTime);
}

// Overriding sf::Drawable pure virtual
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(playerSprite, states);
}
