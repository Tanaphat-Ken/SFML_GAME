#include "Sword.h"

Sword::Sword(sf::RenderWindow* window, float x, float y, sf::Texture& texture_sheet)
{
	this->window = window;
	this->setPosition(mousePosWindow.x, mousePosWindow.y);
	//this->createHitboxComponent(this->sprite, 0.f, 0.f, 18.f, 34.f);
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
	//this->hitboxComponent->update();
	this->updateMousePos();
	this->setPosition(mousePosWindow.x - 10, mousePosWindow.y - 15);
	this->animationComponent->play("IDLE", dt);
}

void Sword::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	//this->hitboxComponent->render(target);
}
