#pragma once
#include "sfmlAll.h"

#define PLARYER_A 0
#define ENEMY_A 1

class Bullet
{
private:
	Sprite sprite;
	Vector2f direction;

	float bulletSpeed;

public:
	int tag;
	bool died;

	Bullet();
	Bullet(Texture* texture, Vector2f pos, Vector2f dir, float bulletSpeed, int tag = PLARYER_A);
	virtual ~Bullet();

	//Accessors
	inline const FloatRect getGlobalBoubds()const { return this->sprite.getGlobalBounds(); }

	void update(float deltaTime);
	void render(RenderTarget &target);

};

