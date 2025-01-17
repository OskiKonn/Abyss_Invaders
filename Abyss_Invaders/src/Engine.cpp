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
    gameWindow.setFramerateLimit(144);

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
    float deltaTime = m_gameClock.restart().asSeconds();

    while (gameWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:

            gameWindow.close();
            break;

        case sf::Event::KeyPressed:

            inputController.handleInput(event.key.code, deltaTime);

        default:
            break;

        }
    }

    if (m_abyssExists)
        m_abyssWorld->update(deltaTime);
}

// Drawing new Frame
void Engine::renderFrame()
{
    gameWindow.clear();

    if (m_menu.inMenu)
        drawMenu();
    else if (m_painter.isReady())
    {
        m_painter.paint();
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
    winSize = gameWindow.getSize();
    m_abyssWorld = std::make_shared<AbyssWorld>(winSize);
    m_abyssWorld->test();
    inputController.setAbyssWorld(m_abyssWorld);
    std::cout << '\n' << m_abyssWorld->bulletsPtr->size();
    m_painter.setActorsVector(m_abyssWorld->actorsPtr, m_abyssWorld->uiElementsPtr, m_abyssWorld->bulletsPtr);
    m_abyssExists = true;
}



