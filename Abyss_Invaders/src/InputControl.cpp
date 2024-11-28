#include "InputControl.h"

void InputControl::handleInput(sf::Keyboard::Key &key_code)
{
	if (inMenu)
	{
		navigateMenu(key_code);
	}
	else
	{
		std::cerr << "\nCANNOT PROCESS INPUT\n";
	}
}

{
}

{
	{
		case sf::Keyboard::Up:
			break;

		case sf::Keyboard::Down:
			break;

		case sf::Keyboard::Enter:
			break;
	}
}

void InputControl::handlePlayerActions(sf::Keyboard::Key& key_code)
{
	// TO DO
}
