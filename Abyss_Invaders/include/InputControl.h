#pragma once

#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include "Menu.h"

class InputControl
{
public:

	~InputControl() = default;

private:
	
	bool inMenu = true;
	Menu &m_ui;

	void navigateMenu(sf::Keyboard::Key& key_code);
	void handlePlayerActions(sf::Keyboard::Key& key_code);
};

