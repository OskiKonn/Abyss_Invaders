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
	sf::Sprite playerSprite;

	Player();

	void move(Direction direction, const float& deltaTime);
	virtual ~Player() = default;

private:
	
	sf::Texture m_playerTexture;
	sf::Vector2f velocity;
	const std::string m_texture_path = "assets/textures/player.png";
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

