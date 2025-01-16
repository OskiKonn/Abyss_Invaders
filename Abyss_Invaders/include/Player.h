#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.h"

class Player : public Actor
{
public:

	Player(int hp, const std::string texture_path = "assets/textures/player.png")
		: Actor(hp, texture_path) {}
	virtual void shoot() override;

};

