#pragma once

#include <SFML/Window.hpp>
#include <memory>
#include <functional>

class InputControl
{
public:

	std::function<void()> menuUp;
	std::function<void()> menuDown;
	std::function<void()> menuEnter;
	std::function<void()> playerLeft;
	std::function<void()> playerRight;

	InputControl() = default;
	void handlePlayerMovement(const float& dt);
	void handleMenuNavigation(sf::Event &event);
	~InputControl() = default;

private:

};

