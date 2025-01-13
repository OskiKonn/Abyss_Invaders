#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>

const size_t MAX_MENU_ITEMS = 5;

class Engine;			// Forward declaration

class Menu
{

public:

	short selectedOption;
	bool inMenu = true;

	Menu(sf::RenderWindow* win, Engine *engine);
	void initMenuOpts();
	void Draw();
	void menuDown();
	void menuUp();
	int menuEnter();
	~Menu();

private:

	enum class MenuType {
		MainMenu,
		SettingsMenu,
		PlayMenu
	};

	sf::RenderWindow* m_gameWin;
	Engine* engine = nullptr;
	const std::string m_fontPath = "assets/fonts/PlayMeGames-Demo.otf";
	const char m_indicator[4] = ">  ";
	sf::Text m_menuOptions[MAX_MENU_ITEMS];
	sf::Text m_titleHeader;
	sf::Font m_font;
	MenuType m_menu_type = MenuType::MainMenu;
	std::string m_optionsLabels[MAX_MENU_ITEMS] = { "Play", "Settings", "Quit", "" };
};

