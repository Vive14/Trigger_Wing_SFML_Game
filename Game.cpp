#include "Game.h"


Game::Game(RenderWindow* window)
{
	this->window = window;

	//init textures
	this->bulletTexture.loadFromFile("Textures/bullet2.png");
	this->enemyTexture.loadFromFile("Textures/Enemy2.1.png");
	this->enemyBulletTexture.loadFromFile("Textures/enemybullet4.png");

	//score
	score = 0;
	font.loadFromFile("Fonts/Rockstar-ExtraBold.otf");
	textScore.setFont(font);
	textScore.setFillColor(Color::White);
	textScore.setCharacterSize(30);
	textScore.setPosition(Vector2f(20, 20));
	textScore.setString("Score " + to_string(score));

	//map
	map.loadFromFile("Textures/map1.png");
	showMap.setTexture(map);

	//item
	itemSpeedAttackTexture.loadFromFile("Textures/itemSpeed.png"); ////
	itemShieldTexture.loadFromFile("Textures/item_shield1.png");
	shieldTexture.loadFromFile("Textures/shield2.1.png");
	showShield.setTexture(shieldTexture);

	shileldOn = false;
	speedAttackOn = false;

	showShield.setOrigin(shieldTexture.getSize().x / 2 , shieldTexture.getSize().y / 2);



	this->shootCooldownMax = 0.3;
	this->shootCooldown = shootCooldownMax;

	this->itemCooldownMax = 4; 
	this->itemCooldown = 0;

	this->enemyCooldownMax = 8;
	this->enemyCooldown = 0;

	this->enemyCooldownLimit = 0;

	isAlive = 1;

	for (size_t i = 0; i < 2; i++)
	{
		enemies.push_back(Enemy(Vector2f(rand() % SCREEN_WIDTH, -150), enemyTexture));
	}
}

Game::~Game()
{

}

void Game::Update(float deltaTime)
{
	player.update(deltaTime);
	showShield.setPosition(player.getPosition());
	shootCooldown += deltaTime;

	if (speedAttackOn)
	{
		shootCooldownMax = 0.1;
		this->itemCooldown += deltaTime;
		if (this->itemCooldown >= this->itemCooldownMax)
		{
			this->itemCooldown = 0;
			this->speedAttackOn = false;
		}
	}
	else
	{
		this -> shootCooldownMax = 0.3;
	}

	if (this->enemyCooldown >= this->enemyCooldownMax && this->enemyCooldownLimit <= 7)
	{
		this->enemyCooldownLimit++;
		this->enemyCooldown = 0;
		enemies.push_back(Enemy(Vector2f(rand() % SCREEN_WIDTH, -150), enemyTexture));
	}
	else
	{
		this->enemyCooldown += deltaTime;
	}

	if (Keyboard::isKeyPressed(Keyboard::P) && this->shootCooldown >= this->shootCooldownMax)
	{
		shootCooldown = 0;
		Vector2f setBullet = Vector2f(-4.f, 0.f);
		bullets.push_back(Bullet(&bulletTexture, player.getPosition() + setBullet , Vector2f(0.f, -1.f), 1000.f));
	}

	//update bullet
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).update(deltaTime);
		if (player.getGlobalBounds().intersects(bullets[i].getGlobalBoubds()) && bullets[i].tag == ENEMY_A)
		{
			if (shileldOn)
			{
				bullets.erase(bullets.begin() + i);
				shileldOn = false;
			}
			else
			{
				isAlive = 0;
			}
		}

	}

	//update enemy
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).update(deltaTime, &enemyBulletTexture, bullets);
		for (size_t j = 0; j < bullets.size(); j++)
		{
			if (bullets[j].getGlobalBoubds().intersects(enemies[i].getGlobalBounds()) && enemies.at(i).getHp() > 0 && bullets[j].tag != ENEMY_A )
			{
				bullets.erase(bullets.begin() +j);
				enemies[i].updateHp(&itemShieldTexture, &itemSpeedAttackTexture, shields, speedAttack); ///

				if (enemies.at(i).getHp() == 0)
				{
					enemies.erase(enemies.begin() + i);
					enemies.push_back(Enemy(Vector2f(rand() % SCREEN_WIDTH, -100), enemyTexture));
					score += 50;
					textScore.setString("Score " + to_string(score));
				}
				break;
			}
		}
		if (enemies[i].getPosition().y > 1100)   /// moving enemies fall off the screen
		{
			enemies.erase(enemies.begin() + i);
			enemies.push_back(Enemy(Vector2f(rand() % SCREEN_WIDTH, -100), enemyTexture));
		}
	}
	
	//update itemShield
	for (size_t i = 0; i < shields.size(); i++)
	{
		shields.at(i).update(deltaTime);
		if (player.getGlobalBounds().intersects(shields[i].getGlobalBoubds())) //การเก็บไอเท็ม
		{
			shields.erase(shields.begin() + i);
			shileldOn = true;
		}
	}

	//update itemSpeedAttackTexture
	for (size_t i = 0; i < speedAttack.size(); i++) ////
	{
		speedAttack.at(i).update(deltaTime);
		if (player.getGlobalBounds().intersects(speedAttack[i].getGlobalBoubds()))
		{
			speedAttack.erase(speedAttack.begin() + i);
			speedAttackOn = true;
		}
	}

}

bool Game::checkAlive()
{
	return isAlive;
}

int Game::getScore()
{
	return this->score;
}

void Game::setName(string name)
{
	this->name = name;
	nameText.setString(name);
}

string Game::getName()
{
	return this->name;
}


void Game::reset()
{
	score = 0;
	isAlive = 1;
	players.clear();
	enemies.clear();
	bullets.clear();
	shields.clear();
	speedAttack.clear();
}


void Game::render()
{
	window->draw(showMap);

	//render bullet
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).render(*window);
	}

	//render enemy
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).render(window);
	}

	//render shield
	for (size_t i = 0; i < shields.size(); i++)
	{
		shields.at(i).render(window);
	}

	for (size_t i = 0; i < speedAttack.size(); i++) 
	{
		speedAttack.at(i).render(window);
	}

	if (shileldOn)
	{
		window->draw(showShield);
	}
	
	this->player.render(*window);

	window->draw(textScore);

}

