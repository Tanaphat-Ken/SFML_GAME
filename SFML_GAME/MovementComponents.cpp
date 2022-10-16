#include "MovementComponents.h"


MovementComponents::MovementComponents(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponents::~MovementComponents()
{

}
//accessor

const sf::Vector2f& MovementComponents::getVelocity() const
{
	return this->velocity;
}

//functions
const bool MovementComponents::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;
	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
			return true;
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
			return true;
		break;
	case MOVING_UP:
		if (this->velocity.y < 0.f)
			return true;
		break;
	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
			return true;
		break;
	}
	return false;
}


void MovementComponents::move(const float dir_x, const float dir_y,const float& dt)
{
	//acceleration

	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponents::update(const float& dt)
{
	//Dece,max velo,move

	if (this->velocity.x > 0.f) //check x +
	{
		//max velo check x +
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//dece x +
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f ;
	}
	else if (this->velocity.x < 0.f) // check x -
	{
		//max velo check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//dece
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if (this->velocity.y > 0.f) //check y +
	{
		//max velo check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//dece
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) // check y -
	{
		//max velo check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//dece
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//final
	this->sprite.move(this->velocity * dt); //use velo
}
