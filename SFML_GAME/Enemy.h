#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :
	public Entity
{
private:
	std::string filename;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Vector2f enemyPosition;
	#define enemy_size 20;

	bool isOnScreen(int enemyPositionX);

public:
	std::vector<int> indexFrame;
	std::vector<sf::Sprite> enemies;
	Enemy();
	virtual ~Enemy();

	//Functions
	virtual void update(const float& dt);
	void render(sf::RenderWindow& window);
};

#endif
