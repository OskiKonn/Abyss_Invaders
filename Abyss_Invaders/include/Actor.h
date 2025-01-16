#pragma once
#include <SFML/Graphics.hpp>

class Actor : public sf::Drawable, public sf::Transformable
{
public:

	sf::Sprite sprite;
	sf::Vector2f velocity;
	int hp;

	Actor(int health, std::string texture_path);
	void getDamage(unsigned int damage);
	void goLeft(float& dT);
	void goRight(float& dT);
	virtual void shoot() = 0;
	virtual ~Actor() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(sprite, states);
	}

protected:

	sf::Texture texture;
};

