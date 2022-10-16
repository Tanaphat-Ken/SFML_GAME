#include "Game.h"

//initiate
void Game::initwindow()
{
    //Create Window

    std::ifstream ifs("Config/window.ini");
    
    std::string title = "None";
    sf::VideoMode window_bounds(1920, 1080);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    srand(time(NULL));
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->initwindow();
    this->initStates();
}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    { 
        delete this->states.top();
        this->states.pop();
    }
}

//Function

void Game::endApplication()
{
    std::cout << "EndingApplication" << "\n";
}

void Game::updateDt()
{
    //1 frame , update&&render
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateevent()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateevent();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getEnd())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    
    //END App
    else
    {
        this->endApplication();
        this->window->close();
    }

}

void Game::render()
{
    this->window->clear();

    //Render item
    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
