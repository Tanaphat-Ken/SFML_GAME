#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();
	void initAI();
	//void initGUI();

	//sf::RectangleShape hpBar;

public:
	Goblin(float x, float y, sf::Texture& texture_sheet,Entity& player);
	virtual ~Goblin();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget& target);
};

#endif

