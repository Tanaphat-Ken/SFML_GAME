#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponents.h"
#include "AnimationComponent.h"

class Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;
	
	MovementComponents* movementComponents;
	AnimationComponent* animationComponent;

public:
	Entity();
	virtual ~Entity();

	//component functions
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	//Functions
	virtual void setPostision(const float x, const float y);
	virtual void move(const float x, const float y, const float& dt);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif

