#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"

class GameStates :
    public State 
{
private:
    sf::Font font;
    PauseMenu* pmenu;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::RenderTexture renderTexture;
    Player* player;
    Enemy* enemy[20];
    Sword* sword;
    #define enemy_size 20
    HitboxComponent* hitboxComponent;
    //sf::Vector2f enemies;
    sf::Vector2f posenemy, posplayer;

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