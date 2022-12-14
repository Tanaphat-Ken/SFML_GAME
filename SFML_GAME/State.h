#ifndef STATE_H
#define STATE_H

#include "Player.h"
#include "Goblin.h"
#include "Sword.h"
#include "Demon.h"
#include "Skeleton.h"
#include "Zombie.h"
#include "Imp.h"


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
	std::map<std::string, sf::Music> music;
	std::map<std::string, sf::SoundBuffer> sounds;


public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	//Attribute
	std::string playerInput;
	int score = 0;
	float Time = 0;

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

