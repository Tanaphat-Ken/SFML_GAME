#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "State.h"
#include "Button.h"

class PauseMenu
{
private:
    //Variebles
    sf::RectangleShape background;
    sf::RectangleShape container;
    sf::Font& font;
    sf::Text menuText;

    std::map<std::string, Button*>buttons;

    //Functions

public:
    PauseMenu(sf::RenderWindow& window,sf::Font& font);
    virtual ~PauseMenu();

    //Accessor
    std::map<std::string, Button*>& getButtons();

    //Functions
    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

};

#endif
