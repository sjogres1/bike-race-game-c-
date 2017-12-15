/* 
 * File:   Screens.hpp
 * Author: ilkka
 *
 * Created on December 12, 2017, 10:10 AM
 */
#include <SFML/Graphics.hpp>

#ifndef SCREENS_HPP
#define SCREENS_HPP

//The state numbers, corresponding to a specific screen/state
#define GAMESTATE_MAINMENU 0
#define GAMESTATE_LEVELS 1
#define GAMESTATE_HIGHSCORES 2
#define GAMESTATE_INSTRUCTIONS 3

#define GAME_DIFFICULTY_EASY 4
#define GAME_DIFFICULTY_NORMAL 5
#define GAME_DIFFICULTY_HARD 6

/*The base class Screen, inherited by each screen/state in the game.
 Screen only contains one function, open. This function gets two parameters.
 window is the game window, to which the screen/state currently selected 
 performs its operations, e.g. draws the menus or the game. Int is the number of
 the screen/state that called the function. This is necessary, as in some cases
 the operations inside open need to be aware of the state from which the open 
 was called. This is the case in the game states with different difficulty.*/

class Screen{

public :
    virtual int open(sf::RenderWindow &window, int) = 0;
};


#endif /* SCREENS_HPP */

