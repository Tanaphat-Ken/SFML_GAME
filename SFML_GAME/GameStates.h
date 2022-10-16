#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameStates :
    public State
{
private:
    Player* player;
    Enemy* enemy;
    Sword* sword;
    //Functions
    void initTextures();
    void initEntity();

public:
    GameStates(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameStates();

    //Functions
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif