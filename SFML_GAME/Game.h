#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//initiate
	void initwindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateevent();
	void update();

	//render
	void render();

	//core
	void run();
};

#endif