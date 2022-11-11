#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class enemyBullet
{
public:
	sf::CircleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	float movementspeed = 2;
	float distance;
	float dir_y;
	float dir_x;
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 200;
	int type = 1;
	enemyBullet();
	void update(float dir_x, float dir_y);
	void setupBullet(float player_posx, float player_posy);
};

