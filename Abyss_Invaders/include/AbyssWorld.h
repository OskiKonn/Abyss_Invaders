#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <vector>
#include <string>
#include "Player.h"
#include "Actor.h"
#include "Enemy.h"
#include "Bullet.h"
#include <SFML/System/Clock.hpp>

const int UI_ELEMENTS_NUM = 8;

typedef std::array<sf::Text*, UI_ELEMENTS_NUM> UI_ELEMENTS_ARRAY;
typedef std::vector<std::shared_ptr<Actor>> ACTORS_VECTOR;
typedef std::vector<std::shared_ptr<Bullet>> BULLETS_VECTOR;

class AbyssWorld
{
public:
	enum class GameMode { Easy = 3, Medium = 4, Hard = 5 };

	AbyssWorld(const sf::Vector2u &winSizeRef, GameMode mode = GameMode::Easy);
	~AbyssWorld() = default;

	void test();
	void moveLeft(float& deltaTime);
	void moveRight(float& deltaTime);
	void firePlayer();
	void restartClocks();
	void update(float& deltaTime);
	
	UI_ELEMENTS_ARRAY  *uiElementsPtr;
	ACTORS_VECTOR *actorsPtr;
	BULLETS_VECTOR *bulletsPtr;
	GameMode gameMode;
	bool gameOver = false;
	bool paused = false;

private:

	int m_score = 0;
	int m_lives = 3;
	int m_highScore = 0;
	char m_enemyMoveDirection = 'l';
	bool m_statusChanged = false;

	const sf::Vector2u &winSize;

	std::shared_ptr<Player> player;
	std::shared_ptr<Player> spawnPlayer();

	sf::Font m_font;
	sf::Text m_modeText;
	sf::Text m_scoreText;
	sf::Text m_highScoreText;
	sf::Text m_livesText;

	sf::Text m_modeText_value;
	sf::Text m_scoreText_value;
	sf::Text m_highScoreText_value;
	sf::Text m_livesText_value;

	sf::Clock m_cooldownClock;
	sf::Clock m_moveIntervalClock;
	sf::Clock m_enemyShotCooldownClock;

	UI_ELEMENTS_ARRAY m_uiElements = { &m_modeText, &m_modeText_value, &m_scoreText, &m_scoreText_value,
														   &m_highScoreText, &m_highScoreText_value, &m_livesText , &m_livesText_value };
	
	ACTORS_VECTOR m_actors;
	BULLETS_VECTOR m_bullets;

	void initializeUiContent();
	void updateUiValues();
	void spawnEnemies(GameMode& gameMode);
	void moveEnemies();
	void fireEnemy();
	bool checkForHit(std::shared_ptr<Bullet> bullet);
	void kill(ACTORS_VECTOR::iterator &actor);
	std::string numToText(int& num);
};

