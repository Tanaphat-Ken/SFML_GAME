#ifndef MOVEMENTCOMPONENTS_H
#define MOVEMENTCOMPONENTS_H

#include<iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

enum movement_states {IDLE = 0,MOVING,MOVING_LEFT,MOVING_RIGHT,MOVING_UP,MOVING_DOWN};

class MovementComponents
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;
	sf::Vector2f velocity;

	//init functions

public:
	MovementComponents(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponents();

	//accessor
	const sf::Vector2f& getVelocity() const;

	//functions
	const bool getState(const short unsigned state) const;

	void move(const float x, const float y, const float& dt);
	void update(const float& dt);
};

#endif