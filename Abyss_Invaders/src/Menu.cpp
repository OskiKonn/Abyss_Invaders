#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow *win) :
	selectedOption(0),
	gameWindow(win)

{
	if (!m_font.loadFromFile(m_fontPath))
	{
		std::cerr << "FAILED TO LOAD FONT";
	}

	m_titleHeader.setString("ABYSS INVADERS");
	initMenuOpts();
	
}

// Initializing current menu options + positioning
void Menu::initMenuOpts()
{
	for (std::size_t i = 0; i < MAX_MENU_ITEMS && m_optionsLabels[i] != ""; ++i)
	{

		m_menuOptions[i].setFont(m_font);

		if (i == selectedOption)
		{
			// Sets > indicator next to active option 
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

		/*
		m_titleHeader.setFont(m_font);
		m_titleHeader.setPosition(gameWindow->getSize().x / 2 - m_titleHeader.getGlobalBounds().width / 2,
								  gameWindow->getSize().y / 8);
		m_titleHeader.setCharacterSize(32);
		*/
	}
}

void Menu::Draw()
{
	for (size_t i = 0; i < MAX_MENU_ITEMS && m_optionsLabels[i] != ""; ++i)
	{
		gameWindow->draw(m_menuOptions[i]);
	}

	gameWindow->draw(m_titleHeader);
}

void Menu::menuDown()
{
	if (selectedOption < MAX_MENU_ITEMS - 1 && m_optionsLabels[selectedOption + 1] != "")
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

// Responsible for menu selection. Returns MenuType to menu input handling in Engine
enum Menu::MenuType Menu::menuEnter()
{
	switch (selectedOption)
	{
		case 0:
			m_menu_type = MenuType::PlayMenu;
			break;

		case 1:
			m_menu_type = MenuType::SettingsMenu;
			break;

		// Quits the game and closes the window
		case 2:
			gameWindow->close();
			break;

		default:
			std::cerr << "\nNo such menu option!";
			break;
	}

	std::cout << "\nSelected Option: " << selectedOption;
}

