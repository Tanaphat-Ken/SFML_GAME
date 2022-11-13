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

void GameStates::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Superstar M54.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameStates::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/wizard.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
	if (!this->textures["GOBLIN_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/goblin.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_GOBLIN_TEXTURE";
	}
	if (!this->textures["SWORD"].loadFromFile("Resources/Images/Sprites/Player/sword2.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_SWORD_TEXTURE";
	}
}

void GameStates::initPauseMenu()
{
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->pmenu->addButton("RESUME", 300.f, "RESUME");
	this->pmenu->addButton("QUIT", 500.f, "QUIT");
}

void GameStates::initEntity()
{
	this->player = new Player(880, 480, this->textures["PLAYER_SHEET"]);
	for (int i = 0; i < goblin_size; i++)
	{
		this->goblin[i] = new Goblin(rand() % 1920, rand() % 950, this->textures["GOBLIN_SHEET"], *this->player);
	}
	this->sword = new Sword(window, 924, 520, this->textures["SWORD"]);
}


//CON /DES
GameStates::GameStates(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window,states)
{
	this->initTextures();
	this->initFonts();
	this->initEntity();
	this->initPauseMenu();
	this->initBackground();
}

GameStates::~GameStates()
{
	delete this->pmenu;
	delete this->player;
	delete this->sword;
	for (int i = 0; i < goblin_size; i++)
	{
		delete this->goblin[i];
	}
}

void GameStates::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeytime())
	{
		if (!this->Pause)
		{
			window->setMouseCursorVisible(true);
			this->pauseState();
		}
		else
		{
			window->setMouseCursorVisible(false);
			this->unpauseState();
		}
	}
}

void GameStates::updatePlayerInput(const float& dt)
{
	//update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if(this->player->getPosition().x < 30)
			this->player->move(1.f, 0.f, dt);
		else
			this->player->move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->player->getPosition().x > 1850)
			this->player->move(-1.f, 0.f, dt);
		else
			this->player->move(1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (this->player->getPosition().y < 60)
			this->player->move(0.f, 1.f, dt);
		else
			this->player->move(0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (this->player->getPosition().y > 970)
			this->player->move(0.f, -1.f, dt);
		else
			this->player->move(0.f, 1.f, dt);
	}

	//MOVING ENEMY
	posplayer = player->getPosition();
	for (int i = 0; i < goblin_size; i++)
	{
		posenemy = this->goblin[i]->getPosition();
		if (posenemy.x > posplayer.x)
		{
			this->goblin[i]->move(-1.f, 0.f, dt);
			if (posenemy.y > posplayer.y)
				this->goblin[i]->move(0.f, -1.f, dt);
			else if (posenemy.y < posplayer.y)
				this->goblin[i]->move(0.f, 1.f, dt);
		}
		else if (posenemy.x < posplayer.x)
		{
			this->goblin[i]->move(1.f, 0.f, dt);
			if (posenemy.y > posplayer.y)
				this->goblin[i]->move(0.f, -1.f, dt);
			else if (posenemy.y < posplayer.y)
				this->goblin[i]->move(0.f, 1.f, dt);
		}
		else if (posenemy.y < posplayer.y)
			this->goblin[i]->move(0.f, 1.f, dt);
		else if (posenemy.y > posplayer.y)
			this->goblin[i]->move(0.f, -1.f, dt);

	}
}

void GameStates::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("RESUME"))
	{
		window->setMouseCursorVisible(false);
		this->unpauseState();
	}
	if (this->pmenu->isButtonPressed("QUIT"))
	{
		window->setMouseCursorVisible(true);
		this->endState();
	}
}

void GameStates::update(const float& dt)
{
	this->updateMousePos();
	this->updateKeytime(dt);
	this->updateInput(dt);

	if(!this->Pause) //unpause
	{
		this->updatePlayerInput(dt);
		this->player->update(dt);
		this->sword->update(dt);
		for (int i = 0; i < goblin_size; i++)
		{
			this->goblin[i]->update(dt);
			if (this->goblin[i]->getGlobalBounds().intersects(this->player->getGlobalBounds()))
			{
				this->goblin[i]->setPosition(rand() % 1920, rand() % 950);
				playerHP--;
				if (playerHP == 0)
				{
					this->endState();
				}
			}
			if (this->goblin[i]->getGlobalBounds().intersects(this->sword->getGlobalBounds()))
			{
				this->goblin[i]->setPosition(rand() % 1920, rand() % 950);
				score++;
			}
		}
	}
	else //pause
	{
		this->pmenu->update(this->mousePosView);
		this->updatePauseMenuButtons();
	}
	
}

void GameStates::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->player->render(*target);
	this->sword->render(*target);

	for (int i = 0; i < goblin_size; i++)
	{
		this->goblin[i]->render(*target);
	}
	if (this->Pause) //pauseMenu render
	{
		this->pmenu->render(*target);
	}
}

