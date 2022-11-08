#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{

}

void Enemy::loseHP(const int hp)
{
	if (this->attributeComponent)
	{
		this->attributeComponent->loseHP(hp);
	}
}

const bool Enemy::isDead() const
{
	if (this->attributeComponent)
	{
		return this->attributeComponent->isDead();
	}

	return false;
}

//Function
void Enemy::update(const float& dt)
{
}

void Enemy::render(sf::RenderTarget& target)
{
}
