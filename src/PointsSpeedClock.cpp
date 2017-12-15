#include "PointsSpeedClock.hpp"



PointsSpeedClock::PointsSpeedClock(Player* player) {


 player3 = player;
        psc_font.loadFromFile("LemonMilk.otf"); 
        finish_count=0;
        
        // Set parameters for scoretext
        scoretext.setFont(psc_font);
        scoretext.setCharacterSize(25);
        scoretext.setStyle(sf::Text::Bold);
        scoretext.setColor(sf::Color::White);
        scoretext.setPosition(0,20);
        
        //Set parameters for finish line text
        speedtext.setFont(psc_font);
        speedtext.setCharacterSize(40);
        speedtext.setStyle(sf::Text::Bold);
        speedtext.setColor(sf::Color::Magenta);
        speedtext.setPosition(200,40);
        
        //Set parameters for clock
        clocktext.setFont(psc_font);
        clocktext.setCharacterSize(25);
        clocktext.setStyle(sf::Text::Bold);
        clocktext.setColor(sf::Color::White);
        clocktext.setPosition(0,60);





}

PointsSpeedClock::~PointsSpeedClock() {

}


void PointsSpeedClock::update() {
    // updates points
 	score_ss.str("");
    score_ss << "Points " << player3->getPoints();
    scoretext.setString(score_ss.str()); 

    // updates finish line text    
    bikespeed_ss.str("");
    bikespeed_ss << "CONGRATULATIONS, YOU FINISHED :))!";
    speedtext.setString(bikespeed_ss.str()); 

    //updates clock    
    start = std::clock()/divide;
    clock_ss.str("");
    clock_ss << "Time: " << start; 
    clocktext.setString(clock_ss.str());


}

void PointsSpeedClock::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//draws every text to the screen
    target.draw(scoretext);
        target.draw(clocktext);
        if(finish_count == 1){
            target.draw(speedtext);
        }

}

