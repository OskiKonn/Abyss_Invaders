#pragma once
#include <SFML/Graphics.hpp>

class Bullet;

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
	sf::FloatRect getHitbox() const;
	virtual void shoot(std::shared_ptr<Bullet>) = 0;
	virtual ~Actor() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

	sf::Texture texture;
};

