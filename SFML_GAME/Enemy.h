#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :
	public Entity
{
private:

public:
	Enemy();
	virtual ~Enemy();

	//Functions
	virtual void loseHP(const int hp);
	virtual const bool isDead() const;

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

#endif
