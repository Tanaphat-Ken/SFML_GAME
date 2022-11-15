#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Entity.h"

class Zombie :
	public Entity
{
private:
	int Move = 0;

	void initVariables();
	void initAnimations();

public:
	Zombie(float x, float y, sf::Texture& texture_sheet);
	virtual ~Zombie();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif