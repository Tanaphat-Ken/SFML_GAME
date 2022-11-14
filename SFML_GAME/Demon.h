#ifndef DEMON_H
#define DEMON_H

#include "Entity.h"

class Demon :
	public Entity
{
private:
	int Move = 0;

	void initVariables();
	void initAnimations();

public:
	Demon(float x, float y, sf::Texture& texture_sheet);
	virtual ~Demon();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif