#include "Goblin.h"

//Initializer functions
void Goblin::initVariables()
{

}

void Goblin::initAnimations()
{
	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 3, 0, 18, 30);
	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 4, 0, 7, 0, 18, 30);
}

void Goblin::initAI()
{

}

/*void Goblin::initGUI()
{
	this->hpBar.setFillColor(sf::Color::Red);
	this->hpBar.setSize(sf::Vector2f(60.f, 10.f));
	this->hpBar.setPosition(this->sprite.getPosition());
}*/

//Constructors / Destructors
Goblin::Goblin(float x, float y, sf::Texture& texture_sheet, Entity& player)
{
	this->initVariables();
	//this->initGUI();

	this->createHitboxComponent(this->sprite, 16.f, 23.f, 32.f, 32.f);
	this->createMovementComponent(100.f, 10.f, 5.f);
	this->createAnimationComponent(texture_sheet);
	//this->createAttributeComponent();

	this->setPosition(x, y);
	this->initAnimations();

	//this->follow = new AIFollow(*this, player);
}


Goblin::~Goblin()
{
	//delete this->follow;
}

void Goblin::updateAnimation(const float& dt)
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
	if (this->movementComponents->getState(IDLE))
	{
		if (Move == 1)
			this->animationComponent->play("IDLE_LEFT", dt);
		if (Move == 0)
			this->animationComponent->play("IDLE_RIGHT", dt);

	}
	else if (this->movementComponents->getState(MOVING_RIGHT))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if (this->movementComponents->getState(MOVING_LEFT))
		this->animationComponent->play("IDLE_LEFT", dt);
	else if (this->movementComponents->getState(MOVING_UP) || this->movementComponents->getState(MOVING_DOWN))
	{
		if (Move == 1)
			this->animationComponent->play("IDLE_LEFT", dt);
		if (Move == 0)
			this->animationComponent->play("IDLE_RIGHT", dt);
	}
	else
		this->sprite.setColor(sf::Color::White);
}

void Goblin::update(const float& dt)
{

	this->movementComponents->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	//this->follow->update(dt);
}

void Goblin::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitboxComponent->render(target);

	//target.draw(this->hpBar);
}
