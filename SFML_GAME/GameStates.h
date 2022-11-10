#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "EnemySystem.h"

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
    Sword* sword;
    #define goblin_size 30
    HitboxComponent* hitboxComponent;
    sf::Vector2f posenemy, posplayer;
    std::vector<Enemy*> activeEnemies;
    EnemySystem* enemySystem;
    Goblin* goblin[30];

    //Attribute
    int playerHP = 10;
    int score = 0;

    //Functions

    void initBackground();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initEntity(/*EnemySystem& enemySystem*/);
    void initEnemySystem();
    

public:
    GameStates(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameStates();

    //Functions
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();

    //NOT USING
    void updateCombat(Enemy* enemy, const int index, const float& dt);

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif