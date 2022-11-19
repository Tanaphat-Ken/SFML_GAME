#include "Scoreboard.h"

void Scoreboard::initBackground(sf::RenderWindow& window)
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/SCOREBOARD.png"))
	{
		throw"ERROR::SCOREBOARD::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

	//Init background
	this->bg.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)
		)
	);
	this->bg.setFillColor(sf::Color(20, 20, 20, 100));

	//Init container
	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 2.f,
			static_cast<float>(window.getSize().y) - 100.f
		)
	);
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
		30.f
	);
}

void Scoreboard::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Superstar M54.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void Scoreboard::initButton()
{
	this->buttons["END_STATE"] = new Button(20.f, 850.f, 250.f, 150.f, &this->font, "BACK", 50,
		sf::Color(250, 250, 250, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void Scoreboard::initText()
{
	ss << "SCOREBOARD";
	SCOREBOARD.setString(ss.str());
	SCOREBOARD.setFont(font);
	SCOREBOARD.setOrigin(SCOREBOARD.getGlobalBounds().width / 2, SCOREBOARD.getGlobalBounds().height / 2);
	SCOREBOARD.setCharacterSize(75);
	SCOREBOARD.setPosition(840, 80);

	ss1 << score0;
	score1.setString(ss1.str());
	score1.setFont(font);
	score1.setOrigin(score1.getGlobalBounds().width / 2, score1.getGlobalBounds().height / 2);
	score1.setCharacterSize(50);
	score1.setPosition(1350, 250);
}

//CON /DES
Scoreboard::Scoreboard(sf::RenderWindow* window, std::stack<State*>* states, int score)
	: State(window, states)
{
	score0 = score;
	this->initFonts();
	this->initButton();
	this->initText();
	this->initBackground(*this->window);
}

Scoreboard::~Scoreboard()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Scoreboard::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
}

void Scoreboard::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	//back
	if (this->buttons["END_STATE"]->isPressed())
	{
		this->endState();
	}
}

void Scoreboard::update(const float& dt)
{
	this->updateButtons();
	this->updateMousePos();
	this->updateInput(dt);
}

void Scoreboard::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Scoreboard::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->bg);
	target->draw(this->container);
	target->draw(this->SCOREBOARD);
	target->draw(this->score1);
	this->renderButtons(*target);

}
