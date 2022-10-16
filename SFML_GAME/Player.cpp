#include "Player.h"
//init functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//CON / DES
Player::Player(float x,float y,sf::Texture& texture_sheet)
{
	//this->initVariables();

	this->setPostision(x, y);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 3, 0, 18, 30);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 8, 0, 11, 0, 18, 30);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 4, 0, 7, 0, 18, 30);
}

Player::~Player()
{

}

//Function
void Player::update(const float& dt)
{
	this->movementComponents->update(dt);

	if(this->movementComponents->getState(IDLE))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if(this->movementComponents->getState(MOVING_RIGHT) || (this->movementComponents->getState(MOVING_RIGHT) && this->movementComponents->getState(MOVING_UP)) || (this->movementComponents->getState(MOVING_RIGHT) && this->movementComponents->getState(MOVING_DOWN)))
		this->animationComponent->play("WALK_RIGHT", dt);
	else if(this->movementComponents->getState(MOVING_LEFT) || (this->movementComponents->getState(MOVING_LEFT) && this->movementComponents->getState(MOVING_UP)) || (this->movementComponents->getState(MOVING_LEFT) && this->movementComponents->getState(MOVING_DOWN)))
		this->animationComponent->play("WALK_LEFT", dt);
	else if(this->movementComponents->getState(MOVING_UP))
		this->animationComponent->play("WALK_RIGHT", dt);
	else if (this->movementComponents->getState(MOVING_DOWN))
		this->animationComponent->play("WALK_LEFT", dt);

}
