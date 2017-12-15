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
    //Screens vector that contains all the "states" of the game
    std::vector<Screen*> screens;
    int screen = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hillside Racing", sf::Style::Default, settings);
    
    /*Initialize all the states of the game.
     *States need to be pushed into the screens vector in correct order,
     * corresponding to the states defined in Screens.hpp
     */
    MainMenu mm;
    screens.push_back (&mm);
    
    LevelsMenu l;
    screens.push_back(&l);
    
    HighScores hs;
    screens.push_back(&hs);
    
    Instructions in;
    screens.push_back(&in);
    
    //each difficulty level of the game needs to initialized separately
    Game g_easy;
    screens.push_back(&g_easy);
    
    Game g_normal;
    screens.push_back(&g_normal);
    
    Game g_hard;
    screens.push_back(&g_hard);
    

    /*The main loop running the game. Each screen corresponds to number,
     *defined in Screens.hpp. These numbers are positive integers.
     *The open function of each screen return a number corresponding to a
     * new screen the player wishes to open*/
    while (screen >= 0) {
        screen = screens[screen]->open(window, screen);
   }
}