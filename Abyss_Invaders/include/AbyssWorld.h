#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <vector>
#include <string>
#include "Player.h"
#include "Actor.h"

const int UI_ELEMENTS_NUM = 8;

typedef std::array<sf::Text*, UI_ELEMENTS_NUM> UI_ELEMENTS_ARRAY;
typedef std::vector<std::shared_ptr<Actor>> ACTORS_VECTOR;

class AbyssWorld
{
public:

	AbyssWorld();
	AbyssWorld(std::string mode);
	~AbyssWorld() = default;

	void test();
	
	UI_ELEMENTS_ARRAY  *uiElementsPtr;
	ACTORS_VECTOR *actorsPtr;

private:

	int m_score = 0;
	int m_lives = 3;
	int m_highScore = 0;
	std::string m_difficulty = "";

	std::shared_ptr<Player> player;
	std::shared_ptr<Player> spawnPlayer();

	sf::Font font;
	sf::Text m_modeText;
	sf::Text m_scoreText;
	sf::Text m_highScoreText;
	sf::Text m_livesText;

	sf::Text m_modeText_value;
	sf::Text m_scoreText_value;
	sf::Text m_highScoreText_value;
	sf::Text m_livesText_value;

	UI_ELEMENTS_ARRAY m_uiElements = { &m_modeText, &m_modeText_value, &m_scoreText, &m_scoreText_value,
														   &m_highScoreText, &m_highScoreText_value, &m_livesText , &m_livesText_value };
	
	ACTORS_VECTOR m_actors;

	void initializeUiContent();
	std::string numToText(int& num);
};

