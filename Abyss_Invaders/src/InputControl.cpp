#include "InputControl.h"

void InputControl::handleInput(sf::Keyboard::Key& key_code, float &deltaTime)
{
	if (*inMenu)
	{
		navigateMenu(key_code);
	}
	else
	{
		handlePlayerActions(key_code, deltaTime);
	}
}


void InputControl::navigateMenu(sf::Keyboard::Key& key_code)
{
	switch (key_code)
	{
	case sf::Keyboard::Up:
		m_ui.menuUp();
		break;

	case sf::Keyboard::Down:
		m_ui.menuDown();
		break;

	case sf::Keyboard::Enter:
		m_ui.menuEnter();
		break;
	}
}

void InputControl::handlePlayerActions(sf::Keyboard::Key& key_code, float &deltaTime)
{
	switch (key_code)
	{
		case sf::Keyboard::A:
			abyssWorld->moveLeft(deltaTime);
			break;

		case sf::Keyboard::D:
			abyssWorld->moveRight(deltaTime);
			break;

		case sf::Keyboard::W:
			abyssWorld->firePlayer();
			break;
	}
}

void InputControl::setAbyssWorld(std::shared_ptr<AbyssWorld>& world)
{
	abyssWorld = world;
}
