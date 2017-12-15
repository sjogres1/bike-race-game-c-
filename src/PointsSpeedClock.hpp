#ifndef POINTSSPEEDCLOCK_HPP
#define POINTSSPEEDCLOCK_HPP
#include <ctime>
#include "GameObject.hpp"
#include "Car.hpp"
#include <sstream>

class PointsSpeedClock : public sf::Drawable {
    
    public:
       
       // destructor
        ~PointsSpeedClock();
         
        //Sets drawing settings for points, speed and goaltext
        PointsSpeedClock(Player* player);
        
    
        //updates texts tha are printed to the screen
        void update();
        
    
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        //Draws text to the screen
       
         void getFinish() {
            // flag for finish line
        finish_count =1;
    }
    
    private:
    int finish_count;
    double divide = 1000000;
    std::clock_t start;
    sf::Font psc_font;
    Player* player3;
    sf::Text scoretext;
    std::stringstream bikespeed_ss;
    sf::Text speedtext;
    std::stringstream score_ss;
    
    sf::Text clocktext;
    std::stringstream clock_ss;
    
    
    
}; 

#endif