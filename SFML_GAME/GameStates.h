#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "Entity.h"
#include "MainMenuState.h"
#include "GameOver.h"

class GameStates :
    public State 
{
private:
    int imp_move[3];
    int check = 1;
    float starttime = 0;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ssIm;
    sf::Clock Clock;
    sf::Font font;
    sf::Text current_score;
    sf::Text current_time;
    sf::Text current_buff;
    sf::Sound monster_dead;
    sf::Sound Immortality_effect;
    sf::Sound player_dead;
    sf::Sound heal;
    sf::Sound player_hurt;
    sf::RectangleShape hpHidBar;
    sf::RectangleShape hpShowBar;
    PauseMenu* pmenu; 
    HitboxComponent* hitboxComponent;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::RenderTexture renderTexture;
    #define goblin_size 10 //0 sec
    #define skeleton_size 10 //45 sec
    #define imp_size 3 //85 sec
    #define zombie_size 2 //150 sec
    Player* player;
    Sword* sword;
    Goblin* goblin[10];
    Skeleton* skeleton[10];
    Imp* imp[3];
    Zombie* zombie[2]; //150 sec
    Demon* demon; //10 sec
    sf::Vector2f posenemy, posplayer;
    

    //Attribute
    int immortality = 0;
    int immortal_time = 3;
    int immortal_percent = 5;
    int playerHP = 30;
    int playerMaxHP = 30;

    //Functions

    void initBackground();
    void initFonts();
    void initTextures();
    void initSound();
    void initPauseMenu();
    void initEntity();
    void initHpBar();
    void initText();
    

public:
    GameStates(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameStates();

    //Functions
    void updateText(int time, float Time);
    void updateHpBar();
    void updateInput(const float& dt);
    void updatePlayerInput(const float& dt);
    void updatePauseMenuButtons();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif