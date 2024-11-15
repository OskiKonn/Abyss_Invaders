#pragma once

#include <SFML/Graphics.hpp>
#include <string>

const size_t MAX_MENU_ITEMS = 3;

class Menu
{

public:

	 short selectedOption;

	Menu();
	void initMenuOpts();
	void Draw(sf::RenderWindow *win);
	void menuDown();
	void menuUp();
	int menuEnter();
	~Menu();

private:

	const char m_indicator[4] = ">  ";
	sf::Text m_menuOptions[MAX_MENU_ITEMS];
	sf::Text m_titleHeader;
	sf::Font m_font;
	const std::string m_optionsLabels[MAX_MENU_ITEMS] = {"Play", "Settings", "Quit"};
};

