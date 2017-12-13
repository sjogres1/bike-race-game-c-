#ifndef HIGHSCRORES_HPP
#define HIGHSCRORES_HPP

#include <iostream>
#include "Screens.hpp"
#include <algorithm>
#include "DEFINITIONS.hpp"

class HighScores : public Screen {

private:
    size_t position;
    std::vector<sf::Text*> scores;
    sf::Texture texture;
    sf::Text title;
    sf::Text score;
    sf::Font font;
    //temporary variable for testing high scores, later replaced with reading from file
    int temp_scores [5] = { 1, 7, 14, 3, 999 };
    
public:

  HighScores() {
      
    font.loadFromFile("LemonMilk.otf");
      
    title.setFont(font);
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Red);
    title.setPosition(SCREEN_WIDTH/3,SCREEN_HEIGHT/4);
    title.setString("Highscores"); 
     
    //for (int i = 0; i <  temp_scores.length(); i++){
    //    score.setFont(font);
    //    score.setCharacterSize(50);
    //    score.setStyle(sf::Text::Bold);
    //    score.setColor(sf::Color::White);
    //    score.setPosition(400,520);
    //    score.setString(i); 
    //    scores.push_back(&score);
    //}
  }

    

  int open(sf::RenderWindow &window)  {

    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();

        //for(size_t i = 0; i < scores.size(); i++) {
        //  if(i == position) {
        //    scores[i]->setColor(sf::Color::Red);
        //  } 
        //  else {
        //    scores[i]->setColor(sf::Color::White);
        //  }
        //}
        window.draw(title);//
        
        //for(auto t : scores)
        //    window.draw(*t);
        window.display();

        return process;
    }

    //Temporary solution
    return -1;
}



    
  int processEvents(sf::RenderWindow& window) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased){
        switch (event.key.code){

        case sf::Keyboard::Escape:
           return GAMESTATE_MAINMENU;;
           
        case sf::Keyboard::Up: 
          if(position > 0){
             position--;
          }


        case sf::Keyboard::Down:
           if(position < scores.size() - 1) {
             position++;
           }

           //return GAMESTATE_MAINMENU;
        }
      }
    }

    return GAMESTATE_HIGHSCORES;
  }
};


#endif

