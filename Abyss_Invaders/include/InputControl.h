#pragma once

#include <SFML/Window.hpp>
#include <iostream>
#include "Menu.h"

class InputControl
{
public:

	InputControl(Menu& Ui) : m_ui(Ui) { }
	void handleInput(sf::Keyboard::Key& key_code);
	void setPlayer();
	~InputControl() = default;

private:

	Menu& m_ui;
	bool *inMenu = &m_ui.inMenu;

	void navigateMenu(sf::Keyboard::Key& key_code);
	void handlePlayerActions(sf::Keyboard::Key& key_code);
};

