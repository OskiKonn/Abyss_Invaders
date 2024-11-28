#include "InputControl.h"

InputControl::InputControl()
{
}

void InputControl::handlePlayerMovement(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (playerLeft)
            playerLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (playerRight)
            playerRight();
}

void InputControl::handleMenuNavigation(sf::Event &event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        menuUp();
        break;

    case sf::Keyboard::Down:
        menuDown();
        break;

    case sf::Keyboard::Enter:
        menuEnter();

        // If selected to play, sets isMenuActive to false and thus creates
        // new Player object and sets is starting position
        if (selectedMenu == Menu::MenuType::PlayMenu)
        {
            isMenuActive = false;
            isGameLive = true;
            player = std::make_shared<Player>();
            player->playerSprite.setPosition(gameWindow.getSize().x / 2, gameWindow.getSize().y / 1.15);
        }
        break;
    }
}
