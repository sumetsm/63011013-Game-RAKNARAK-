#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class enemy
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	float movementspeed = 0.5;
	int attackDamage = 2;
	int counterWallking = 0;
	int counterWallking1 = 0;
	int direction;
	int hp = 100;
	int lv = 1;
	bool alive = true;
	bool followCheck = true;
	int generateRandom(int max)
	{
		int randomNumber = rand();
		int random = (randomNumber % max) + 1;
		int myRandom = random;
		return myRandom;
	}



	enemy();
	void update();
	void updateMovement();
	//void followMove(float dir_x,float dir_y,float dt);
	void follow(float player_posx, float player_posy);
};

