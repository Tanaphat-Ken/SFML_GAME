#include "Enemy.h"

Enemy::Enemy(float x, float y, sf::Texture& texture_sheet)
{
	this->setPosition(x, y);
	this->createHitboxComponent(this->sprite, 16.f, 23.f, 32.f, 32.f);
	this->createMovementComponent(200.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 3, 0, 18, 30);
	//this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 4, 0, 7, 0, 18, 30);

}

Enemy::~Enemy()
{

}
//Function
void Enemy::update(const float& dt)
{
	this->hitboxComponent->update();

	this->movementComponents->update(dt);
	if (this->movementComponents->getState(IDLE))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if (this->movementComponents->getState(MOVING_RIGHT) || this->movementComponents->getState(MOVING_DOWN))
		this->animationComponent->play("IDLE_RIGHT", dt); //WALK_RIGHT
	/*else if (this->movementComponents->getState(MOVING_LEFT) || this->movementComponents->getState(MOVING_UP))
		this->animationComponent->play("IDLE_LEFT", dt); //WALK_LEFT*/

}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitboxComponent->render(target);
}
