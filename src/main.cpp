#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "HILLSIDE RACING");
	Menu menu (window.getSize().x, window.getSize().y);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
                            case sf::Event::KeyReleased:
                                switch (event.key.code){
                                    case sf::Keyboard::Up:
                                        menu.MoveUp();
                                        break;
                                    case sf::Keyboard::Down:
                                        menu.MoveDown();
                                        break;
                                    case sf::Keyboard::Return:
                                        switch (menu.GetPressedItem()){
                                            case 0:
                                                std::cout << "Open levels submenu" << std::endl;
                                                break;
                                            case 1:
                                                std::cout << "Open instructions" << std::endl;
                                                break;
                                            case 2:
                                                std::cout << "Open highscores" << std::endl;
                                                break;
                                            case 3:
                                                window.close();
                                                break;
                                        }
                                }
                                break;
                            
                            case sf::Event::Closed:
                                window.close();
                                break;
			}
		}


		window.clear(sf::Color::White);

		menu.draw(window);

		window.display();
	}
}
