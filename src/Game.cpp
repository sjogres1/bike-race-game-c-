#include "Game.hpp"
Game::Game() {}

Game::~Game() {}


int Game::open(sf::RenderWindow &window, int screen) {
        
        if(screen == 4){
            difficulty =0.2;
            map_length=400;
            //goal_points=50;
        }
        if(screen == 5){
            difficulty =0.3;
            map_length = 500;
            //goal_points=100;
        }
        
        if(screen == 6){
            difficulty =0.5;
            map_length=650;
            //goal_points=200;
            
        }
        
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        sf::Font font;
        if(!font.loadFromFile("LemonMilk.otf")) {
            std::cout << "Font does not work";
        }
        
 	sf::View view = window.getDefaultView();
 	window.setView(view);
        
        // Creates background for the game
        int counter = 0;
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
        auto groundPoints = ground->generateGroundPoints(difficulty ,map_length);
        
        // Draws map, pushes objects to the map and the player to the map
        ground->drawMap(&world, groundPoints);
        objects.push_back(ground);
        Player* player = new Player(&world);
        objects.push_back(player);
        
        // Creates text for points, speed and time spent
        PointsSpeedClock psc(player);
        
        // Saves terrain shapes, so that coins can be drawn smartly around the map
        std::vector<float> coinPointsX = {};
        std::vector<float> coinPointsY = {};
        for (auto i = groundPoints.begin(); i!=groundPoints.end(); i++) {
            coinPointsY.push_back(i->second);
            coinPointsX.push_back(i->first);
        }
        
        // Puts all the coins in the map
        for (size_t i = 1; i < groundPoints.size(); i++) {
            if( !(i % rand() % 5)) {
                objects.push_back(new Coin(&world, player, coinPointsX[i], coinPointsY[i] + 2 + rand() % 8));
            }
        }
        // Saves the last point of the map, so that we can put the goal there
        auto lastpoint = groundPoints.back();
        auto lastx = lastpoint.first;
        auto lasty = lastpoint.second;
        
        // Puts goal at the end of the map
        auto goal = new Goal(&world, player, lastx, lasty);
        objects.push_back(goal);
        
        
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
            // Puts background in the center of the screen, so that it looks cool
            bgx = player->getPosition().x*20*BGSPEED;
            bgy = player->getPosition().y*20*BGSPEED;
            if (bgx<0) bgx=0;
            if (bgx>bgw-WWidth) bgx=bgw-WWidth;
            if (-bgy<0) bgy=0;
            if (-bgy>bgh-WHeight) bgy=-bgh+WHeight;
            bg.setPosition(-bgx,bgy);
            window.draw(bg);
            
            
            // Set view to follow player
            window.setView(view);
            view.setCenter(player->getPosition().x*20+100, -player->getPosition().y*20-150);
            //draw objects to the map all the time, 60 times per second
            for (auto obj : objects) {
                obj->update();
                obj->render(window);
            }
            // checks if goal is reached
            if(goal->getCollected() ) {
                player->increasePoints(50);
                psc.update();
                psc.getFinish();
                counter++;
                
            }
            window.setView(window.getDefaultView());
            psc.update();
            window.draw(psc);
            
            //player->debugLog(std::cout);
            if(goal->getCollected() ) {
                if(counter > 1){
                    usleep(1000000);
                    usleep(1000000);
                    usleep(1000000);
                    //TODO set "camera" back to original position
                    window.clear();
                    objects.clear();
                    window.setView(window.getDefaultView());
                    window.setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
                    return GAMESTATE_MAINMENU;
                }
            }
            
            window.display();
        }
        //temporary solution
        return -1;
    }