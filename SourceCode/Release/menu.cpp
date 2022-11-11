#include "menu.h"
menu::menu(float width, float hight)
{
	font.loadFromFile("font.ttf");

	text[0].setCharacterSize(72);
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("PLAY");
	text[0].setPosition(sf::Vector2f(1980 / 2, 1080 / (totalButton+1) * 1));
	text[0].setOrigin(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height / 2);
	
	text[1].setCharacterSize(72);
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Black);
	text[1].setString("LEADERBOARD");
	text[1].setPosition(sf::Vector2f(1980 / 2, 1080 / (totalButton+1) * 2));
	text[1].setOrigin(text[1].getGlobalBounds().width / 2, text[1].getGlobalBounds().height / 2);
	
	text[2].setCharacterSize(72);
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Black);
	text[2].setString("EXIT");
	text[2].setPosition(sf::Vector2f(1980 / 2, 1080/ (totalButton+1) * 3));
	text[2].setOrigin(text[2].getGlobalBounds().width / 2, text[2].getGlobalBounds().height / 2);

}

void menu::draw(sf::RenderWindow &window)
{
	for (int y = 0; y < totalButton; y++)
	{
		window.draw(text[y]);
	}
}

void menu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		text[selectedItem].setFillColor(sf::Color::Black);
		selectedItem--;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}

void menu::moveDown()
{
	if (selectedItem + 1 < totalButton)
	{
		text[selectedItem].setFillColor(sf::Color::Black);
		selectedItem++;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}
