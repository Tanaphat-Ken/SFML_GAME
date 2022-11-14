#include "Demon.h"

//Initializer functions
void Demon::initVariables()
{

}

void Demon::initAnimations()
{
	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 3, 0, 34, 38);
	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 4, 0, 7, 0, 34, 38);
}

//Constructors / Destructors
Demon::Demon(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->createHitboxComponent(this->sprite, 16.f, 23.f, 32.f, 32.f);
	this->createMovementComponent(125.f, 10.f, 0.1f);
	this->createAnimationComponent(texture_sheet);

	this->setPosition(x, y);
	this->initAnimations();

}


Demon::~Demon()
{
}

void Demon::updateAnimation(const float& dt)
{
	if (this->movementComponents->getState(MOVING))
	{
		if (this->movementComponents->getState(MOVING_LEFT))
		{
			Move = 1;
		}
		else if (this->movementComponents->getState(MOVING_RIGHT))
		{
			Move = 0;
		}
	}
	if (Move == 1 || (this->movementComponents->getState(MOVING_UP) && Move == 1) || (this->movementComponents->getState(MOVING_DOWN) && Move == 1))
		this->animationComponent->play("IDLE_LEFT", dt);
	else if (Move == 0 || (this->movementComponents->getState(MOVING_UP) && Move == 0) || (this->movementComponents->getState(MOVING_DOWN) && Move == 0))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else
		this->sprite.setColor(sf::Color::White);
}

void Demon::update(const float& dt)
{

	this->movementComponents->update(dt);

	this->hitboxComponent->update();

	this->updateAnimation(dt);

}

void Demon::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitboxComponent->render(target);
}
