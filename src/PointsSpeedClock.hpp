#ifndef POINTSSPEEDCLOCK_HPP
#define POINTSSPEEDCLOCK_HPP
#include <ctime>
#include "GameObject.hpp"
#include "Car.hpp"
#include <sstream>

class PointsSpeedClock : public sf::Drawable {
    
    public:

        ~PointsSpeedClock();
    
    
        PointsSpeedClock(Player* player);
    
        void update();
        
      
    
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
       
         void getFinish() {
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