#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Engine
{
public:
	
	sf::RenderWindow gameWindow;
	bool isMenuActive = true;

	Engine() : gameWindow(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default) { }
	bool ready();
	void Run();
	void processEvents(sf::Event &event);
	void renderFrame();
	void drawMenu();
	void MenuDown();
	void MenuUp();
	~Engine();

private:

	Menu m_menu;

	bool isGameRunning();
};

