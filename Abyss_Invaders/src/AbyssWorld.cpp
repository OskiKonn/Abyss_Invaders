#pragma once

#include <iostream>
#include "AbyssWorld.h"

AbyssWorld::AbyssWorld(const sf::Vector2u &winSizeRef, GameMode mode) : m_gameMode(mode), winSize(winSizeRef)
{
	initializeUiContent();
	uiElementsPtr = &m_uiElements;
	actorsPtr = &m_actors;
	spawnPlayer();
	spawnEnemies(mode);
}

void AbyssWorld::test()
{
	std::cout << "WORKING\n";
}

void AbyssWorld::moveLeft(float& deltaTime)
{
	player->goLeft(deltaTime);
}

void AbyssWorld::moveRight(float& deltaTime)
{
	player->goRight(deltaTime);
}

std::shared_ptr<Player> AbyssWorld::spawnPlayer()
{
	player = std::make_shared<Player>(3);

	float winX = static_cast<float>(winSize.x);
	float winY = static_cast<float>(winSize.y);

	player->sprite.setPosition(winX * 0.48f, winY * 0.83f);
	player->sprite.setScale(0.1f, 0.1f);

	m_actors.push_back(player);
	return player;
}

void AbyssWorld::initializeUiContent()
{
	std::string font_path = "assets/fonts/ariblk.ttf";

	if (!m_font.loadFromFile(font_path))
	{
		std::cerr << "FAILED LOADING UI ELEMENTS FONT!\n\n";
	}

	std::string difficulty = "";

	switch (m_gameMode)
	{
		case GameMode::Easy:
			difficulty = "EASY";
			break;

		case GameMode::Medium:
			difficulty = "MEDIUM";
			break;

		case GameMode::Hard:
			difficulty = "HARD";
			break;
	}

	m_modeText.setString("MODE");
	m_scoreText.setString("SCORE");
	m_highScoreText.setString("HS");
	m_livesText.setString("LIVES");

	m_modeText_value.setString(difficulty);
	m_scoreText_value.setString(numToText(m_score));
	m_highScoreText_value.setString(numToText(m_highScore));
	m_livesText_value.setString(numToText(m_lives));

	for (sf::Text* text : m_uiElements)
	{
		text->setFont(m_font);
		text->setCharacterSize(15);
	}

	std::cout << "\n\nUI ELEMENTS INIT SUCCESSFUL\n";
}

void AbyssWorld::spawnEnemies(GameMode& gameMode)
{
	switch (gameMode)
	{
	case GameMode::Easy:

		for (size_t v = 0; v < 3; ++v)
		{
			for (size_t h = 0; h < 3; ++h)
			{

				std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(Enemy::EnemyType::Soldier);

				float winX = static_cast<float>(winSize.x);
				float winY = static_cast<float>(winSize.y);

				enemy->sprite.setPosition(winX * 0.4f + h * winX * 0.07f, winY * 0.25f + v * winY * 0.05f);
				enemy->sprite.setScale(0.06f, 0.06f);

				m_actors.push_back(enemy);

			}
		}

		break;
	}
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
