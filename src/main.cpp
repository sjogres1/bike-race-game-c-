#include <Box2D/Box2D.h>
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Screens.hpp"
#include <vector>

int main(){

    std::vector<Screen*> screens;
    int screen = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //TODO:fetch screen size from a separate file to unify
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Hillside Racing", sf::Style::Default, settings);

    MainMenu mm;
    screens.push_back (&mm);

    Game g;
    screens.push_back(&g);

    while (screen >= 0) {
        screen = screens[screen]->open(window);
        if(screen == GAMESTATE_GAME) {g.open(window);}
   }
}