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
#define GAMESTATE_GAME 4


class Screen{

public :
    virtual int open(sf::RenderWindow &window) = 0;
};


#endif /* SCREENS_HPP */

