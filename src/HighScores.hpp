#ifndef HIGHSCRORES_HPP
#define HIGHSCRORES_HPP

#include <iostream>
#include "Screens.hpp"
#include <algorithm>
#include <fstream>
#include "DEFINITIONS.hpp"
#include <string> 

class HighScores : public Screen {

private:
    size_t position;
    sf::Texture texture;
    sf::Text title;
    sf::Font font;
    
    sf::Text score_text;
    int score_int;
    std::vector<sf::Text> scores_text;
    std::vector<int> scores_int;
    //flag for updating high scores only once when the screen is opened
    bool update_highscores = true;
    
public:

  HighScores();
  
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

