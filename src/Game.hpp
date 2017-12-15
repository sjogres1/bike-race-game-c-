//
//  Game.hpp
//  Hillside1
//

#ifndef Hillside1_Game_hpp
#define Hillside1_Game_hpp
#define BGSPEED 0.2

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include "Interface.hpp"
#include <list>
#include "Car.hpp"
#include "Coin.hpp"
#include "Screens.hpp"
#include "GameObject.hpp"
#include "Ground.hpp"
#include "Goal.hpp"
#include "PointsSpeedClock.hpp"
//#include <SFML/OpenGL.hpp>
#include "DEFINITIONS.hpp"
#include <unistd.h>



namespace {
    const float WWidth = 1024;
    const float WHeight = 768;
    b2Vec2 gravity(0.0f, -9.8f);
    const float32 timeStep = 1.0f / 60.0f;
    const int32 velocityIterations = 8;
    const int32 positionIterations = 6;
    const float y_points = -500;
    const float x_points = 400;
    //int goal_points = 0;
    
    
}


class Game : public Screen
{
    public:
    //Constructor
    Game();

    //Destructor
    ~Game(); 
    
    
    // opens the game and handles lots of function and parameters
    int open(sf::RenderWindow &window, int screen);
         

    //protected:
    
    private:
    int goal_points;
    sf::RenderWindow window;
    sf::ContextSettings settings;
    sf::Clock clock;
    sf::ContextSettings setting;
    std::vector<GameObject*> objects;
    float difficulty = 0;
    int map_length = 200;
    
};

#endif