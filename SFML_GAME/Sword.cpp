#include "Sword.h"

Sword::Sword(float x, float y, sf::Texture& texture_sheet)
{
	this->setPostision(x, y);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);
	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 0, 0, 6, 13);
}

Sword::~Sword()
{

}

void Sword::update(const float& dt)
{
	this->movementComponents->update(dt);
	this->animationComponent->play("IDLE_RIGHT", dt);
}
