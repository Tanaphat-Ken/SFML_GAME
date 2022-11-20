#define _CRT_SECURE_NO_WARNINGS
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
}

//CON /DES
Scoreboard::Scoreboard(sf::RenderWindow* window, std::stack<State*>* states, int score , std::string playerInput)
	: State(window, states)
{
	score0 = score;
	name0 = playerInput;
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

void Scoreboard::readFile()
{
	this->fp = fopen("./System/score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		userScore.push_back(make_pair(score[i], name[i]));
	}
}

void Scoreboard::writeFile(std::string name, unsigned int score)
{
	readFile();
	this->name[5] = name;
	this->score[5] = score;
	this->userScore.push_back(make_pair(this->score[5], this->name[5]));
	sort(this->userScore.begin(), this->userScore.end());
	fclose(this->fp);

	fopen("./System/score.txt", "w");
	for (int i = 5; i >= 1; i--)
	{
		strcpy(temp, userScore[i].second.c_str());
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}
	fclose(this->fp);
}

void Scoreboard::leaderBoard()
{
	readFile();
	fclose(this->fp);
	for (int i = 0; i < 5; i++)
	{
		this->numS[i].setFont(font);
		this->nameS[i].setFont(font);
		this->scoreS[i].setFont(font);

		this->numS[i].setCharacterSize(60);
		this->nameS[i].setCharacterSize(60);
		this->scoreS[i].setCharacterSize(60);

		this->numS[i].setFillColor(sf::Color::White);
		this->nameS[i].setFillColor(sf::Color::White);
		this->scoreS[i].setFillColor(sf::Color::White);

		this->numS[i].setPosition(500.f, 330.f + (i * 100));
		this->nameS[i].setPosition(550.f, 330.f + (i * 100));
		this->scoreS[i].setPosition(1400.f, 330.f + (i * 100));


		this->numS[i].setOrigin(0, this->numS[i].getLocalBounds().height);
		this->nameS[i].setOrigin(0, this->nameS[i].getLocalBounds().height);
		this->scoreS[i].setOrigin(this->scoreS[i].getLocalBounds().width, this->scoreS[i].getLocalBounds().height);

		this->numS[i].setString(std::to_string(i + 1) + ". ");
		this->nameS[i].setString(name[i]);
		this->scoreS[i].setString(std::to_string(score[i]) + " P");

		this->window->draw(numS[i]);
		this->window->draw(nameS[i]);
		this->window->draw(scoreS[i]);
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
	this->renderButtons(*target);
	leaderBoard();

}
