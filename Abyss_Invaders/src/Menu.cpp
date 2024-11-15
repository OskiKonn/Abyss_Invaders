#include "Menu.h"
#include <iostream>
#include <string>

Menu::Menu() :
	selectedOption(0)

{
	m_titleHeader.setString("ABYSS INVADERS");
	initMenuOpts();
	
	if (!m_font.loadFromFile("assets/fonts/PlayMeGames-Demo.otf"))
	{
		std::cerr << "FAILED TO LOAD FONT";
	}
}

void Menu::initMenuOpts()
{
	for (std::size_t i = 0; i < MAX_MENU_ITEMS; ++i)
	{
		m_menuOptions[i].setFont(m_font);

		if (i == selectedOption)
		{
			std::string optWithIndicator = m_indicator + m_optionsLabels[i];
			m_menuOptions[i].setString(optWithIndicator);
			m_menuOptions[i].setCharacterSize(23);
		}
		else
		{
			m_menuOptions[i].setString(m_optionsLabels[i]);
			m_menuOptions[i].setCharacterSize(20);
		}

		m_menuOptions[i].setFillColor(sf::Color::White);
		m_menuOptions[i].setPosition(380.f, 380.f + i * 35.f);
	}
}

void Menu::Draw(sf::RenderWindow *win)
{
	for (size_t i = 0; i < MAX_MENU_ITEMS; ++i)
	{
		win->draw(m_menuOptions[i]);
	}
}

void Menu::menuDown()
{
	if (selectedOption < 2)
	{
		++selectedOption;
		initMenuOpts();
	}
}

void Menu::menuUp()
{
	if (selectedOption > 0)
	{
		--selectedOption;
		initMenuOpts();
	}
}

int Menu::menuEnter()
{
	std::cout << "\nSelected Option: " << selectedOption;
	return selectedOption;
}

Menu::~Menu()
{
}
