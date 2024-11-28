#include "Engine.h"


// Ready function for checking all neccessary stuff before running
bool Engine::ready()
{
    if (gameWindow.isOpen())
        return true;

    return false;
}

// Running the main loop of the game
void Engine::Run()
{
	while (isGameRunning())
	{
        processEvents();
        renderFrame();
	}
}

// Handling various events, i.e. handling user inputs
void Engine::processEvents()
{
    sf::Event event;

    while (gameWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:

                gameWindow.close();
                break;

            case sf::Event::KeyPressed:

                m_inputController.handleInput(event.key.code);

            default:
                break;

        }
    }
}

// Drawing new Frame
void Engine::renderFrame()
{
    gameWindow.clear();
    drawMenu();
    gameWindow.display();
}

void Engine::drawMenu()
{
    m_menu.Draw();
}

// Menu navigation
void Engine::MenuDown()
{
	m_menu.menuDown();
}

void Engine::MenuUp()
{
	m_menu.menuUp();
}

// Returns if window is open and running
bool Engine::isGameRunning()
{
    return gameWindow.isOpen();
}

Engine::~Engine()
{
}

