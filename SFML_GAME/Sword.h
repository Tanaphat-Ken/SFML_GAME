#ifndef SWORD_H
#define SWORD_H

#include "Entity.h"

class Sword :
	public Entity
{
private:
	sf::RenderWindow* window;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	Sword(sf::RenderWindow* window, float x, float y, sf::Texture& texture_sheet);
	virtual ~Sword();

	virtual void updateMousePos();
	virtual void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif