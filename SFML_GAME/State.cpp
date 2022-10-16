#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->End = false;
}

State::~State()
{

}

const bool& State::getEnd() const
{
	return this->End;
}

void State::endState()
{
	this->End = true;
}

void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
