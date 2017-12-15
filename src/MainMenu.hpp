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
 
  int open(sf::RenderWindow &window, int screen) ;
  
    
  int processEvents(sf::RenderWindow& window) ;
 
};


#endif

