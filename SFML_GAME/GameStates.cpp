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
	if (!this->textures["GOBLIN_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/Goblin/goblin.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_GOBLIN_TEXTURE";
	}
	if (!this->textures["SWORD"].loadFromFile("Resources/Images/Sprites/Player/sword2.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_SWORD_TEXTURE";
	}
	if (!this->textures["DEMON_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/Demon/Demon.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_DEMON_TEXTURE";
	}
	if (!this->textures["SKELETON_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/Skeleton/Skeleton.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_SKELETON_TEXTURE";
	}
	if (!this->textures["ZOMBIE_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/Zombie/Zombie.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_ZOMBIE_TEXTURE";
	}
	if (!this->textures["IMP_SHEET"].loadFromFile("Resources/Images/Sprites/Enemy/Imp/Imp.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_IMP_TEXTURE";
	}
	
}

void GameStates::initSound()
{
	if (!this->music["GAME_MUSIC"].openFromFile("Resources/Sound/Music/2018-08-02-17971.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_GAME_MUSIC";
	}
	this->music["GAME_MUSIC"].setVolume(10);
	this->music["GAME_MUSIC"].play();
	this->music["GAME_MUSIC"].setLoop(true);
	if (!this->sounds["MONSTER_DEAD"].loadFromFile("Resources/Sound/Sound Effect/zombie-death-2-95167.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_MONSTER_DEAD";
	}
	monster_dead.setBuffer(this->sounds["MONSTER_DEAD"]);
	monster_dead.setVolume(8);

	if (!this->sounds["IMMORTALITY"].loadFromFile("Resources/Sound/Sound Effect/IMMORTALITY.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_IMMORTALITY";
	}
	Immortality_effect.setBuffer(this->sounds["IMMORTALITY"]);
	Immortality_effect.setVolume(10);

	if (!this->sounds["DEAD"].loadFromFile("Resources/Sound/Sound Effect/075609_robotic-voice-39now-you-are-dead39-hd-80275.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_DEAD";
	}
	player_dead.setBuffer(this->sounds["DEAD"]);
	player_dead.setVolume(10);

	if (!this->sounds["HEAL"].loadFromFile("Resources/Sound/Sound Effect/heal-up-39285.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HEAL";
	}
	heal.setBuffer(this->sounds["HEAL"]);
	heal.setVolume(10);

	if (!this->sounds["HURT"].loadFromFile("Resources/Sound/Sound Effect/ough.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HURT";
	}
	player_hurt.setBuffer(this->sounds["HURT"]);
	player_hurt.setVolume(12);
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
		this->goblin[i] = new Goblin(rand() % 1920, rand() % 950, this->textures["GOBLIN_SHEET"]);
	}
	this->sword = new Sword(window, 924, 520, this->textures["SWORD"]);
	this->demon = new Demon(rand() % 1920, rand() % 950, this->textures["DEMON_SHEET"]);

	//TEST FOR MORE ENEMY
	for (int i = 0; i < zombie_size; i++)
	{
		this->zombie[i] = new Zombie(rand() % 1920, rand() % 950, this->textures["ZOMBIE_SHEET"]);
	}
	for (int i = 0; i < skeleton_size; i++)
	{
		this->skeleton[i] = new Skeleton(rand() % 50 - 150, rand() % 1080, this->textures["SKELETON_SHEET"]);
	}
	for (int i = 0; i < imp_size; i++)
	{
		this->imp[i] = new Imp(rand() % 50 - 150, rand() % 950, this->textures["IMP_SHEET"]);
	}

}

void GameStates::initHpBar()
{
	this->hpHidBar.setSize(sf::Vector2f(960.f, 20.f));
	this->hpHidBar.setFillColor(sf::Color::Red);
	this->hpHidBar.setPosition(480.f, 20.f);

	this->hpShowBar.setSize(sf::Vector2f(960.f, 20.f));
	this->hpShowBar.setFillColor(sf::Color::Green);
	this->hpShowBar.setPosition(this->hpHidBar.getPosition());
}

void GameStates::initText()
{
	ss1 << score;
	current_score.setString(ss1.str());
	current_score.setFont(font);
	current_score.setOrigin(current_score.getGlobalBounds().width / 2, current_score.getGlobalBounds().height / 2);
	current_score.setCharacterSize(50);
	current_score.setPosition(20, 20);

	ss2 << Time;
	current_time.setString(ss2.str());
	current_time.setFont(font);
	current_time.setOrigin(current_time.getGlobalBounds().width / 2, current_time.getGlobalBounds().height / 2);
	current_time.setCharacterSize(50);
	current_time.setPosition(1700, 20);
}

//CON /DES
GameStates::GameStates(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window,states)
{
	this->initTextures();
	this->initSound();
	this->initFonts();
	this->initEntity();
	this->initPauseMenu();
	this->initBackground();
	this->initHpBar();
	this->initText();
}

GameStates::~GameStates()
{
	delete this->pmenu;
	delete this->player;
	delete this->sword;
	delete this->demon;
	for (int i = 0; i < goblin_size; i++)
	{
		delete this->goblin[i];
	}

	//TEST FOR MORE ENEMY
	if (Clock.getElapsedTime().asSeconds() > 150)
	{
		for (int i = 0; i < zombie_size; i++)
		{
			delete this->zombie[i];
		}
	}
	if (Clock.getElapsedTime().asSeconds() > 45)
	{
		for (int i = 0; i < skeleton_size; i++)
		{
			delete this->skeleton[i];
		}
	}
	if (Clock.getElapsedTime().asSeconds() > 85)
	{
		for (int i = 0; i < imp_size; i++)
		{
			delete this->imp[i];
		}
	}
}

void GameStates::updateText(int score,float Time)
{
	current_score.setString(std::to_string(score));
	current_time.setString(std::to_string(Time));
	if (immortality == 1)
	{
		current_buff.setString("IMMORTALITY");
		current_buff.setFont(font);
		current_buff.setOrigin(current_time.getGlobalBounds().width / 2, current_time.getGlobalBounds().height / 2);
		current_buff.setCharacterSize(100);
		current_buff.setPosition(750, 60);
		current_buff.setFillColor(sf::Color(250, 0, 0, 250));
	}
	else
		current_buff.setFillColor(sf::Color(0, 0, 0, 0));
}

void GameStates::updateHpBar()
{
	this->hpShowBar.setSize(sf::Vector2f(playerHP*960.f/playerMaxHP, 20.f));
	this->hpShowBar.setFillColor(sf::Color::Green);
	this->hpShowBar.setPosition(this->hpHidBar.getPosition());
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
	if (Clock.getElapsedTime().asSeconds() > 10)
	{
		posenemy = this->demon->getPosition();
		if (posenemy.x > posplayer.x)
		{
			this->demon->move(-1.f, 0.f, dt);
			if (posenemy.y > posplayer.y)
				this->demon->move(0.f, -1.f, dt);
			else if (posenemy.y < posplayer.y)
				this->demon->move(0.f, 1.f, dt);
		}
		else if (posenemy.x < posplayer.x)
		{
			this->demon->move(1.f, 0.f, dt);
			if (posenemy.y > posplayer.y)
				this->demon->move(0.f, -1.f, dt);
			else if (posenemy.y < posplayer.y)
				this->demon->move(0.f, 1.f, dt);
		}
		else if (posenemy.y < posplayer.y)
			this->demon->move(0.f, 1.f, dt);
		else if (posenemy.y > posplayer.y)
			this->demon->move(0.f, -1.f, dt);
	}

	//zombie
	if (Clock.getElapsedTime().asSeconds() > 150)
	{
		for (int i = 0; i < zombie_size; i++)
		{
			posenemy = this->zombie[i]->getPosition();
			if (posenemy.x > posplayer.x)
			{
				this->zombie[i]->move(-1.f, 0.f, dt);
				if (posenemy.y > posplayer.y)
					this->zombie[i]->move(0.f, -1.f, dt);
				else if (posenemy.y < posplayer.y)
					this->zombie[i]->move(0.f, 1.f, dt);
			}
			else if (posenemy.x < posplayer.x)
			{
				this->zombie[i]->move(1.f, 0.f, dt);
				if (posenemy.y > posplayer.y)
					this->zombie[i]->move(0.f, -1.f, dt);
				else if (posenemy.y < posplayer.y)
					this->zombie[i]->move(0.f, 1.f, dt);
			}
			else if (posenemy.y < posplayer.y)
				this->zombie[i]->move(0.f, 1.f, dt);
			else if (posenemy.y > posplayer.y)
				this->zombie[i]->move(0.f, -1.f, dt);
		}
	}
	//TEST FOR IMP
	if (Clock.getElapsedTime().asSeconds() > 85)
	{
		for (int i = 0; i < imp_size; i++)
		{
			posenemy = this->imp[i]->getPosition();

			if (posenemy.x < 0)
				imp_move[i] = 0;
			if (posenemy.x > 1920)
				imp_move[i] = 1;
			if (imp_move[i] == 0)
				this->imp[i]->move(1.f, 0.f, dt);
			else
				this->imp[i]->move(-1.f, 0.f, dt);
		}
	}
	//skeleton
	if (Clock.getElapsedTime().asSeconds() > 45)
	{
		for (int i = 0; i < skeleton_size; i++)
		{
			posenemy = this->skeleton[i]->getPosition();
			if (posenemy.x > posplayer.x)
			{
				this->skeleton[i]->move(-1.f, 0.f, dt);
				if (posenemy.y > posplayer.y)
					this->skeleton[i]->move(0.f, -1.f, dt);
				else if (posenemy.y < posplayer.y)
					this->skeleton[i]->move(0.f, 1.f, dt);
			}
			else if (posenemy.x < posplayer.x)
			{
				this->skeleton[i]->move(1.f, 0.f, dt);
				if (posenemy.y > posplayer.y)
					this->skeleton[i]->move(0.f, -1.f, dt);
				else if (posenemy.y < posplayer.y)
					this->skeleton[i]->move(0.f, 1.f, dt);
			}
			else if (posenemy.y < posplayer.y)
				this->skeleton[i]->move(0.f, 1.f, dt);
			else if (posenemy.y > posplayer.y)
				this->skeleton[i]->move(0.f, -1.f, dt);
		}
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
		this->states->push(new MainMenuState(this->window, this->states));
		this->music["GAME_MUSIC"].stop();
		this->endState();
		Clock.restart();
	}
}

void GameStates::update(const float& dt)
{
	this->updateMousePos();
	this->updateKeytime(dt);
	this->updateInput(dt);

	if(!this->Pause) //unpause
	{
		float Time = Clock.getElapsedTime().asSeconds();
		std::cout << Time << std::endl;
		std::cout << playerHP << std::endl;
		std::cout << score << std::endl;
		std::cout << std::endl;
		this->updatePlayerInput(dt);
		this->updateText(score,Time);
		this->updateHpBar();
		this->player->update(dt);
		this->sword->update(dt);
		this->demon->update(dt);

		if (playerHP <= 0)
		{
			this->music["GAME_MUSIC"].stop();
			player_dead.play();
			this->states->push(new GameOver(this->window, this->states,score));
			this->endState();
			Clock.restart();
			playerHP = playerMaxHP;
		}
		if (playerHP >= playerMaxHP)
			playerHP = playerMaxHP;
		if (immortality == 1)
		{
			if (check == 1)
			{
				starttime = Clock.getElapsedTime().asSeconds();
				Immortality_effect.play();
				check = 0;
			}
			else if (Time - starttime >= immortal_time)
			{
				immortality = 0;
				check = 1;
			}
		}

		//demon
		if (this->demon->getGlobalBounds().intersects(this->player->getGlobalBounds()))
		{
			if (immortality == 1)
			{
				if (check == 1)
				{
					starttime = Clock.getElapsedTime().asSeconds();
					check = 0;
				}
				else if (Time - starttime >= immortal_time)
				{
					immortality = 0;
					check = 1;
				}
				else
					this->demon->setPosition(rand() % 1920, rand() % 950);
			}
			else
			{
				playerHP = 0;
				player_hurt.play();
				this->demon->setPosition(rand() % 1920, rand() % 950);
			}
		}
		//goblin
		for (int i = 0; i < goblin_size; i++)
		{
			this->goblin[i]->update(dt);
			if (this->goblin[i]->getGlobalBounds().intersects(this->player->getGlobalBounds()))
			{
				if (immortality == 1)
				{
					if (check == 1)
					{
						starttime = Clock.getElapsedTime().asSeconds();
						check = 0;
					}
					else if (Time - starttime >= immortal_time)
					{
						immortality = 0;
						check = 1;
					}
					else
						this->goblin[i]->setPosition(rand() % 1920, rand() % 950);
				}
				else
				{
					this->goblin[i]->setPosition(rand() % 1920, rand() % 950);
					player_hurt.play();
					playerHP -= 5;
				}
			}
			if (this->goblin[i]->getGlobalBounds().intersects(this->sword->getGlobalBounds()))
			{
				monster_dead.play();
				this->goblin[i]->setPosition(rand() % 1920, rand() % 950);
				score++;
				int drop_from_goblin = rand() % 100;
				if (drop_from_goblin >= 40)
				{
					if (playerHP >= playerMaxHP)
						continue;
					else
					{
						playerHP += 2;
						heal.play();
					}
				}
				if (drop_from_goblin <= immortal_percent)
				{
					immortality = 1;
				}
			}
		}

		//zombie
		if (Clock.getElapsedTime().asSeconds() > 150)
		{
			for (int i = 0; i < zombie_size; i++)
			{
				this->zombie[i]->update(dt);
				if (this->zombie[i]->getGlobalBounds().intersects(this->player->getGlobalBounds()))
				{
					if (immortality == 1)
					{
						if (check == 1)
						{
							starttime = Clock.getElapsedTime().asSeconds();
							check = 0;
						}
						else if (Time - starttime >= immortal_time)
						{
							immortality = 0;
							check = 1;
						}
						else
							this->zombie[i]->setPosition(rand() % 1920, rand() % 950);
					}
					else
					{
						player_hurt.play();
						playerHP = 0;
						this->zombie[i]->setPosition(rand() % 1920, rand() % 950);
					}
				}
			}
		}
		//skeleton
		if (Clock.getElapsedTime().asSeconds() > 45)
		{
			for (int i = 0; i < skeleton_size; i++)
			{
				this->skeleton[i]->update(dt);
				if (this->skeleton[i]->getGlobalBounds().intersects(this->player->getGlobalBounds()))
				{
					if (immortality == 1)
					{
						if (check == 1)
						{
							starttime = Clock.getElapsedTime().asSeconds();
							check = 0;
						}
						else if (Time - starttime >= immortal_time)
						{
							immortality = 0;
							check = 1;
						}
						else
							this->skeleton[i]->setPosition(rand() % 1920, rand() % 950);
					}
					else
					{
						playerHP -= 9;
						player_hurt.play();
						this->skeleton[i]->setPosition(rand() % 1920, rand() % 950);
					}
				}
				if (this->skeleton[i]->getGlobalBounds().intersects(this->sword->getGlobalBounds()))
				{
					monster_dead.play();
					score += 2;
					this->skeleton[i]->setPosition(rand() % 1920, rand() % 60 - 80);
					int drop_from_skeleton = rand() % 100;
					if (drop_from_skeleton >= 50)
					{
						if (playerHP >= playerMaxHP)
							continue;
						else
						{
							playerHP += 1;
							heal.play();
						}
					}
					if (drop_from_skeleton <= immortal_percent)
					{
						immortality = 1;
					}
				}
			}
		}
		//imp
		if (Clock.getElapsedTime().asSeconds() > 85)
		{
			for (int i = 0; i < imp_size; i++)
			{
				this->imp[i]->update(dt);
				if (this->imp[i]->getGlobalBounds().intersects(this->player->getGlobalBounds()))
				{
					if (immortality == 1)
					{
						if (check == 1)
						{
							starttime = Clock.getElapsedTime().asSeconds();
							check = 0;
						}
						else if (Time - starttime >= immortal_time)
						{
							immortality = 0;
							check = 1;
						}
						else
							this->imp[i]->setPosition(rand() % 1920, rand() % 950);
					}
					else
					{
						playerHP -= 12;
						player_hurt.play();
						if (imp_move[i] == 0)
							this->imp[i]->setPosition(rand() % 50 + 1970, rand() % 950);
						else if (imp_move[i] == 1)
							this->imp[i]->setPosition(rand() % 50 - 50, rand() % 950);
					}
				}
				if (this->imp[i]->getGlobalBounds().intersects(this->sword->getGlobalBounds()))
				{
					monster_dead.play();
					score += 4;
					if (imp_move[i] == 0)
						this->imp[i]->setPosition(rand() % 50 + 1970, rand() % 950);
					else if (imp_move[i] == 1)
						this->imp[i]->setPosition(rand() % 50 - 50, rand() % 950);
					int drop_from_imp = rand() % 100;
					if (drop_from_imp >= 60)
					{
						if (playerHP >= playerMaxHP)
							continue;
						else
						{
							playerHP += 4;
							heal.play();
						}
					}
					if (drop_from_imp <= immortal_percent)
					{
						immortality = 1;
					}
				}
				if (this->imp[i]->getPosition().x > 1920)
					this->imp[i]->setPosition(rand() % 50 + 1920, rand() % 950);
				else if (this->imp[i]->getPosition().x < -30)
					this->imp[i]->setPosition(rand() % 50 - 80, rand() % 950);
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
	target->draw(this->hpHidBar);
	target->draw(this->hpShowBar);
	target->draw(this->current_score);
	target->draw(this->current_time);
	target->draw(this->current_buff);
	this->player->render(*target);
	this->sword->render(*target);
	this->demon->render(*target);

	for (int i = 0; i < goblin_size; i++)
	{
		this->goblin[i]->render(*target);
	}

	//TEST FOR MORE ENEMY
	if (Clock.getElapsedTime().asSeconds() > 150)
	{
		for (int i = 0; i < zombie_size; i++)
		{
			this->zombie[i]->render(*target);
		}
	}
	if (Clock.getElapsedTime().asSeconds() > 45)
	{
		for (int i = 0; i < skeleton_size; i++)
		{
			this->skeleton[i]->render(*target);
		}
	}
	if (Clock.getElapsedTime().asSeconds() > 85)
	{
		for (int i = 0; i < imp_size; i++)
		{
			this->imp[i]->render(*target);
		}
	}
	if (this->Pause) //pauseMenu render
	{
		this->pmenu->render(*target);
	}
	
}

