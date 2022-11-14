#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "Entity.h"

class GameStates :
    public State 
{
private:
    sf::Clock Clock;
    sf::Font font;
    PauseMenu* pmenu;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::RenderTexture renderTexture;
    #define goblin_size 20 //0 sec
    #define skeleton_size 10 //45 sec
    #define imp_size 3 //85 sec
    Player* player;
    Sword* sword;
    Goblin* goblin[20];
    //Zombie* zombie[2] //150 sec
    Demon* demon; //10 sec
    HitboxComponent* hitboxComponent;
    sf::Vector2f posenemy, posplayer;
    

    //Attribute
    int playerHP = 30;
    int score = 0;

    //Functions

    void initBackground();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initEntity();
    

public:
    GameStates(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameStates();

    //Functions
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif