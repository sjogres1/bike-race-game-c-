#include <Box2D/Box2D.h>
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Screens.hpp"
#include "HighScores.hpp"
#include "LevelsMenu.hpp"
#include "Instructions.hpp"
#include <vector>
#include "DEFINITIONS.hpp"
#include <iostream>

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
    
    Game g1;
    screens.push_back(&g1);
    
    Game g2;
    screens.push_back(&g2);
    
    Game g3;
    screens.push_back(&g3);
    


    while (screen >= 0) {
        //std::cout << screen;
        screen = screens[screen]->open(window, screen);
   }
}