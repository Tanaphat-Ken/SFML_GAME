#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameStates :
    public State
{
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    Player* player;
    Enemy* enemy[20];
    Sword* sword;
    #define enemy_size 20
    //sf::Vector2f enemies;
    //sf::Vector2f posenemy, posplayer;

    //Functions

    void initBackground();
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