#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "DEFINITIONS.hpp"
#include "Screens.hpp"

class Instructions : public Screen {

private:
    size_t position;
    sf::Texture texture;
    sf::Text title;
    sf::Text instructions;
    sf::Font font;
    
public:

  Instructions() {
      
    font.loadFromFile("LemonMilk.otf");
      
    title.setFont(font);
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Red);
    title.setPosition(SCREEN_WIDTH/5,(SCREEN_HEIGHT/10)*3);
    title.setString("Instructions");
    
    instructions.setFont(font);
    instructions.setCharacterSize(10);
    instructions.setStyle(sf::Text::Bold);
    instructions.setColor(sf::Color::Red);
    instructions.setPosition(SCREEN_WIDTH/5,(SCREEN_HEIGHT/10)*5);
    instructions.setString("Accelerate using up and down arrow keys, tilt using left and right arrow keys"); 

  }

    

  int open(sf::RenderWindow &window)  {

    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();

        window.draw(title);
        window.draw(instructions);
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
           
        }
      }
    }

    return GAMESTATE_INSTRUCTIONS;
  }
};


#endif

