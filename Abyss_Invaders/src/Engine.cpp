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
    sf::Clock gameClock;

	while (isGameRunning())
	{
        m_deltaTime = gameClock.restart();
        update(m_deltaTime.asSeconds());
        renderFrame();
	}
}

// Handling user inputs and event
void Engine::update(const float &dt)
{
    sf::Event event;

    while (gameWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                gameWindow.close();
                break;

            // Handles single key input
            case sf::Event::KeyPressed:
                if (isMenuActive)
                    handleMenuNavigation(event);

            default:
                break;

        }
    }

    if (isGameLive)
        inputController.handlePlayerMovement(dt);

}

// Drawing new Frame
void Engine::renderFrame()
{
    gameWindow.clear();
    drawMenu();

    if (player)
        gameWindow.draw(*player);

    gameWindow.display();
}

void Engine::drawMenu()
{
    if (isMenuActive)
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

bool Engine::startLevel()
{
    return false;
}

void Engine::handleMenuNavigation(sf::Event &event)
{
        switch (event.key.code)
        {
            case sf::Keyboard::Up:
                MenuUp();
                break;

            case sf::Keyboard::Down:
                MenuDown();
                break;

            case sf::Keyboard::Enter:
                Menu::MenuType selectedMenu = m_menu.menuEnter();

                // If selected to play, sets isMenuActive to false and thus creates
                // new Player object and sets is starting position
                if (selectedMenu == Menu::MenuType::PlayMenu)
                {
                    isMenuActive = false;
                    isGameLive = true;
                    player = std::make_shared<Player>();
                    inputController.setPlayer(player);
                    player->playerSprite.setPosition(gameWindow.getSize().x / 2, gameWindow.getSize().y / 1.15);
                }
                break;
        }
}

// Returns if window is open and running
bool Engine::isGameRunning()
{
    return gameWindow.isOpen();
}

