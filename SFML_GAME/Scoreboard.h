#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "State.h"
#include "Button.h"
#include "GameStates.h"
#include "MainMenuState.h"

class Scoreboard :
    public State
{
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;
    sf::RectangleShape bg;
    sf::RectangleShape container;
    std::stringstream ss;
    std::stringstream ss1;
    sf::Text SCOREBOARD;
    sf::Text score1;

    std::map<std::string, Button*>buttons;

    //Attribute
    int score0 = 0;

    //Functions
    void initBackground(sf::RenderWindow& window);
    void initFonts();
    void initButton();
    void initText();

public:
    Scoreboard(sf::RenderWindow* window, std::stack<State*>* states, int score);
    virtual ~Scoreboard();

    //Functions
    
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif

