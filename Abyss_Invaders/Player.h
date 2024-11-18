#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Transformable, public sf::Drawable
{
public:
	
	int health = 3;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	Player() = default;

private:
	
	static const sf::Vector2f velocity;
};

