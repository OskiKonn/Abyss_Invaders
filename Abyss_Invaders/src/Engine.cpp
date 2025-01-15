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

            inputController.handleInput(event.key.code);

        default:
            break;

        }
    }
}

// Drawing new Frame
void Engine::renderFrame()
{
    gameWindow.clear();

    if (m_menu.inMenu)
        drawMenu();
    else if (painter.isReady())
    {
        painter.paint();
    }

    gameWindow.display();
}

void Engine::drawMenu()
{
    m_menu.Draw();
}


// Returns if window is open and running
bool Engine::isGameRunning()
{
    return gameWindow.isOpen();
}

void Engine::createAbyss()
{
    abyssWorld = std::make_unique<AbyssWorld>();
    abyssWorld->test();
    painter.setActorsVector(abyssWorld->actorsPtr, abyssWorld->uiElementsPtr);
}



