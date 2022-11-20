#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "State.h"
#include "Button.h"
#include "GameStates.h"
#include "MainMenuState.h"
#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <vector>

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
    std::stringstream ss11;
    std::stringstream ss12;
    sf::Text SCOREBOARD;
    sf::Text score1;
    sf::Text name1;
    sf::Text name5;
    sf::Text numS[5];
    sf::Text nameS[5];
    sf::Text scoreS[5];

    std::map<std::string, Button*>buttons;

    FILE* fp;
    char temp[255];
    unsigned int score[6];
    std::string name[6];
    std::vector<std::pair<int, std::string>> userScore;

    //Attribute
    int score0 = 0;
    std::string name0;

    //Functions
    void initBackground(sf::RenderWindow& window);
    void initFonts();
    void initButton();
    void initText();

public:
    Scoreboard(sf::RenderWindow* window, std::stack<State*>* states, int score, std::string playerInput);
    virtual ~Scoreboard();

    //Functions
    void readFile();
    void writeFile(std::string name, unsigned int score);
    void leaderBoard();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif

