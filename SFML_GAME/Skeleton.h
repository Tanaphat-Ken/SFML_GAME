#ifndef SKELETON_H
#define SKELETON_H

#include "Entity.h"

class Skeleton :
	public Entity
{
private:
	int Move = 0;

	void initVariables();
	void initAnimations();

public:
	Skeleton(float x, float y, sf::Texture& texture_sheet);
	virtual ~Skeleton();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif