//
//  Game.hpp
//  Hillside1
//

#ifndef Hillside1_Game_hpp
#define Hillside1_Game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interface.hpp"


namespace {
	const float WWidth = 1024;
	const float WHeight = 768;
	b2Vec2 gravity(0.0f, -9.8.0f);
	const float32 timeStep = 1.0f / 60.0f;
	const int32 velocityIterations = 8;
	const int32 positionIterations = 3;
}

class Game {
public:
    Game() : window(sf::VideoMode(WWidth, WHeight), "HillClimb racing") { }
    
    void open(void) {
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        sf::View view = window.getDefaultView();
        
        window.setView(view);
        b2World world(gravity, true);
        
        Ground ground(&world);
        Player player(&world);
        
       
        
        
        while(window.isOpen()) {
            
         sf::Event event;
        
        
      while (window.pollEvent(event))
			{
				
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				Interface::playerKeyboard(event, &player);
			}
			
			sf::Time dt = clock.restart();
			float accumulator = dt.asSeconds();
			while (accumulator > 0.0f)
			{
				world.Step(timeStep, velocityIterations, positionIterations);
				accumulator -= timeStep;
			}

			// Set view to follow player
			view.setCenter(player.getPosition().x*20+100, -player.getPosition().y*20-150);
			window.setView(view);
			
			player.update();
			player.debugLog(std::cout);
			
			window.clear();
			ground.draw(window);
			player.draw(window);
			window.display();
		}
    }
	
	
private:
	sf::RenderWindow window;
	sf::Clock clock;
};

#endif