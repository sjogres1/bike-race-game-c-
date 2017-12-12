//
//  Interface.hpp
//  Hillside1
//

#ifndef Hillside1_Interface_hpp
#define Hillside1_Interface_hpp

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Interface
{
public:
	
	static void playerKeyboard(sf::Event event, Player* player)
	{
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)//(event.key.code)
			{
				case sf::Keyboard::Down:
					player->backwards();
					break;
					
				case sf::Keyboard::Space:
					player->stop();
					break;
					
				case sf::Keyboard::Up:
					player->forward();
					break;
			}
		}// else  {
		//	player->decreaseSpeed();
		//}
	}

};

#endif