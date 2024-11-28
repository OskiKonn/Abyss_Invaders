#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>s
#include "Menu.h"

class Engine
{
public:
	
	sf::RenderWindow gameWindow;
	bool isMenuActive = true;
	bool isGameLive = false;

	Engine() : gameWindow(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default),
			   m_menu(&gameWindow) { }

	bool ready();
	void Run();
	void processEvents(sf::Event &event);
	void renderFrame();
	void drawMenu();
	void MenuDown();
	void MenuUp();
	bool startLevel();	// To Do: Add enum level parameter
	void handleMenuNavigation(sf::Event &event);

	~Engine() = default;

private:

	sf::Time m_deltaTime;
	Menu m_menu;

	bool isGameRunning();
};

