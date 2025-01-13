#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Actor.h"

class Painter
{
public:

	Painter() = default;
	~Painter() = default;

private:

	std::array<sf::Text*, 8>* uiElements;
	std::vector<std::shared_ptr<Actor>>* actors;
};

