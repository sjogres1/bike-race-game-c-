#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <iostream>
#include "Screens.hpp"
#include "DEFINITIONS.hpp"

class MainMenu : public Screen {

private:
    size_t position;
    std::vector<sf::Text*> options;
    sf::Texture texture;
    sf::Text option_levels;
    sf::Text option_highscores;
    sf::Text option_instructions;
    sf::Font font;

public:

  MainMenu();
 
  
   /*Open gets two parameters. window is the game window, to which LevelsMenu 
 performs its operations, i.e. draws the menu. Int is the number of
 the screen/state that called the function*/
  int open(sf::RenderWindow &window, int screen) ;
  
    /*Method defining and monitoring controls and user interaction 
   (e.g. pressing esc to return) inside this state.
   Gets the window as parameter.*/
  int processEvents(sf::RenderWindow& window) ;
 
};


#endif

