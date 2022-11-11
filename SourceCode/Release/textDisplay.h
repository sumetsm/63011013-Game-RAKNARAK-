#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class textDisplay
{
public:
	sf::Text text;
	float movementSpeed = 1.5;
	int counter = 0;
	int lifeTime = 100;
	bool destroy = false;
	string myString="Default";
	textDisplay();
	void update();
};

