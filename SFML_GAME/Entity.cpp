#include "Entity.h"

void Entity::initVariables()
{
	this->movementComponents = NULL;
}

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movementComponents;
	delete this->animationComponent;
}

//component functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity , const float acceleration ,const float deceleration)
{
	this->movementComponents = new MovementComponents(this->sprite, maxVelocity , acceleration , deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

//Functions
void Entity::setPostision(const float x, const float y)
{
	this->sprite.setPosition(x,y);
}

void Entity::getPostision() const
{
	this->sprite.getPosition();
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponents)
	{
		this->movementComponents->move(dir_x,dir_y,dt); //set velo
	}
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
