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
		m_painter(&gameWindow) { };

	bool ready();
	void Run();
	void drawMenu();
	void createAbyss(int mode);
	void resumeGame();
	void quit();
	void endGame();
	void restartGame();

	~Engine() = default;

private:

	bool m_abyssExists = false;
	sf::RenderWindow gameWindow;
	sf::Clock m_gameClock;
	sf::Vector2u winSize;
	Menu m_menu;
	std::shared_ptr<AbyssWorld> m_abyssWorld;
	Painter m_painter;

	bool isGameRunning();
	void processEvents();
	void renderFrame();
	
public:
	InputControl inputController;
};

