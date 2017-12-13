/* 
 * File:   MainMenu.hpp
 * Author: ilkka
 *
 * Created on December 12, 2017, 10:15 AM
 */

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <iostream>
#include "Screens.hpp"

class MainMenu : public Screen {

private:
    size_t position;
    std::vector<sf::Text*> options;
    sf::Texture texture;
    sf::Text option_play;
    sf::Text option_highscores;
    sf::Font font;

public:

  MainMenu() {

    position = 0;
    font.loadFromFile("LemonMilk.otf"); 

    option_play.setFont(font);
    option_play.setCharacterSize(50);
    option_play.setStyle(sf::Text::Bold);
    option_play.setColor(sf::Color::White);
    option_play.setPosition(400,520);
    option_play.setString("NEW GAME"); 
    options.push_back(&option_play);

    option_highscores.setFont(font);
    option_highscores.setCharacterSize(50);
    option_highscores.setStyle(sf::Text::Bold);
    option_highscores.setColor(sf::Color::White);
    option_highscores.setPosition(370,580);
    option_highscores.setString("HIGH SCORES");  
    options.push_back(&option_highscores);
  }

    

  int open(sf::RenderWindow &window)  {

    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();

        for(size_t i = 0; i < options.size(); i++) {
          if(i == position) {
            options[i]->setColor(sf::Color::Red);
          } 
          else {
            options[i]->setColor(sf::Color::White);
          }
        }

        
        for(auto t : options)
            window.draw(*t);
        window.display();

        return process;
    }

    //Temporary solution
    return -1;
}



    
  int processEvents(sf::RenderWindow& window) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased)
        switch (event.key.code){
            
        case sf::Keyboard::Return:
          if(position == 0) {
            return GAMESTATE_LEVELS;
          } 
          if(position == 1) {
            return GAMESTATE_HIGHSCORES;
          }

        case sf::Keyboard::Escape:
           return -1;
           
        case sf::Keyboard::Up: 
          if(position > 0){
             position--;
          }

        return GAMESTATE_MAINMENU;

        case sf::Keyboard::Down:
           if(position < options.size() - 1) {
             position++;
           }

           return GAMESTATE_MAINMENU;
      }
    }

    return GAMESTATE_MAINMENU;
  }
};


#endif /* MAINMENU_HPP */

