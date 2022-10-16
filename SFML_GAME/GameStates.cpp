#include "GameStates.h"


void GameStates::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/wizard.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
	if (!this->textures["ENEMY_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/goblin.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_GOBLIN_TEXTURE";
	}
	if (!this->textures["SWORD"].loadFromFile("Resources/Images/Sprites/Player/sword2.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_SWORD_TEXTURE";
	}
}

void GameStates::initEntity()
{
	this->player = new Player(880, 480, this->textures["PLAYER_SHEET"]);
	this->enemy = new Enemy(rand() % 1800, rand() % 950, this->textures["ENEMY_SHEET"]);
	this->sword = new Sword(924, 520, this->textures["SWORD"]);
}

//CON /DES
GameStates::GameStates(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window,states)
{
	this->initTextures();
	this->initEntity();
}

GameStates::~GameStates()
{
	delete this->player;
	delete this->enemy;
	delete this->sword;
}

void GameStates::updateInput(const float& dt)
{
	//update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f, dt);
		this->sword->move(-1.f, 0.f, dt);
		this->enemy->move(1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f, dt);
		this->sword->move(1.f, 0.f, dt);
		this->enemy->move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f, dt);
		this->sword->move(0.f, -1.f, dt);
		this->enemy->move(0.f, 1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f, dt);
		this->sword->move(0.f, 1.f, dt);
		this->enemy->move(0.f, -1.f, dt);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		this->sword->move(-10.f, 0.f, dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		this->sword->move(10.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();	
}

void GameStates::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);

	this->player->update(dt);
	this->enemy->update(dt);
	this->sword->update(dt);
}

void GameStates::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->render(target);
	this->enemy->render(target);
	this->sword->render(target);
}
