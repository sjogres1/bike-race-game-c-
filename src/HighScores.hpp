#ifndef HIGHSCRORES_HPP
#define HIGHSCRORES_HPP

#include <iostream>
#include "Screens.hpp"
#include <algorithm>
#include <fstream>
#include "DEFINITIONS.hpp"

class HighScores : public Screen {

private:
    size_t position;
    sf::Texture texture;
    sf::Text title;
    sf::Text score;
    sf::Font font;
    //stuff needed for reading the highscores from file
    //std::vector<sf::Text*> scores_text;
    //std::fstream myfile("highscores.txt");
    //int a;
    //std::vector<a> scores_int;
    
public:

  HighScores() {
      
    font.loadFromFile("LemonMilk.otf");
     
    //while (myfile >> a){
    //    scores_int.push_back(a);
    //}
     
    //for (int i = 0; i <  scores_int.size(); i++){
    //    scores_text<i>.setFont(font);
    //   score.setCharacterSize(10);
    //    score.setStyle(sf::Text::Bold);
    //    score.setColor(sf::Color::White);
    //    score.setPosition(SCREEN_WIDTH/3,(SCREEN_HEIGHT/10)*(3+i));
    //    score.setString(i); 
    //    scores.push_back(&score);
    //}
    
    
        
    title.setFont(font);
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Red);
    title.setPosition(SCREEN_WIDTH/3,(SCREEN_HEIGHT/10)*2);
    title.setString("Highscores"); 
  }

    

  int open(sf::RenderWindow &window, int screen)  {

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
           return GAMESTATE_MAINMENU;
           
        case sf::Keyboard::Up: 
          if(position > 0){
             position--;
          }


        //case sf::Keyboard::Down:
        //   if(position < scores.size() - 1) {
        //    position++;
        //   }

           //return GAMESTATE_MAINMENU;
        }
      }
    }

    return GAMESTATE_HIGHSCORES;
  }
};


#endif

