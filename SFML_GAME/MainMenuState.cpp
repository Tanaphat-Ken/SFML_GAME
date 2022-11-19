#include "MainMenuState.h"

//init
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(
	static_cast<float>(this->window->getSize().x), 
	static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/MENU.png"))
	{
		throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Superstar M54.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initMusic()
{
	if (!this->music["MENU_MUSIC"].openFromFile("Resources/Sound/Music/retrowave1-6271.ogg"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_MENU_MUSIC";
	}
	this->music["MENU_MUSIC"].setVolume(10);
	this->music["MENU_MUSIC"].play();
	this->music["MENU_MUSIC"].setLoop(true);
}

void MainMenuState::initButton()
{
	this->buttons["GAME_STATE"] = new Button(250.f, 180.f, 250.f, 50.f ,&this->font, "NEW GAME", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20,0));

	this->buttons["SCOREBOARD"] = new Button(250.f, 280.f, 250.f, 50.f, &this->font, "SCOREBOARD",50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["END_STATE"] = new Button(250.f, 380.f, 250.f, 50.f, &this->font, "QUIT",50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["CREDITS"] = new Button(1400.f, 10.f, 490.f, 50.f, &this->font, "65010421 TANAPHAT SOMBOON", 40,
		sf::Color(250, 250, 250, 250), sf::Color(250, 250, 250, 250), sf::Color(800, 250, 250, 250),
		sf::Color(250, 250, 250, 0), sf::Color(250, 250, 250, 0), sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window,states)
{
	this->initVariables();
	this->initBackground();
	this->initMusic();
	this->initFonts();
	this->initButton();

}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::updateInput(const float& dt)
{	

}

void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//new game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameStates(this->window,this->states));
		window->setMouseCursorVisible(false);
		this->music["MENU_MUSIC"].stop();
	}
	//Scoreboard
	if (this->buttons["SCOREBOARD"]->isPressed())
	{
		this->states->push(new Scoreboard(this->window, this->states,score));
	}
	//quit
	if (this->buttons["END_STATE"]->isPressed())
	{
		this->window->close();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
	this->updateButtons();

}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(*target);

	//remove later
	//sf::Text mouseText;
	//mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	//mouseText.setFont(this->font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << this->mousePosView.y;
	//mouseText.setString(ss.str());
	//target->draw(mouseText);
}
