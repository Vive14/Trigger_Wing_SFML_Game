#pragma once

#include "Player.h"
#include "Bullet.h"
#include "Item.h"

class Enemy
{
private:
	Sprite enemySprite;
	vector<Enemy> enemeies;
	Vector2f areaSize;
	Vector2f direction;
	Vector2f moveEnPosition;;

	bool enemyStart;
	bool enenyDead;

	int hp;
	int itemRand;

	float enemyRushSpeed;

public:
	Enemy(Vector2f spawnPosition, Texture& texture);

	//Accessors
	inline const Vector2f& getPosition()const { return this->enemySprite.getPosition(); }
	inline const Vector2f& getSize()const { return Vector2f(enemySprite.getGlobalBounds().width, enemySprite.getGlobalBounds().height); }
	inline const FloatRect getGlobalBounds()const { return this->enemySprite.getGlobalBounds(); }

	inline int getHp() { return hp; }
	inline int randnum(int start, int stop) { return rand() % (stop - start + 1) + start; }

	inline Vector2f safeArea(Vector2f vec) 
	{
		float sA = sqrtf(vec.x * vec.x + vec.y * vec.y);
		if (sA != 0) { return vec / sA; }
		return vec;
	}

	//Function 
	void update(float delTatime, Texture* enemyBulletTexture, vector<Bullet>& bullets);
	void updateHp(Texture* itemShieldTexture, Texture* itemSpeedAttackTexture,  vector<Item>& shields, vector<Item>& speedAttack);
	void render(RenderWindow* window);
};

