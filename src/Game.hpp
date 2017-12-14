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
#include "DEFINITIONS.hpp"


namespace {
    const float WWidth = 1024;
    const float WHeight = 768;
    b2Vec2 gravity(0.0f, -9.8f);
    const float32 timeStep = 1.0f / 60.0f;
    const int32 velocityIterations = 8;
    const int32 positionIterations = 6;
    const float y_points = -500;
    const float x_points = 400;
    const int map_length = 40;
}

class Game : public Screen{
    public:
    Game() {
        
    }
    
    ~Game() {
        
    }
    
    
    
    int open(sf::RenderWindow &window) {
        
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        sf::Font font;
        if(!font.loadFromFile("LemonMilk.otf")) {
            std::cout << "Font does not work";
        }
        
 	sf::View view = window.getDefaultView();
 	window.setView(view);
        
        
        // Creates background for the game
        
        sf::Texture background;
        sf::RectangleShape bg;
        float bgx, bgy;
        float bgw, bgh;
        bgw = WWidth*2;
        bgh = WHeight*1.5;
        background.loadFromFile("terrain_England_background.png");
        bg.setPosition(0,0);
        bg.setSize(sf::Vector2<float>(bgw,bgh));
        bg.setTexture(&background);
            
        
        
        
        
        // Creates gravity
        b2World world(gravity, true);
        
        // Creates coin and goal listeners
        CoinListener cl;
        GoalListener gl;
        world.SetContactListener(&cl);
        world.SetContactListener(&gl);
        
        // Sets up map terrain and generates a randomgenerated map
        Ground* ground = new Ground();
        auto groundPoints = ground->generateGroundPoints(3,map_length);
        
        // Saves the last point of the map, so that we can put the goal there
        auto lastpoint = groundPoints.back();
        auto lastx = lastpoint.first;
        auto lasty = lastpoint.second;
        
        // Saves terrain shapes, so that coins can be drawn smartly around the map
        std::vector<float> coinPointsX = {};
        std::vector<float> coinPointsY = {};
        for (auto i = groundPoints.begin(); i!=groundPoints.end(); i++) {
            coinPointsY.push_back(i->second);
            coinPointsX.push_back(i->first);
        }
        
        
        // Draws map, pushes objects to the map and the player to the map
        ground->drawMap(&world, groundPoints);
        objects.push_back(ground);
        Player* player = new Player(&world);
        objects.push_back(player);
        
        
        // Puts all the coins in the map
        for (size_t i = 1; i < groundPoints.size(); i++) {
            if( !(i % rand() % 5)) {
                objects.push_back(new Coin(&world, player, coinPointsX[i], coinPointsY[i] + 2 + rand() % 8));
            }
        }
        
        // Puts goal at the end of the map
        auto goal = new Goal(&world, player, lastx, lasty);
        objects.push_back(goal);
        
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
        
        
        
        // Game loop
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
            
            
            
            window.clear();
            //Set Background to follow player
            window.setView(window.getDefaultView());
            bgx = player->getPosition().x*20*BGSPEED;
            bgy = player->getPosition().y*20*BGSPEED;
            if (bgx<0) bgx=0;
            if (bgx>bgw-WWidth) bgx=bgw-WWidth;
            if (-bgy<0) bgy=0;
            if (-bgy>bgh-WHeight) bgy=-bgh+WHeight;
            bg.setPosition(-bgx,bgy);
            
            
            
            // The points follow player
            atext.setPosition(player->getPosition().x*20+x_points, -player->getPosition().y*20+y_points);           
            ss.clear();
            ss.str(std::string());
            ss << "Points: " << player->getPoints();
            atext.setString(ss.str()); 
            // Set view to follow player
            view.setCenter(player->getPosition().x*20+100, -player->getPosition().y*20-150);
          
           
            
            window.draw(bg);
            window.draw(atext);
            window.setView(view);
            
            //draw objects to the map all the time, 60 times per second
            //player->update();
            //for (auto obj : objects)
            for (auto obj : objects) {
                obj->update();
                obj->render(window);
            }
            //player->debugLog(std::cout);
            if(goal->getCollected() ) {
                //TODO set "camera" back to original position
                window.clear();
                objects.clear();
                window.setView(window.getDefaultView());
                window.setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
                return GAMESTATE_MAINMENU;
            }
            
            window.display();
        }
        //temporary solution
        return -1;
    }
    
    
    private:
    sf::RenderWindow window;
    sf::ContextSettings settings;
    sf::Clock clock;
    sf::ContextSettings setting;
    std::vector<GameObject*> objects;
    std::vector<Coin> coins;
    std::vector<Goal> goal;
    
};

#endif