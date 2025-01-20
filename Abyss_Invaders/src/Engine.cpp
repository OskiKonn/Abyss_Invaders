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

            quit();
            break;

        case sf::Event::KeyPressed:

            inputController.handleInput(event.key.code, deltaTime);

        default:

            break;

        }
    }

    if (m_abyssExists && !m_abyssWorld->gameOver && !m_abyssWorld->paused)
    {
        m_abyssWorld->update(deltaTime);
    }
    else if (m_abyssExists && m_abyssWorld->gameOver)
    {
        m_menu.menu_type = Menu::MenuType::EndGameMenu;
        m_menu.changeMenu();
        m_menu.inMenu = true;
    }
    else if (m_abyssExists && m_abyssWorld->paused)
    {
        m_menu.menu_type = Menu::MenuType::PauseMenu;
        m_menu.changeMenu();
        m_menu.inMenu = true;
    }
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

void Engine::createAbyss(int mode)
{
    AbyssWorld::GameMode gameMode;

    if (mode == 1)
        gameMode = AbyssWorld::GameMode::Easy;
    else if (mode == 2)
        gameMode = AbyssWorld::GameMode::Medium;
    else if (mode == 3)
        gameMode = AbyssWorld::GameMode::Hard;

    winSize = gameWindow.getSize();
    m_abyssWorld = std::make_shared<AbyssWorld>(winSize, gameMode);
    m_abyssWorld->test();
    inputController.setAbyssWorld(m_abyssWorld);
    m_painter.setActorsVector(m_abyssWorld->actorsPtr, m_abyssWorld->uiElementsPtr, m_abyssWorld->bulletsPtr);
    m_abyssExists = true;
}

void Engine::resumeGame()
{
    m_menu.inMenu = false;
    m_abyssWorld->restartClocks();
    m_abyssWorld->paused = false;
}

void Engine::quit()
{
    gameWindow.close();
}

void Engine::endGame()
{
    m_abyssWorld->paused = false;
    m_abyssWorld->gameOver = false;
    m_abyssExists = false;
}

void Engine::restartGame()
{
    AbyssWorld::GameMode gameMode = m_abyssWorld->gameMode;
    
    winSize = gameWindow.getSize();
    m_abyssWorld = std::make_shared<AbyssWorld>(winSize, gameMode);
    m_abyssWorld->test();
    inputController.setAbyssWorld(m_abyssWorld);
    m_painter.setActorsVector(m_abyssWorld->actorsPtr, m_abyssWorld->uiElementsPtr, m_abyssWorld->bulletsPtr);
    m_abyssExists = true;
}



