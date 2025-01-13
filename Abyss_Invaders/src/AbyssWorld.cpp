#pragma once

#include <iostream>
#include "AbyssWorld.h"

AbyssWorld::AbyssWorld() : m_difficulty("EASY")
{
	spawnPlayer();
	initializeUiContent();
}

AbyssWorld::AbyssWorld(std::string mode) : m_difficulty(mode)
{
	spawnPlayer();
	initializeUiContent();
}

void AbyssWorld::test()
{
	std::cout << "WORKING\n";
}

std::shared_ptr<Player> AbyssWorld::spawnPlayer()
{
	player = std::make_shared<Player>("assets/textures/player.png", 3);
	player->sprite.setPosition(300, 300);
	return player;
}

void AbyssWorld::initializeUiContent()
{
	std::string font_path = "assets/fonts/PlayMeGames-Demo.otf";
	sf::Font font;

	if (!font.loadFromFile(font_path))
	{
		std::cout << "FAILED LOADING UI ELEMENTS FONT!\n\n";
	}

	m_modeText.setString("MODE");
	m_scoreText.setString("SCORE");
	m_highScoreText.setString("HS");
	m_livesText.setString("LIVES");

	m_modeText_value.setString(m_difficulty);
	m_scoreText_value.setString(numToText(m_score));
	m_highScoreText_value.setString(numToText(m_highScore));
	m_livesText_value.setString(numToText(m_lives));

	for (sf::Text* text : m_uiElements)
	{
		text->setFont(font);
	}

	std::cout << "\n\nUI ELEMENTS INIT SUCCESSFUL\n";
}

std::string AbyssWorld::numToText(int& num)
{
	std::string castedNum = std::to_string(num);

	if (num < 10)
		return "00" + castedNum;
	else if (num < 100)
		return "0" + castedNum;
	else
		return castedNum;
	
	return "000";
}
