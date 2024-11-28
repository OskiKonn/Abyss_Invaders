#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <memory>
#include "Menu.h"
#include "Player.h"
#include "InputControl.h"

class Engine
{
public:
	
	sf::RenderWindow gameWindow;
	bool isMenuActive = true;
	bool isGameLive = false;

	Engine() : gameWindow(sf::VideoMode(800, 600), "Abyss Invaders", sf::Style::Default),
			   m_menu(&gameWindow) { }

	bool ready();
	void Run();
	void update(const float &dt);
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
	InputControl inputController;
	std::shared_ptr<Player> player;

	bool isGameRunning();
};

