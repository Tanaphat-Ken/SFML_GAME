#ifndef STATE_H
#define STATE_H

#include "Player.h"
#include "Goblin.h"
#include "Sword.h"


class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool End;
	bool Pause;
	float keytime;
	float keytimeMax;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources
	std::map<std::string, sf::Texture> textures;


public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	//Accessors
	const bool& getEnd() const;
	const bool& getKeytime();
	
	//Function
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePos();
	virtual void updateKeytime(const float& dt);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif

