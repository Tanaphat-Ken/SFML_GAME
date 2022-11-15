#ifndef IMP_H
#define IMP_H

#include "Entity.h"

class Imp :
	public Entity
{
private:
	int Move = 0;

	void initVariables();
	void initAnimations();

public:
	Imp(float x, float y, sf::Texture& texture_sheet);
	virtual ~Imp();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif