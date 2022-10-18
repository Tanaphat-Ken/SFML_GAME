#include "Sword.h"

Sword::Sword(float x, float y, sf::Texture& texture_sheet)
{
	this->setPostision(mousePosScreen.x, mousePosScreen.y);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 0, 0, 6, 13);
}

Sword::~Sword()
{

}

void Sword::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
}

void Sword::update(const float& dt)
{
	this->updateMousePos();
	this->setPostision(mousePosScreen.x-17, mousePosScreen.y-45);
	this->movementComponents->update(dt);
	this->animationComponent->play("IDLE", dt);
}
