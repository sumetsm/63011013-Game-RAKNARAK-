#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define totalButton 3
class menu
{
public:
	int selectedItem=0;
	
	sf::Font font;
	sf::Text text[3];

	menu(float width, float hight);
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
};

