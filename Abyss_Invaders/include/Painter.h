#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Actor.h"

#define UI_ELEMENST_NUM 8

typedef std::array<sf::Text*, UI_ELEMENST_NUM> UI_ELEMENTS_ARRAY;
typedef std::vector<std::shared_ptr<Actor>> ACTORS_VECTOR;

class Painter
{
public:

	Painter(sf::RenderWindow* window) : m_gameWindow(window) { };
	~Painter() = default;

	void setActorsVector(ACTORS_VECTOR *actors, UI_ELEMENTS_ARRAY *elements);
	void paint();
	bool isReady();

private:

	bool ready = false;

	sf::RenderWindow* m_gameWindow;

	UI_ELEMENTS_ARRAY  *m_uiElements;
	ACTORS_VECTOR *m_actors;

	void setUiElementsPos();
};

