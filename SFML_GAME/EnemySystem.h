#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "Entity.h"
#include "State.h"
#include "Goblin.h"
//#include "Bird1.h"

enum EnemyTypes { GOBLIN = 0, BIRD1 };

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies,
		std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	//Accessors

	//Modifiers

	//Functions
	void createEnemy(const short type, const float xPos, const float yPos);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif //!ENEMYSYSTEM_H

