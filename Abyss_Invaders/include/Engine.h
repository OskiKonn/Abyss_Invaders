#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>s
#include "Menu.h"
#include "InputControl.h"

class Engine
{
public:
	
	sf::RenderWindow gameWindow;
	bool isMenuActive = true;

	Engine() : gameWindow(sf::VideoMode(800, 600), "Abyss Invaders", sf::Style::Default),
			   m_menu(&gameWindow), m_inputController(m_menu) {  }

	bool ready();
	void Run();
	void processEvents();
	void renderFrame();
	void drawMenu();
	void MenuDown();
	void MenuUp();
	~Engine();

private:

	Menu m_menu;
	InputControl m_inputController;
	sf::Time deltaTime;

	bool isGameRunning();
};

