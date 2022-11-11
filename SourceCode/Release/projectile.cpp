#include "projectile.h"
projectile::projectile()
{
	//rect.setSize(sf::Vector2f(36, 36));
	rect.setRadius(15);
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
	sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
}
void projectile::update()
{
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
	if (direction == 1)
	{
		rect.move(-movementspeed,0);
		sprite.setTextureRect(sf::IntRect(0*30, 0, 30, 30));
	}
	if (direction == 2)
	{
		rect.move(movementspeed,0);
		sprite.setTextureRect(sf::IntRect(1*30, 0, 30, 30));
	}
	if (direction == 3)
	{
		rect.move(0,-movementspeed);
		sprite.setTextureRect(sf::IntRect(2*30, 0, 30, 30));
	}
	if (direction == 4)
	{
		rect.move(0,movementspeed);
		sprite.setTextureRect(sf::IntRect(3*30, 0, 30, 30));
	}
	counterLifetime++;
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}
}
