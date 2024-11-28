#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class Player : public sf::Transformable, public sf::Drawable
{
public:
	
	enum class Direction
	{
		Left,
		Right
	};

	int health = 3;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	Player() = default;

	void move(Direction direction, const float& deltaTime);
	virtual ~Player() = default;

private:
	
};

