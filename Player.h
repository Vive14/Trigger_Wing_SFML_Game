#pragma once

#include "sfmlAll.h"
#include "Bullet.h"

class Player
{
private:

	Sprite sprite;
	Texture Playertexture;
	vector <Player> player;
	vector<Bullet> bullets;

public:
	Player();

	//Accessors
	inline const Vector2f& getPosition()const { return this->sprite.getPosition(); }
	inline const Vector2f& getSize()const { return Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height); }
	inline const FloatRect getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	
	//Function
	void Movement();

	void update(float deltaTime);
	void render(RenderTarget& target);
};

