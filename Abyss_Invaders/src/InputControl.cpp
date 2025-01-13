#include "InputControl.h"

void InputControl::handleInput(sf::Keyboard::Key& key_code)
{
	if (*inMenu)
	{
		navigateMenu(key_code);
	}
	else
	{
		std::cerr << "\nCANNOT PROCESS INPUT\n";
	}
}

void InputControl::setPlayer()
{
	// TO DO
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

void InputControl::handlePlayerActions(sf::Keyboard::Key& key_code)
{
	// TO DO
}
