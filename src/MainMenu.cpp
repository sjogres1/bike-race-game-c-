#include "MainMenu.hpp"

MainMenu::MainMenu() {

    position = 0;
    font.loadFromFile("LemonMilk.otf"); 

    option_levels.setFont(font);
    option_levels.setCharacterSize(50);
    option_levels.setStyle(sf::Text::Bold);
    option_levels.setColor(sf::Color::White);
    option_levels.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*3);
    option_levels.setString("LEVELS"); 
    options.push_back(&option_levels);

    option_highscores.setFont(font);
    option_highscores.setCharacterSize(50);
    option_highscores.setStyle(sf::Text::Bold);
    option_highscores.setColor(sf::Color::White);
    option_highscores.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*5);
    option_highscores.setString("HIGH SCORES");  
    options.push_back(&option_highscores);
    
    option_instructions.setFont(font);
    option_instructions.setCharacterSize(50);
    option_instructions.setStyle(sf::Text::Bold);
    option_instructions.setColor(sf::Color::White);
    option_instructions.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*7);
    option_instructions.setString("INSTRUCTIONS"); 
    options.push_back(&option_instructions);
  }

    

  int MainMenu::open(sf::RenderWindow &window, int screen)  {

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



    
  int MainMenu::processEvents(sf::RenderWindow& window) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased){
        switch (event.key.code){
            
        case sf::Keyboard::Return:
          if(position == 0) {
            return GAMESTATE_LEVELS;
          } 
          if(position == 1) {
            return GAMESTATE_HIGHSCORES;
          }
          if(position == 2) {
            return GAMESTATE_INSTRUCTIONS;
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
    }

    return GAMESTATE_MAINMENU;
  }