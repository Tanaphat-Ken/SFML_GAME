#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "State.h"

class Scoreboard :
    public State
{
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    
    //Functions
    void initBackground();

public:
    Scoreboard(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~Scoreboard();

    //Functions
    
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif

