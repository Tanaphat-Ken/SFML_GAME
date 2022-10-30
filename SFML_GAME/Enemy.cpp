#include "Enemy.h"

bool Enemy::isOnScreen(int enemyPositionX)
{
	if (enemyPositionX > 1000) return false;
	else return true;
}

Enemy::Enemy()
{
	filename = "Resources/Images/Sprites/Enemy/goblin.png";
	enemyTexture.loadFromFile(filename);
	enemySprite.setTexture(enemyTexture);
	enemySprite.setPosition(50.f, static_cast<float>(rand() % 900));
	this->createMovementComponent(200.f, 15.f, 5.f);
	this->createAnimationComponent(enemyTexture);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 3, 0, 18, 30);
	//this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 4, 0, 7, 0, 18, 30);

}

Enemy::~Enemy()
{

}
//Function
void Enemy::update(const float& dt)
{
	for (int i = 0; i < enemy_size; i++) {
		enemies.at(i).move(sf::Vector2f (1.f, 0.f));
		if (!isOnScreen(enemies.at(i).getPosition().x)) 
		{
			enemies.erase(enemies.begin() + i);
			indexFrame.erase(indexFrame.begin() + i);
		}
	}
	this->movementComponents->update(dt);
	if (this->movementComponents->getState(IDLE))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if (this->movementComponents->getState(MOVING_RIGHT) || this->movementComponents->getState(MOVING_DOWN))
		this->animationComponent->play("IDLE_RIGHT", dt); //WALK_RIGHT
	/*else if (this->movementComponents->getState(MOVING_LEFT) || this->movementComponents->getState(MOVING_UP))
		this->animationComponent->play("WALK_LEFT", dt);*/

}

void Enemy::render(sf::RenderWindow& window)
{
	for (int i = 0; i < enemy_size; i++)
	{
		window.draw(enemies.at(i));
	}
}
