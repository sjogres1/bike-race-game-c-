//
//  Game.hpp
//  Hillside1
//

#ifndef Hillside1_Game_hpp
#define Hillside1_Game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include "Interface.hpp"
#include <list>


namespace {
	const float WWidth = 1024;
	const float WHeight = 768;
	b2Vec2 gravity(0.0f, -9.8f);
	const float32 timeStep = 1.0f / 60.0f;
	const int32 velocityIterations = 8;
	const int32 positionIterations = 6;
        const float y_points = -500;
        const float x_points = 400;
}

class Game {
public:
    Game() {
        
    }
    
    ~Game() {
        
	}
	std::list<std::pair<float, float>> generateGroundPoints(int difficulty, int length){
		std::list<std::pair<float, float>> groundPoints;
		std::pair<float, float> coordinatesAtSection;
		std::pair<float, float> firstPair;
		std::pair<float, float> lastPair;
		int dice;
		firstPair.first = -20;
		firstPair.second = -10;
		groundPoints.push_back(firstPair);
		float r;

		for(int section = 0; section <= length; section = section + 5)
		{
			lastPair = groundPoints.back();
			coordinatesAtSection.first = section;
			r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			dice = rand() % 5;
			if (dice == 1){
				coordinatesAtSection.second = lastPair.second + r*difficulty;
			}
			if (dice == 0){
				coordinatesAtSection.second = lastPair.second - r*difficulty;
			}
			groundPoints.push_back(coordinatesAtSection);
		}
		return groundPoints;
	}

    void open(void) {
        sf::RenderWindow window(sf::VideoMode(WWidth, WHeight), "Hillside coin test", sf::Style::Default);
        
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
       
        sf::Font font;
        if(!font.loadFromFile("LemonMilk.otf")) {
            std::cout << "Font does not work";
        }
 		
                
 	
         
 		sf::View view = window.getDefaultView();
 		window.setView(view);
        sf::Texture texture;
        sf::Sprite background;
        sf::Vector2u TextureSize;
        sf::Vector2u WindowSize;
        if (!texture.loadFromFile("terrain_England_background.png"))
        {

        }
        else {
            TextureSize = texture.getSize();
            WindowSize = window.getSize();
            float ScaleX = ((float) WWidth / TextureSize.x) * 20;
            float ScaleY = ((float) WHeight / TextureSize.y) * 20;
            
            background.setTexture(texture);
            background.setScale(ScaleX, ScaleY);
            
        }
        
            

        
        //window.setView(view);
        b2World world(gravity, true);
        CoinListener cl;
        world.SetContactListener(&cl);
        auto groundPoints = generateGroundPoints(3, 500);
        Ground* ground = new Ground(&world, groundPoints);
        objects.push_back(ground);
        Player* player = new Player(&world);
        objects.push_back(player);
        
        for (size_t i = 1; i < 75; i++) {
            objects.push_back(new Coin(&world, player, 10*i, -14));
        }
        
       std::stringstream ss;
        ss << "Points: " << 0;
        font.loadFromFile("LemonMilk.otf");
        sf::Text atext;
        atext.setFont(font);
	atext.setCharacterSize(25);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::Blue);
	atext.setPosition(player->getPosition().x*20+x_points, -player->getPosition().y*20+y_points);
	atext.setString(ss.str()); 
	window.draw(atext);
        
       
        
        
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
				Interface::playerKeyboard(event, player);
			}
			
			sf::Time dt = clock.restart();
			float accumulator = dt.asSeconds();
			while (accumulator > 0.0f)
			{
				world.Step(timeStep, velocityIterations, positionIterations);
				accumulator -= timeStep;
			}

			// Set view to follow player
                        
                window.clear();
                        
             ss.clear();
            ss.str(std::string());
            ss << "Points: " << player->getPoints();
            atext.setString(ss.str()); 
            atext.setPosition(player->getPosition().x*20+x_points, -player->getPosition().y*20+y_points);          

            view.setCenter(player->getPosition().x*20+100, -player->getPosition().y*20-150);
             
             window.draw(background);
             window.draw(atext);
             window.setView(view);
                    
			//draw objects
			
                            for (auto obj : objects) {
                                obj->update();
                                obj->render(window);
                            }
			player->debugLog(std::cout);
			
		
			window.display();
		}
    }
	
	
private:
	sf::RenderWindow window;
        sf::ContextSettings settings;
	sf::Clock clock;
        sf::ContextSettings setting;
        std::vector<GameObject*> objects;
        std::vector<Coin> coins;
       
};

#endif