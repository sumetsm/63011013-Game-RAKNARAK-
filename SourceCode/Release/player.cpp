#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(31, 47));
	rect.setPosition(1000, 700);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 31, 47));

}

void player::update()
{
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
}

void player::updateMovement()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-movementspeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWallking * 31, 47 * 1, 31, 47));
		direction = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(movementspeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWallking * 31, 47 * 2, 31, 47));
		direction = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking * 31, 47 * 3, 31, 47));
		direction = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, movementspeed);
		sprite.setTextureRect(sf::IntRect(counterWallking * 31, 47 * 0, 31, 47));
		direction = 4;
	}
	counterLifetime2++;
	if (counterLifetime2 >= lifeTime2)
	{
		counterWallking++;
		counterLifetime2 = 0;
		if (counterWallking == 2)
		{
			counterWallking = 0;
		}
	}

}
void player::manaPlayer()
{
	counterLifetime ++;
	
	if (mana < 0)
	{
		mana = 0;
	}
	if (counterLifetime >= lifeTime)
	{
		if (mana < 100) 
		{
			mana += 5;
			counterLifetime = 0;
		}
	}
	counterLifetime1++;
		if (counterLifetime1 >= lifeTime1)
		{
			movementspeed = 1.5;
			counterLifetime1 = 0;
		}
}
