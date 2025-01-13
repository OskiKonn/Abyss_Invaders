#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include "Menu.h"
#include "InputControl.h"
#include "AbyssWorld.h"

class Engine
{
public:


	Engine() : gameWindow(sf::VideoMode(800, 600), "Abyss Invaders", sf::Style::Default),
		m_menu(&gameWindow, this),
		inputController(m_menu) { }

	bool ready();
	void Run();
	void drawMenu();
	void createAbyss();

	~Engine();

private:

	sf::RenderWindow gameWindow;
	Menu m_menu;
	std::unique_ptr<AbyssWorld> abyssWorld;
	sf::Time deltaTime;

	bool isGameRunning();
	void processEvents();
	void renderFrame();
	
public:
	InputControl inputController;
};

