#pragma once

#include "Item.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "sfmlAll.h"
#include "ScoreBoard.h"
#include "enterNameText.h"


class Game 
{
private:

	RenderWindow* window;

	//score
	int score;
	Font font;
	Text textScore;

	//Player
	string name;
	Text nameText;
	Player player;
	vector<Player> players;

	//bullet
	Texture bulletTexture;
	vector<Bullet> bullets;

	//enemy
	Texture enemyTexture;
	Texture enemyBulletTexture;
	vector<Enemy> enemies;

	//map
	Sprite showMap;
	Texture map;

	//item
	Item item;
	Sprite showShield;
	Texture shieldTexture;
	Texture itemShieldTexture;
	vector<Item> shields;

	Texture itemSpeedAttackTexture;
	vector<Item> speedAttack;


	//check 
	bool isAlive;
	bool shileldOn;
	bool speedAttackOn; 

	float shootCooldown;
	float shootCooldownMax;

	float itemCooldown;
	float itemCooldownMax;

	float enemyCooldown;
	float enemyCooldownMax;
	float enemyCooldownLimit;
	
	

public:
	Game(RenderWindow* window);
	virtual ~Game();

	//function
	void Update(float deltaTime);

	bool checkAlive();

	int getScore();

	void setName(string name);

	string getName();

	void reset();

	void render();
};

