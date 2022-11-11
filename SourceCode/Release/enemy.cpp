#include "enemy.h"
#include<string.h>
enemy::enemy()
{
	rect.setSize(sf::Vector2f(31, 47));
	rect.setPosition(5000, 5000);
	rect.setFillColor(sf::Color::White);
	sprite.setTextureRect(sf::IntRect(0, 0, 31, 47));
}
void enemy::update()
{
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
}
void enemy::updateMovement()
{


	if (direction == 1)
	{
		rect.move(-movementspeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 1, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 1, 116, 116));

	}
	else if (direction == 2)
	{
		rect.move(movementspeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 2, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 2, 116, 116));

	}
	else if (direction == 3)
	{
		rect.move(0, -movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 3, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 3, 116, 116));

	}
	else if (direction == 4)
	{
		rect.move(0, movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 0, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 0, 116, 116));

	}
	else
	{

	}
	if (counterWallking1 == 2)
	{
		counterWallking1 = 0;
	}
	counterWallking1++;
	counterWallking++;
	if (counterWallking >= 50)
	{
		direction = generateRandom(15);
		counterWallking = 0;
	}

}


void enemy::follow(float player_posx, float player_posy)
{

	float distance = sqrt((player_posx - rect.getPosition().x) * (player_posx - rect.getPosition().x) + (player_posy - rect.getPosition().y) * (player_posy - rect.getPosition().y));
	float dir_x = (player_posx - rect.getPosition().x)/distance;
	float dir_y = (player_posy - rect.getPosition().y) / distance;
	if (dir_x < 0)
	{
		rect.move(dir_x*movementspeed, dir_y * movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 1, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 1, 116, 116));

	}
	else if (dir_x > 0 )
	{
		rect.move(dir_x*movementspeed, dir_y * movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 2, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 2, 116, 116));

	}
	else if (dir_y <0)
	{
		rect.move(dir_x * movementspeed, dir_y*movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 3, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 3, 116, 116));

	}
	else if (dir_y >0)
	{
		rect.move(dir_x * movementspeed, dir_y*movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 0, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 0, 116, 116));

	}
}
