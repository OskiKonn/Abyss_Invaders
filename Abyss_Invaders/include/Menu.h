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

	enum class MenuType {
		MainMenu,
		SettingsMenu,
		PlayMenu,
		PauseMenu,
		EndGameMenu,
		QuitMenu
	};

	MenuType menu_type = MenuType::MainMenu;
	short selectedOption;
	bool inMenu = true;

	Menu(sf::RenderWindow* win, Engine *engine);
	void initMenuOpts();
	void Draw();
	void menuDown();
	void menuUp();
	void changeMenu();
	int menuEnter();
	~Menu();

private:

	sf::RenderWindow* m_gameWin;
	Engine* engine = nullptr;
	const std::string m_fontPath = "assets/fonts/PlayMeGames-Demo.otf";
	const char m_indicator[4] = ">  ";
	sf::Text m_menuOptions[MAX_MENU_ITEMS];
	sf::Text m_titleHeader;
	sf::Font m_font;
	std::string m_optionsLabels[MAX_MENU_ITEMS] = { "Play", "Settings", "Quit", "" };
	std::string m_pausedMenuLabels[MAX_MENU_ITEMS] = { "Resume", "Restart", "Back to menu", ""};
	std::string m_quitMenuLabels[MAX_MENU_ITEMS] = { "Yes", "No", ""};
	std::string m_endMenuLabels[MAX_MENU_ITEMS] = { "Return to menu", "Quit", ""};
	std::string m_playMenuLabels[MAX_MENU_ITEMS] = { "Easy", "Medium", "Hard", "" };
	std::string* labels;

	void setCurrentLables(MenuType& type);

};

