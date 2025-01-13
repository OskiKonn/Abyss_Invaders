#include "Menu.h"
#include "Engine.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* win, Engine *engine) :
	selectedOption(0),
	m_gameWin(win)

{
	this->engine = engine;

	if (!m_font.loadFromFile(m_fontPath))
	{
		std::cerr << "FAILED TO LOAD FONT";
	}

	m_titleHeader.setString("ABYSS INVADERS");
	initMenuOpts();

}

void Menu::initMenuOpts()
{
	for (std::size_t i = 0; i < MAX_MENU_ITEMS && m_optionsLabels[i] != ""; ++i)
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

		/*
		m_titleHeader.setFont(m_font);
		m_titleHeader.setPosition(m_gameWin->getSize().x / 2 - m_titleHeader.getGlobalBounds().width / 2,
								  m_gameWin->getSize().y / 8);
		m_titleHeader.setCharacterSize(32);
		*/
	}
}

void Menu::Draw()
{
	for (size_t i = 0; i < MAX_MENU_ITEMS && m_optionsLabels[i] != ""; ++i)
	{
		m_gameWin->draw(m_menuOptions[i]);
	}

	m_gameWin->draw(m_titleHeader);
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

int Menu::menuEnter()
{
	switch (selectedOption)
	{
	case 0:
		m_menu_type = MenuType::PlayMenu;
		inMenu = false;
		engine->createAbyss();	// Creates AbyssWorld
		break;

	case 1:
		m_menu_type = MenuType::SettingsMenu;
		break;

	case 2:
		m_gameWin->close();
		break;

	default:
		std::cerr << "\nNo such menu option!";
		break;
	}

	//std::cout << "\nSelected Option: " << selectedOption;
	return selectedOption;
}

Menu::~Menu()
{
}
