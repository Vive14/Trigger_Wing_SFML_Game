#include "Enemy.h"

Enemy::Enemy(Vector2f setPosition, Texture& texture)
{
	this->enemySprite.scale(0.26f, 0.26f);
	this->enemySprite.setTexture(texture);
	this->enemySprite.setPosition(setPosition);

	this->enemyStart = true;
	this->enenyDead = false;
	this->hp = randnum(1, 3);
	this->itemRand = randnum(1, 20); 
	this->enemyRushSpeed = 300;

	areaSize = Vector2f(600.f - enemySprite.getGlobalBounds().width, 500.f - enemySprite.getGlobalBounds().height);
	moveEnPosition.x = rand() % int(areaSize.x);
	moveEnPosition.y = rand() % int(areaSize.y);
}

void Enemy::update(float delTatime, Texture* enemyBulletTexture, vector<Bullet>& bullets)
{
	if (enemyStart)
	{
		direction = safeArea(moveEnPosition - enemySprite.getPosition());
		enemySprite.move(direction * enemyRushSpeed * delTatime);
		if (moveEnPosition.x - enemySprite.getPosition().x <= 10 && moveEnPosition.y - enemySprite.getPosition().y <= 10)
		{
			Vector2f setBullet = (getSize() / 2.f) + Vector2f(0.f, -10.f);
			bullets.push_back(Bullet(enemyBulletTexture, enemySprite.getPosition() + setBullet, Vector2f(0.f, 1.f), 500.f, ENEMY_A));
			this->enemyStart = false;
		}
	}
	else
	{
		enemySprite.move(direction.x, 5);
	}
}

void Enemy::updateHp(Texture* itemShieldTexture, Texture* itemSpeedAttackTexture, vector<Item>& shields, vector<Item>& speedAttack)
{
	this->hp--;
	if (this->hp == 0 && this->itemRand % 5 == 0) // the occurrence of an item
	{
		shields.push_back(Item(itemShieldTexture, enemySprite.getPosition(), Vector2f(0.f, 1.f), 300.f));
	}

	if (this->hp == 0 && this->itemRand % 7 == 0)
	{
		speedAttack.push_back(Item(itemSpeedAttackTexture, enemySprite.getPosition(), Vector2f(0.f, 1.f), 300.f));
	}


}

void Enemy::render(RenderWindow* window)
{
	window->draw(this->enemySprite);
}
