#include <Box2D/Box2D.h>
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Screens.hpp"
#include "HighScores.hpp"
#include "LevelsMenu.hpp"
#include "Instructions.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

int main(){

    std::vector<Screen*> screens;
    int screen = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hillside Racing", sf::Style::Default, settings);

    MainMenu mm;
    screens.push_back (&mm);
    
    LevelsMenu l;
    screens.push_back(&l);
    
    HighScores hs;
    screens.push_back(&hs);
    
    Instructions in;
    screens.push_back(&in);
    
    Game g;
    screens.push_back(&g);
    


    while (screen >= 0) {
        screen = screens[screen]->open(window);
   }
}