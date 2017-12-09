#include <Box2D/Box2D.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "game.hpp"




int main() {
  //sf::ContextSettings settings;
  //setting.antialiasingLevel = 8;
  sf::Event event;
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hillside Racing", sf::Style::Default);
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);



while(window.isOpen()) {
  while (window.pollEvent( event))
    {
      if( event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    //world.Step(timeStep, velocityIterations, positionIterations);
    window.display();
 
}



return 0;




}

