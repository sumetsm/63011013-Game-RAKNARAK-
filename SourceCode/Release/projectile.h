#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class projectile
{
public:
	sf::CircleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	sf::Mouse mouse;
	sf::Vector2f proDirec;
	int movementspeed = 5;
	int attack = 50;
	int direction = 0;
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 150;


	projectile();
	void update();
	//void updateMovement();
};


