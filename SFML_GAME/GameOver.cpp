#include "GameOver.h"

void GameOver::initBackground(sf::RenderWindow& window)
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	this->background.setFillColor(sf::Color::Black);
}

void GameOver::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Superstar M54.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameOver::initButton()
{
	this->buttons["OK"] = new Button(830.f, 850.f, 250.f, 150.f, &this->font, "OK", 50,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void GameOver::initText()
{
	ss << "GAMEOVER";
	GAMEOVER.setString(ss.str());
	GAMEOVER.setFont(font);
	GAMEOVER.setOrigin(GAMEOVER.getGlobalBounds().width / 2, GAMEOVER.getGlobalBounds().height / 2);
	GAMEOVER.setCharacterSize(200);
	GAMEOVER.setPosition(600, 80);
	GAMEOVER.setFillColor(sf::Color::Red);
}

void GameOver::initPlayerText()
{
	playerText.setFont(font);
	playerText.setCharacterSize(200);
	playerText.setPosition(600, 280);
	playerText.setFillColor(sf::Color::White);
}

//CON /DES
GameOver::GameOver(sf::RenderWindow* window, std::stack<State*>* states, int score)
	: State(window, states)
{
	score0 = score;
	this->initFonts();
	this->initButton();
	this->initText();
	this->initPlayerText();
	this->initBackground(*this->window);
}

GameOver::~GameOver()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameOver::updateInput(const float& dt)
{
}

void GameOver::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	//OK
	if (this->buttons["OK"]->isPressed())
	{
		this->states->push(new MainMenuState(this->window, this->states));
		this->states->push(new Scoreboard(this->window, this->states, score0));
		this->endState();
	}
}

void GameOver::update(const float& dt)
{
	this->updateButtons();
	this->updateMousePos();
	this->updateInput(dt);
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 128)
		{
			playerInput += event.text.unicode;
			playerText.setString(playerInput);
		}
	}
	this->window->draw(playerText);
}

void GameOver::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void GameOver::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->GAMEOVER); 
	target->draw(this->playerText);
	this->renderButtons(*target);

}
