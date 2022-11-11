
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class player
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	float movementspeed = 1.5;
	int attackDamage = 20;
	int counterWallking = 0;
	int direction = 0;
	int hp = 100;
	int score = 0;
	int countKill = 0;
	int mana = 100;
	int counterLifetime = 0;
	int lifeTime = 70;
	int counterLifetime1 = 0;
	int counterLifetime2 = 0;
	int lifeTime1 = 700;
	int lifeTime2 = 70;

	player();
	void update();
	void updateMovement();
	void manaPlayer();
private:
protected:
};

