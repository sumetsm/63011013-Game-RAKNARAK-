#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class pickup
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	bool isCoin = true;
	bool destroy = false;
	int item;
	pickup();
	void update();
};

