#include "textDisplay.h"

textDisplay::textDisplay()
{
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(50);
	text.setPosition(300, 300);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -movementSpeed);
	counter++;
	if (counter >= lifeTime)
	{
		destroy = true;
	}
}
