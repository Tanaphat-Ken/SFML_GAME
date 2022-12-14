#include "Player.h"

//CON / DES
Player::Player(float x,float y,sf::Texture& texture_sheet)
{
	this->createHitboxComponent(this->sprite, 7.f, 30.f, 38.f, 60.f);
	this->setPosition(x, y);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 4, 0, 7, 0, 18, 30);
	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 3, 0, 18, 30);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 12, 0, 15, 0, 18, 30);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 8, 0, 11, 0, 18, 30);
}

Player::~Player()
{

}

//Function
void Player::update(const float& dt)
{
	this->movementComponents->update(dt);

	this->hitboxComponent->update();

	if (this->movementComponents->getState(MOVING))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Move = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Move = 0;
		}
	}
	if(this->movementComponents->getState(IDLE))
	{
		if (Move == 1)
			this->animationComponent->play("IDLE_LEFT", dt);
		if (Move == 0)
			this->animationComponent->play("IDLE_RIGHT", dt);

	}
	else if(this->movementComponents->getState(MOVING_RIGHT))
		this->animationComponent->play("WALK_RIGHT", dt);
	else if(this->movementComponents->getState(MOVING_LEFT))
		this->animationComponent->play("WALK_LEFT", dt);
	else if(this->movementComponents->getState(MOVING_UP) || this->movementComponents->getState(MOVING_DOWN))
	{
		if (Move == 1)
			this->animationComponent->play("WALK_LEFT", dt);
		if (Move == 0)
			this->animationComponent->play("WALK_RIGHT", dt);
	}
	else
		this->sprite.setColor(sf::Color::White);

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitboxComponent->render(target);
}
