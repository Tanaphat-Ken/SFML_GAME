#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->End = false;
	this->Pause = false;
	this->keytime = 0.f;
	this->keytimeMax = 40.f;
}

State::~State()
{

}

//Accessor
const bool& State::getEnd() const
{
	return this->End;
}

const bool& State::getKeytime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	else
		return false;
}

//Function
void State::endState()
{
	window->setMouseCursorVisible(true);
	this->End = true;
}

void State::pauseState()
{
	window->setMouseCursorVisible(true);
	this->Pause = true;
}

void State::unpauseState()
{
	this->Pause = false;
}

void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::updateKeytime(const float& dt)
{
	if (this->keytime < this->keytimeMax)
		this->keytime += 60.f * dt;
}
