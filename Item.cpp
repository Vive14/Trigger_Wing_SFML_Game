#include "Item.h"

Item::Item()
{
	this->itemSpeed = 100;
}

Item::Item(Texture* texture, Vector2f pos, Vector2f direction, float itemSpeed)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos);
	this->sprite.setScale(0.6f,0.6f);
	
	this->direction = direction;
	this->itemSpeed = itemSpeed;
}

void Item::update(float delTatime)
{
	this->sprite.move(direction* this->itemSpeed * delTatime);
}

void Item::render(RenderTarget* target)
{
	target->draw(sprite);
}
