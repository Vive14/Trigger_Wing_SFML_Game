#pragma once

#include "sfmlAll.h"

class Item
{
private:
	Sprite sprite;
	
	Vector2f direction;

	float itemSpeed;

public:
	Item();
	Item(Texture* texture, Vector2f pos, Vector2f dir, float itemSpeed);


	//Accessors
	inline const FloatRect getGlobalBoubds()const { return this->sprite.getGlobalBounds(); }

	void update(float deltaTime);
	void render(RenderTarget* target);
};

