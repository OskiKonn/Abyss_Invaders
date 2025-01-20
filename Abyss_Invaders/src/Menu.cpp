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
	changeMenu();

}

void Menu::initMenuOpts()
{

	for (std::size_t i = 0; i < MAX_MENU_ITEMS && labels[i] != ""; ++i)
	{

		m_menuOptions[i].setFont(m_font);

		if (i == selectedOption)
		{
			std::string optWithIndicator = m_indicator + labels[i];
			m_menuOptions[i].setString(optWithIndicator);
			m_menuOptions[i].setCharacterSize(23);
		}
		else
		{
			m_menuOptions[i].setString(labels[i]);
			m_menuOptions[i].setCharacterSize(20);
		}

		m_menuOptions[i].setFillColor(sf::Color::White);
		m_menuOptions[i].setPosition(380.f, 380.f + i * 35.f);

	}
}

void Menu::Draw()
{
	for (size_t i = 0; i < MAX_MENU_ITEMS && labels[i] != ""; ++i)
	{
		m_gameWin->draw(m_menuOptions[i]);
	}

	m_gameWin->draw(m_titleHeader);
}

void Menu::menuDown()
{
	if (selectedOption < MAX_MENU_ITEMS - 1 && labels[selectedOption + 1] != "")
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

void Menu::changeMenu()
{
	setCurrentLables(menu_type);
	initMenuOpts();
}

int Menu::menuEnter()
{
	switch (selectedOption)
	{
	case 0:

		if (menu_type == MenuType::PlayMenu)
		{
			inMenu = false;
			engine->createAbyss(1);	// Creates AbyssWorld
		}
		else if (menu_type == MenuType::PauseMenu)
		{
			engine->resumeGame();
		}
		else if (menu_type == MenuType::QuitMenu)
		{
			engine->quit();
		}
		else if (menu_type == MenuType::EndGameMenu)
		{
			menu_type = MenuType::MainMenu;
			engine->endGame();
			changeMenu();
		}
		else if (menu_type == MenuType::MainMenu)
		{
			menu_type = MenuType::PlayMenu;
			changeMenu();
		}

		break;

	case 1:
		
		if (menu_type == MenuType::PlayMenu)
		{
			inMenu = false;
			engine->createAbyss(2);	// Creates AbyssWorld
		}
		else if (menu_type == MenuType::PauseMenu)
		{
			inMenu = false;
			engine->restartGame();
		}
		else if (menu_type == MenuType::QuitMenu)
		{
			engine->resumeGame();
		}
		else if (menu_type == MenuType::EndGameMenu)
		{
			menu_type = MenuType::MainMenu;
			engine->quit();
		}

		break;

	case 2:
		
		if (menu_type == MenuType::PlayMenu)
		{
			inMenu = false;
			engine->createAbyss(3);	// Creates AbyssWorld
		}
		else if (menu_type == MenuType::PauseMenu)
		{
			menu_type = MenuType::MainMenu;
			engine->endGame();
			changeMenu();
		}
		else if (menu_type == MenuType::MainMenu)
		{
			engine->quit();
		}

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

void Menu::setCurrentLables(MenuType& type)
{
	switch (type)
	{
	case MenuType::MainMenu:
		labels = m_optionsLabels;
		break;

	case MenuType::PlayMenu:
		labels = m_playMenuLabels;
		break;

	case MenuType::PauseMenu:
		labels = m_pausedMenuLabels;
		break;

	case MenuType::EndGameMenu:
		labels = m_endMenuLabels;
		break;

	case MenuType::QuitMenu:
		labels = m_quitMenuLabels;
		break;

	}
}
