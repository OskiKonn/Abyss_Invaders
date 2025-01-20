#pragma once

#include <iostream>
#include <iterator>
#include "AbyssWorld.h"

AbyssWorld::AbyssWorld(const sf::Vector2u &winSizeRef, GameMode mode) : gameMode(mode), winSize(winSizeRef)
{
	initializeUiContent();
	uiElementsPtr = &m_uiElements;
	actorsPtr = &m_actors;
	bulletsPtr = &m_bullets;
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

void AbyssWorld::firePlayer()
{
	float cooldown = m_cooldownClock.getElapsedTime().asSeconds();

	if (cooldown > 0.8f)
	{
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
		m_bullets.push_back(bullet);
		player->shoot(bullet);
		m_cooldownClock.restart();
	}
}

void AbyssWorld::restartClocks()
{
	m_moveIntervalClock.restart();
	m_cooldownClock.restart();
	m_enemyShotCooldownClock.restart();
}

void AbyssWorld::update(float& deltaTime)
{

	float enemiesMoveCooldown = m_moveIntervalClock.getElapsedTime().asSeconds();
	float enemiesShotCoolDown = m_enemyShotCooldownClock.getElapsedTime().asSeconds();
	int numOfBullets = m_bullets.size();

	if (m_statusChanged)
		updateUiValues();

	if (numOfBullets > 0)
	{
		for (BULLETS_VECTOR::iterator it = m_bullets.begin(); it != m_bullets.end(); it++)
		{
			std::shared_ptr<Bullet> bullet = *it;
			sf::Vector2f moveVector = bullet->speed * deltaTime;
			bullet->body.move(moveVector);
			bool bulletOutOfRange = bullet->body.getPosition().y < static_cast<float>(winSize.y) * 0.15f
									|| bullet->body.getPosition().y > static_cast<float>(winSize.y) * 0.9f;

			bool bulletHit = checkForHit(bullet);
			
			if (bulletOutOfRange || bulletHit)
			{

				if (std::distance(it, m_bullets.end()) > 1)
				{
					it = m_bullets.erase(it);
				}
				else
				{
					m_bullets.erase(it);
					break;
				}
			}
		}
	}

	if (enemiesMoveCooldown > 2.0f)
	{
		moveEnemies();
		m_moveIntervalClock.restart();
	}

	if (enemiesShotCoolDown > 2.1f)
		fireEnemy();
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

	switch (gameMode)
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

void AbyssWorld::updateUiValues()
{
	std::string score = numToText(m_score);
	std::string lives = numToText(m_lives);

	m_scoreText_value.setString(score);
	m_livesText_value.setString(lives);
	
	m_statusChanged = false;
}

void AbyssWorld::spawnEnemies(GameMode& gameMode)
{
	for (size_t v = 0; v < 3; ++v)
	{
		for (size_t h = 0; h < static_cast<int>(gameMode); ++h)
		{

			std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(Enemy::EnemyType::Soldier);

			float winX = static_cast<float>(winSize.x);
			float winY = static_cast<float>(winSize.y);

			enemy->sprite.setPosition(winX * 0.4f + h * winX * 0.07f, winY * 0.27f - v * winY * 0.05f);
			enemy->sprite.setScale(0.06f, 0.06f);
			enemy->hp = 1;

			enemy->canShoot = (v == 0) ? true : false;

			m_actors.push_back(enemy);

		}
	}
}

void AbyssWorld::moveEnemies()
{
	static bool changeDirection;

	if (m_actors.size() > 1)
	{
		if (changeDirection)
		{
			for (ACTORS_VECTOR::iterator it = m_actors.begin() + 1; it != m_actors.end(); ++it)
			{
				std::shared_ptr<Actor> enemy = *it;
				enemy->goDown();
				changeDirection = false;
			}
		}
		else if (m_enemyMoveDirection == 'l')
		{
			for (ACTORS_VECTOR::iterator it = m_actors.begin() + 1; it != m_actors.end(); ++it)
			{
				std::shared_ptr<Actor> enemy = *it;
				enemy->goLeft(1);

				if (enemy->sprite.getPosition().x < 200.f)
				{
					changeDirection = true;
					m_enemyMoveDirection = 'r';
				}
			}
		}
		else if (m_enemyMoveDirection == 'r')
		{
			for (ACTORS_VECTOR::iterator it = m_actors.begin() + 1; it != m_actors.end(); ++it)
			{
				std::shared_ptr<Actor> enemy = *it;
				enemy->goRight(1);

				if (enemy->sprite.getPosition().x > 600.f)
				{
					changeDirection = true;
					m_enemyMoveDirection = 'l';
				}
			}
		}
	}
}

void AbyssWorld::fireEnemy()
{
	int numOfEnemies = m_actors.size() - 1;

	if (numOfEnemies < 1)
		return;

	int enemyIndex = 1 + ( rand() % numOfEnemies );
	std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(m_actors[enemyIndex]);

	if (enemy && enemy->canShoot)
	{
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(sf::Vector2f(0, -250.f));
		m_bullets.push_back(bullet);
		enemy->shoot(bullet);
		m_enemyShotCooldownClock.restart();
	}
}

bool AbyssWorld::checkForHit(std::shared_ptr<Bullet> bullet)
{
	for (ACTORS_VECTOR::iterator it = m_actors.begin(); it != m_actors.end(); ++it)
	{
		std::shared_ptr<Actor> actor = *it;
		sf::FloatRect actorHitbox = actor->getHitbox();
		bool hit = bullet->body.getGlobalBounds().intersects(actorHitbox);

		if (hit)
		{
			if (std::dynamic_pointer_cast<Player>(actor))
			{
				--m_lives;
				m_statusChanged = true;
			}

			actor->getDamage(1);
			std::cout << "\nHIT";

			if (actor->hp < 1)
			{
				kill(it);
			}

			return true;
		}
	}

	return false;

}

void AbyssWorld::kill(ACTORS_VECTOR::iterator &actor)
{
	std::shared_ptr<Player> isPlayer = std::dynamic_pointer_cast<Player>(*actor);

	if (!isPlayer)
	{
		int offset = static_cast<int>(gameMode);
		bool nextEnemy = std::distance(actor, m_actors.end()) > offset + 1;

		if (nextEnemy)
		{
			std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(*(actor + offset));
			enemy->canShoot = true;
		}
	}

	m_actors.erase(actor);
	++m_score;
	m_statusChanged = true;

	if (m_actors.size() < 2 || isPlayer)
	{
		std::cout << "\nGAME OVER";
		gameOver = true;
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
