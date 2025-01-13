#pragma once
#include <SFML/Graphics.hpp>

class Actor : public sf::Drawable, public sf::Transformable
{
public:

	sf::Sprite sprite;
	int hp;

	Actor(std::string texture_path, int hp);
	void getDamage(unsigned int damage);
	virtual void shoot() = 0;
	virtual ~Actor() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(sprite, states);
	}

protected:

	sf::Texture texture;
	sf::Vector2f velocity;
};

