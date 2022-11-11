#include "pause.h"
pause::pause(float width, float hight)
{
	font.loadFromFile("font.ttf");

	text[0].setCharacterSize(72);
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("RESUME");
	text[0].setPosition(sf::Vector2f(width / 2, hight / (totalButton + 1) * 1));
	text[0].setOrigin(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height / 2);


	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("QUIT");
	text[1].setPosition(sf::Vector2f(width / 2, hight / (totalButton + 1) * 2));
	text[1].setOrigin(text[1].getGlobalBounds().width / 2, text[1].getGlobalBounds().height / 2);
}

void pause::draw(sf::RenderWindow& window)
{
	for (int y = 0; y < totalButton; y++)
	{
		window.draw(text[y]);
	}
}

void pause::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		text[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}

void pause::moveDown()
{
	if (selectedItem + 1 < totalButton)
	{
		text[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}
