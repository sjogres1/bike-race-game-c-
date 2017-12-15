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
 
  int open(sf::RenderWindow &window, int screen);
 
  int processEvents(sf::RenderWindow& window);
 
};


#endif

