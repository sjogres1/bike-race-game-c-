#ifndef POINTSSPEEDCLOCK_HPP
#define POINTSSPEEDCLOCK_HPP
#include <ctime>
#include "GameObject.hpp"
#include "Car.hpp"

class PointsSpeedClock : public sf::Drawable {
    
    public:
    
        
    PointsSpeedClock(Player* player) {
        player3 = player;
        psc_font.loadFromFile("LemonMilk.otf");
        const float y_points = -500;
        const float x_points = 400;
        
        
        // Set parameters for scoretext
        scoretext.setFont(psc_font);
        scoretext.setCharacterSize(25);
        scoretext.setStyle(sf::Text::Bold);
        scoretext.setColor(sf::Color::White);
        scoretext.setPosition(0,20);
        
        //Set parameters for speedtext
        speedtext.setFont(psc_font);
        speedtext.setCharacterSize(25);
        speedtext.setStyle(sf::Text::Bold);
        speedtext.setColor(sf::Color::White);
        speedtext.setPosition(0,40);
        
        //Set parameters for clock
        clocktext.setFont(psc_font);
        clocktext.setCharacterSize(25);
        clocktext.setStyle(sf::Text::Bold);
        clocktext.setColor(sf::Color::White);
        clocktext.setPosition(0,60); 
    }
    
    void update() {
    score_ss.str("");
    score_ss << "Points " << player3->getPoints();
    scoretext.setString(score_ss.str()); 

   /* bikespeed_ss.str("");
    bikespeed_ss << "Speed: " << std::fixed << std::setprecision(0) << std::abs(player->getVelocity());
    bikespeed_text.setString(bikespeed_ss.str()); */
    
    start = std::clock()/divide;
    clock_ss.str("");
    clock_ss << "Time: " << start; 
    clocktext.setString(clock_ss.str());
  }

  void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(scoretext);
    //target.draw(speedtext);
    target.draw(clocktext);
  }
    
    private:
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