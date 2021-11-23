#include "Player.h"

Player::Player()
{
	Playertexture.loadFromFile("Textures/ship3.png");
	sprite.setTexture(this->Playertexture);
	sprite.scale(0.16f, 0.16f);
	sprite.setPosition(250.f, 800.f);
	sprite.setOrigin(Playertexture.getSize().x / 2, Playertexture.getSize().y / 2);
}

void Player::Movement()
{
	int right = 0, left = 0, top = 0, lower = 0;
	Vector2f CheckMap = getPosition(); 

	if (CheckMap.x > 560) right = 1;
	else right = 0;

	if (CheckMap.x < 43) left = 1;
	else left = 0;

	if (CheckMap.y < 50) top = 1;
	else top = 0;

	if (CheckMap.y > 950) lower = 1;
	else lower = 0;

	if (Keyboard::isKeyPressed(Keyboard::A) && left == 0)
		this->sprite.move(-4.8f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D) && right == 0)
		this->sprite.move(4.8f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::W) && top == 0)
		this->sprite.move(0.f, -4.8f);
	if (Keyboard::isKeyPressed(Keyboard::S) && lower == 0)
		this->sprite.move(0.f, 4.8f);
}


void Player::update(float deltaTime)
{
	this->Movement();
}

void Player::render(RenderTarget& target)
{
	target.draw(this->sprite);
}


