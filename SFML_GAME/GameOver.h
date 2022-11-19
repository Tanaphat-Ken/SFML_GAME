#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "State.h"
#include "Button.h"
#include "GameStates.h"

class GameOver :
    public State
{
private:
    sf::RectangleShape background;
    sf::Font font;
    std::stringstream ss;
    sf::Text GAMEOVER;
    std::string playerInput;
    sf::Text playerText;
    sf::Event event;

    std::map<std::string, Button*>buttons;

    //Attribute
    int score0 = 0;

    //Functions
    void initBackground(sf::RenderWindow& window);
    void initFonts();
    void initButton();
    void initText();
    void initPlayerText();

public:
    GameOver(sf::RenderWindow* window, std::stack<State*>* states, int score);
    virtual ~GameOver();

    //Functions

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif


