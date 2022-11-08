#include "AttributeComponent.h"

AttributeComponent::AttributeComponent()
{
	this->updateStats(true);
}

AttributeComponent::~AttributeComponent()
{
}

void AttributeComponent::loseHP(const int hp)
{
	this->hp -= hp;

	if (this->hp < 0)
		this->hp = 0;
}

void AttributeComponent::gainHP(const int hp)
{

	this->hp += hp;

	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

const bool AttributeComponent::isDead() const
{
	return this->hp <= 0;
}

void AttributeComponent::updateStats(const bool reset)
{
	if (reset)
	{
		this->hp = this->hpMax;
	}
}
