#ifndef STATE_H
#define STATE_H

#include "Player.h"
#include "Enemy.h"
#include "Sword.h"

class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool End;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources
	std::map<std::string, sf::Texture> textures;


public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	const bool& getEnd() const;
	void endState();

	virtual void updateMousePos();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif

