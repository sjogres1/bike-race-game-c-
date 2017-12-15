#include "HighScores.hpp"

HighScores::HighScores() {
      
    font.loadFromFile("LemonMilk.otf");
    
    title.setFont(font);
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Red);
    title.setPosition(SCREEN_WIDTH/6,(SCREEN_HEIGHT/10)*2);
    title.setString("Highscores"); 
}

int HighScores::open(sf::RenderWindow &window, int screen)  {
    if (update_highscores==true){
        scores_int.clear();
        scores_text.clear();
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
        update_highscores = false;
    }
    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();
        
        
        
        window.draw(title);
        
        for(auto t : scores_text){
            window.draw(t);
        }
        window.display();
        if (process == GAMESTATE_MAINMENU){
            update_highscores = true;
        }
        return process;
    }

    //Failsafe
    return -1;
}

int HighScores::processEvents(sf::RenderWindow& window) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased){
        switch (event.key.code){

        case sf::Keyboard::Escape:
           update_highscores = true;
           return GAMESTATE_MAINMENU;
        }
      }
    }

    return GAMESTATE_HIGHSCORES;
}