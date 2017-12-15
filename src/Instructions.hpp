#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "DEFINITIONS.hpp"
#include "Screens.hpp"
#include <SFML/Graphics.hpp>

class Instructions : public Screen {

private:
    size_t position;
    sf::Text title;
    sf::Text instructions;
    sf::Font font;
    
public:

  Instructions();
  
  /*Open gets two parameters. window is the game window, to which LevelsMenu 
 performs its operations, i.e. draws the menu. Int is the number of
 the screen/state that called the function*/
  int open(sf::RenderWindow &window, int screen);

   /*Method defining and monitoring controls and user interaction 
   (e.g. pressing esc to return) inside this state.
   Gets the window as parameter.*/
  int processEvents(sf::RenderWindow& window);
};


#endif

