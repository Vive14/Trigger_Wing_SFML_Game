#include "Bullet.h"

Bullet::Bullet()
{
	tag = PLARYER_A;
	this->died = false;
	this->bulletSpeed = 1000;
}

Bullet::Bullet(Texture* texture, Vector2f pos, Vector2f dir, float bulletSpeed, int tag)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos);
	this->sprite.setScale(0.8f, 0.8f);

	this->direction = dir;
	this->bulletSpeed = bulletSpeed;
	this->tag = tag;
	this->died = false;

}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	//movement
	this->sprite.move(this->direction * this->bulletSpeed * deltaTime);
}

void Bullet::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
