#include "EnemySystem.h"

EnemySystem::EnemySystem(std::vector<Enemy*>& activeEnemies,
	std::map<std::string, sf::Texture>& textures, Entity& player)
	: textures(textures), activeEnemies(activeEnemies), player(player)
{

}

EnemySystem::~EnemySystem()
{

}

void EnemySystem::createEnemy(const short type, const float xPos, const float yPos)
{
	switch (type)
	{
	case EnemyTypes::GOBLIN:
		//BUGGED PUSH_BACK?????
		//this->activeEnemies.push_back(new Goblin(xPos, yPos, this->textures["GOBLIN_SHEET"], this->player));
		break;
	/*case EnemyTypes::BIRD1:
		this->activeEnemies.push_back(new Bird1(xPos, yPos, this->textures["BIRD1_SHEET"], enemy_spawner_tile, this->player));
		enemy_spawner_tile.increaseEnemyCounter();
		break;*/
	default:
		std::cout << "ERROR::ENEMYSYSTEM::CREATEENEMY::TYPE DOES NOT EXIST" << "\n";
		break;
	}
}

void EnemySystem::removeEnemy(const int index)
{
	delete this->activeEnemies[index];
	this->activeEnemies.erase(this->activeEnemies.begin() + index);
}

void EnemySystem::update(const float& dt)
{

}

void EnemySystem::render(sf::RenderTarget* target)
{

}
