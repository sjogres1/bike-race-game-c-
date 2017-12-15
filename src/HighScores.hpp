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
    
public:

  HighScores() {
      
    font.loadFromFile("LemonMilk.otf");
    
    std::fstream myfile("highscores.txt");
    while (myfile >> score_int){
        scores_int.push_back(score_int);
    }
    std::sort(scores_int.rbegin(), scores_int.rend());
    
    for (int i = 0; i <  scores_int.size(); i++){
        score_text.setFont(font);
        score_text.setCharacterSize(10);
        score_text.setStyle(sf::Text::Bold);
        score_text.setColor(sf::Color::White);
        score_text.setPosition(SCREEN_WIDTH/6,(SCREEN_HEIGHT/20)*(10+i));
        score_text.setString(std::to_string(scores_int[i])); 
        scores_text.push_back(score_text);
    }
    
    
        
    title.setFont(font);
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Red);
    title.setPosition(SCREEN_WIDTH/6,(SCREEN_HEIGHT/10)*2);
    title.setString("Highscores"); 
  }

    

  int open(sf::RenderWindow &window, int screen)  {

    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();
        
        
        
        window.draw(title);
        
        for(auto t : scores_text){
            window.draw(t);
        }
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

