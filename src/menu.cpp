#include <iostream>
#include "menu.hpp"


Menu::Menu(float width, float height) 
{
	selectedItemIndex = 0;
	if(!font.loadFromFile("LemonMilk.otf")){
	  	std::cout << "Error loading font file";
		system ("pause");
	}
        
        
        //The actual options in the menu defined (font, color, text and position)
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Levels");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS+1)*1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("Instructions");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS+1)*2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setString("Highscores");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS+1)*3));


  	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Black);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS+1)*4));

	selectedItemIndex = 0;
}

Menu::~Menu(){
	selectedItemIndex = 0;
}

 	//background.setSize(sf::Vector2f(1024, 768));
    //background.setFillColor(sf::Color(30,30,30));


	
	void Menu::draw(sf::RenderWindow &window){
            for(int i =0; i< MAX_NUMBER_OF_ITEMS; i++){
                window.draw(menu[i]);
            }
	}

	void Menu::MoveUp(){
            if (selectedItemIndex - 1 >= 0){
                    menu[selectedItemIndex].setColor(sf::Color::Black);
                    selectedItemIndex--;
                    menu[selectedItemIndex].setColor(sf::Color::Red);
            }
	}

	void Menu::MoveDown(){
            if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
                    menu[selectedItemIndex].setColor(sf::Color::Black);
                    selectedItemIndex++;
                    menu[selectedItemIndex].setColor(sf::Color::Red);
            }
	}
