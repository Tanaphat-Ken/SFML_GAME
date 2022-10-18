#include "Scoreboard.h"

void Scoreboard::initBackground()
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/SCOREBOARD.png"))
	{
		throw"ERROR::SCOREBOARD::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

}
//CON /DES
Scoreboard::Scoreboard(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->initBackground();
}

Scoreboard::~Scoreboard()
{

}

void Scoreboard::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
}

void Scoreboard::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
}

void Scoreboard::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

}
