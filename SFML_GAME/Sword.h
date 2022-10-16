#ifndef SWORD_H
#define SWORD_H

#include "Entity.h"

class Sword :
	public Entity
{
private:


public:
	Sword(float x, float y, sf::Texture& texture_sheet);
	virtual ~Sword();

	virtual void update(const float& dt);

};

#endif