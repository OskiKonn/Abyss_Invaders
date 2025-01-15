#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include "Menu.h"
#include "InputControl.h"
#include "AbyssWorld.h"
#include "Painter.h"

class Engine
{
public:


	Engine() : gameWindow(sf::VideoMode(800, 600), "Abyss Invaders", sf::Style::Default),
		m_menu(&gameWindow, this),
		inputController(m_menu),
		painter(&gameWindow) { };

	bool ready();
	void Run();
	void drawMenu();
	void createAbyss();

	~Engine() = default;

private:

	sf::RenderWindow gameWindow;
	Menu m_menu;
	std::unique_ptr<AbyssWorld> abyssWorld;
	sf::Time deltaTime;
	Painter painter;

	bool isGameRunning();
	void processEvents();
	void renderFrame();
	
public:
	InputControl inputController;
};

