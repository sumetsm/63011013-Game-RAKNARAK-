#include "enemyBullet.h"
enemyBullet::enemyBullet()
{
	rect.setFillColor(sf::Color(255,0,255));
	rect.setRadius(15);
}
void enemyBullet::setupBullet(float player_posx, float player_posy)
{
	distance = sqrt((player_posx - rect.getPosition().x) * (player_posx - rect.getPosition().x) + (player_posy - rect.getPosition().y) * (player_posy - rect.getPosition().y));
	dir_x = (player_posx - rect.getPosition().x) / distance;
	dir_y = (player_posy - rect.getPosition().y) / distance;
}
void enemyBullet::update(float dir_x, float dir_y)
{
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
		rect.move(dir_x * movementspeed, dir_y * movementspeed);
		//sprite.setTextureRect(sf::IntRect(counterWallking1 * 31, 47 * 1, 31, 47));
		//sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 1, 116, 116));
		counterLifetime++;
		if (counterLifetime >= lifeTime)
		{
			destroy = true;
		}
}
