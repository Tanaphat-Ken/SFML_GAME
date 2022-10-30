#include "GameStates.h"

void GameStates::initBackground()
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/GAME.jpg"))
	{
		throw"ERROR::GAMESTATES::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

}

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
	for (int i = 0; i < enemy_size; i++)
	{
		this->enemy[i] = new Enemy(rand() % 1000 - 1000, rand() % 950, this->textures["ENEMY_SHEET"]);
	}
	this->sword = new Sword(window, 924, 520, this->textures["SWORD"]);
}


//CON /DES
GameStates::GameStates(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window,states)
{
	this->initTextures();
	this->initEntity();
	this->initBackground();
}

GameStates::~GameStates()
{
	delete this->player;
	delete this->sword;
	for (int i = 0; i < enemy_size; i++)
	{
		delete this->enemy[i];
	}
}

void GameStates::updateInput(const float& dt)
{
	//update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f, dt);
	}
	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		this->sword->move(-10.f, 0.f, dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		this->sword->move(10.f, 0.f, dt);*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
	for (int i = 0; i < enemy_size; i++)
	{
		this->enemy[i]->move(1.f, 0.f, dt);
	}
	

	//MOVING ENEMY??
	/*if (this->player->getPostision() > this->enemy->getPostision())
	{

	}
	posplayer = player->getPostision();
	posenemy = enemy->getPostision();
	posplayer.x += 0.1 * (posplayer.x > posenemy.x) - 0.1 * (posplayer.x < posenemy.x);
	posenemy.y += 0.1 * (posplayer.y > posenemy.y) - 0.1 * (posplayer.y < posenemy.y);
	this->enemy->setPostision(posenemy.x, posenemy.y);*/
}

void GameStates::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);

	this->player->update(dt);
	this->sword->update(dt);
	for (int i = 0; i < enemy_size; i++)
	{
		this->enemy[i]->update(dt);
	}
	
}

void GameStates::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->player->render(target);	
	this->sword->render(target);
	for (int i = 0; i < enemy_size; i++)
	{
		this->enemy[i]->render(target);
	}
	
}
