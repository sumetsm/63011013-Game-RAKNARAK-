#include "pickup.h"
pickup::pickup()
{
	rect.setSize(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Yellow);
	//sprite.setTextureRect(sf::IntRect(0, 0, 116, 116));
}
void pickup::update()
{
	sprite.setPosition(rect.getPosition());
}
