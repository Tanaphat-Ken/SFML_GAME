#include "Sword.h"

Sword::Sword(sf::RenderWindow* window, float x, float y, sf::Texture& texture_sheet)
{
	this->window = window;
	this->setPostision(mousePosWindow.x, mousePosWindow.y);
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
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Sword::update(const float& dt)
{
	this->updateMousePos();
	this->setPostision(mousePosWindow.x-10, mousePosWindow.y-15);
	this->movementComponents->update(dt);
	this->animationComponent->play("IDLE", dt);
}
