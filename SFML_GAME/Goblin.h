#ifndef GOBLIN_H
#define GOBLIN_H

#include "Entity.h"

class Goblin :
	public Entity
{
private:
	int Move = 0;

	void initVariables();
	void initAnimations();

public:
	Goblin(float x, float y, sf::Texture& texture_sheet,Entity& player);
	virtual ~Goblin();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif

