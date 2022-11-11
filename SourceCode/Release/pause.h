#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define totalButton 2
class pause
{
public:
	int selectedItem = 0;

	sf::Font font;
	sf::Text text[2];

	pause(float width, float hight);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
};

