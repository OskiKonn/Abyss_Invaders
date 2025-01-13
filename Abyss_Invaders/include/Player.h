#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.h"

class Player : public Actor
{
public:

	Player(const std::string& texture_path, int hp)
		: Actor(texture_path, hp) {}
	virtual void shoot() override;

private:

	const std::string m_texture_path = "assets/textures/player.png";
};

