#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameStates.h"
#include "Button.h"
#include "Scoreboard.h"

class MainMenuState :
    public State
{
private:
    //Variebles
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*>buttons;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initButton();

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Function
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};


#endif