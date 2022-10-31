#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :
	public Entity
{
private:

public:
	Enemy(float x, float y, sf::Texture& texture_sheet);
	virtual ~Enemy();

	//Functions
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

#endif
