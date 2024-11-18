#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>

const size_t MAX_MENU_ITEMS = 5;

class Menu
{

public:

	short selectedOption;

	Menu(sf::RenderWindow *win);
	void initMenuOpts();
	void Draw();
	void menuDown();
	void menuUp();
	void menuEnter();
	~Menu();

private:

	enum MenuType {
		MainMenu,
		SettingsMenu,
		PlayMenu
	};

	sf::RenderWindow* m_gameWin;
	const std::string m_fontPath = "assets/fonts/PlayMeGames-Demo.otf";
	const char m_indicator[4] = ">  ";
	sf::Text m_menuOptions[MAX_MENU_ITEMS];
	sf::Text m_titleHeader;
	sf::Font m_font;
	MenuType m_menu_type = MainMenu;
	std::string m_optionsLabels[MAX_MENU_ITEMS] = {"Play", "Settings", "Quit", ""};
};

