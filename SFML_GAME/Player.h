#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
	public Entity
{
private:
	//Variables

	//Init Functions
	void initVariables();
	void initComponents();
	int Move = 0;

public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	//Functions
	virtual void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif