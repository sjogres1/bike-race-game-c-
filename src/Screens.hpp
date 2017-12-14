/* 
 * File:   Screens.hpp
 * Author: ilkka
 *
 * Created on December 12, 2017, 10:10 AM
 */

#ifndef SCREENS_HPP
#define SCREENS_HPP

#include "Game.hpp"

#define GAMESTATE_MAINMENU 0
#define GAMESTATE_LEVELS 1
#define GAMESTATE_HIGHSCORES 2
#define GAMESTATE_INSTRUCTIONS 3
//#define GAMESTATE_GAME 4


#define GAME_DIFFICULTY_EASY 4
#define GAME_DIFFICULTY_NORMAL 5
#define GAME_DIFFICULTY_HARD 6


class Screen{

public :
    virtual int open(sf::RenderWindow &window, int) = 0;
    //virtual int run(sf::RenderWindow &window, float) = 0;
};


#endif /* SCREENS_HPP */

