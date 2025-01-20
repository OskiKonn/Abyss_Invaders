#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <Actor.h>

class Bullet : public sf::Transformable, public sf::Drawable
{
public:

	Bullet();
	Bullet(sf::Vector2f velocity);
	~Bullet() = default;
	void fireUp(sf::Vector2f &barell);
	void fireDown(sf::Vector2f &barell);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape body;
	sf::Vector2f speed;

private:

	std::string m_texture_path = "assets/textures/enemy_soldier.png";
	sf::Texture m_texture;
};

