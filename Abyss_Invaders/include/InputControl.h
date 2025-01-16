#pragma once

#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include "Menu.h"
#include "AbyssWorld.h"

class InputControl
{
public:

	InputControl(Menu& Ui) : m_ui(Ui) { }
	void handleInput(sf::Keyboard::Key& key_code, float &deltaTime);
	void setAbyssWorld(std::shared_ptr<AbyssWorld>& world);
	~InputControl() = default;

private:

	Menu& m_ui;
	std::shared_ptr<AbyssWorld> abyssWorld;
	bool *inMenu = &m_ui.inMenu;

	void navigateMenu(sf::Keyboard::Key& key_code);
	void handlePlayerActions(sf::Keyboard::Key& key_code, float& deltaTime);
};

