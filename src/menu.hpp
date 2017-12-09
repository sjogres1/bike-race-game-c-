#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{

private:
  int selectedItemIndex;                    //Currently selected menu choice
  sf::Font font;                            //Font of the menu
  sf::Text menu[MAX_NUMBER_OF_ITEMS];       //Boundary for the menu

public:
  Menu(float width, float height);
  ~Menu();

  //dDraw the menu
  void draw(sf::RenderWindow &window);

  //Handle the keyboard input
  void MoveUp();
  void MoveDown();
  //return the position of the selected item
  int GetPressedItem(){return selectedItemIndex;}
  
};

#endif
