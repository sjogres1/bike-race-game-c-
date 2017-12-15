#ifndef LEVELSMENU_HPP
#define LEVELSMENU_HPP

#include <iostream>
#include "Screens.hpp"
#include "DEFINITIONS.hpp"


class LevelsMenu : public Screen {

private:
    size_t position;
    std::vector<sf::Text*> levels;
    sf::Texture texture;
    sf::Text level1;
    sf::Text level2;
    sf::Text level3;
    sf::Font font;

public:

  LevelsMenu();
 
 /*Open gets two parameters. window is the game window, to which LevelsMenu 
 performs its operations, i.e. draws the menu. Int is the number of
 the screen/state that called the function*/
  int open(sf::RenderWindow &window, int screen);
 
  //Method defining controls inside this state. Gets the window as parameter.
  int processEvents(sf::RenderWindow& window);
 
};


#endif

