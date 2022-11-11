#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include"player.h"
#include"projectile.h"
#include"enemy.h"
#include"textDisplay.h"
#include"pickup.h"
#include"enemyBullet.h"
#include"menu.h"
#include"pause.h"
#include"boss.h"
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;
//random function
int generateRandom(int max)
{
	int randomNumber = rand();
	int  random = (randomNumber % max) + 1;
	int myRandom = random;
	return myRandom;
}
int main()
{
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::RenderWindow window(sf::VideoMode(1980, 1080), "RAGNARAK");
	window.setFramerateLimit(144);
	///////////////////////////-----------Set---------///////////////////////////////////////////
	int counter, counter2, counter3, bulletStyle = 1, windowscreen = 4;
	int hightscore[5];
	sf::String playerName;
	string hightName[5];
	sf::Texture textureSprite, textureEnemy, textureMap1, texturefire1, textureItem,texturebackground,textureMenu,textureBoss,textureSpeb,textureSpbs, textureGameover,textenteryourname;
	textureSprite.loadFromFile("spriteplayer.png");
	textureEnemy.loadFromFile("enemy.png");
	textureMap1.loadFromFile("map.png");
	texturefire1.loadFromFile("sppj.png");
	textureItem.loadFromFile("item.png");
	texturebackground.loadFromFile("backgound112.jpg");
	textureMenu.loadFromFile("menu.png");
	textureBoss.loadFromFile("boss.png");
	textureSpeb.loadFromFile("speb.png");
	textureSpbs.loadFromFile("Spbs.png");
	textureGameover.loadFromFile("gameover.png");
	textenteryourname.loadFromFile("enteryourname.png");

	sf::RectangleShape map1;
	map1.setTexture(&textureMap1);
	map1.setFillColor(sf::Color::White);
	map1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

	sf::RectangleShape background;
	background.setTexture(&texturebackground);
	background.setFillColor(sf::Color::White);
	background.setSize(sf::Vector2f(3840, 2160));
	background.setPosition(-900, -600);

	sf::RectangleShape background1;
	background1.setTexture(&textureGameover);
	background1.setFillColor(sf::Color::White);
	background1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	background1.setPosition(0,0);

	sf::RectangleShape background2;
	background2.setTexture(&textenteryourname);
	background2.setFillColor(sf::Color::White);
	background2.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	background2.setPosition(0, 0);


	sf::RectangleShape menuTexture;
	menuTexture.setTexture(&textureMenu);
	menuTexture.setFillColor(sf::Color::White);
	menuTexture.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	menuTexture.setPosition(0, 0);
	//Font ---------
	sf::Font font1;
	font1.loadFromFile("font.ttf");
	//music
	sf::SoundBuffer shot,pickupS,collisionS;
	shot.loadFromFile("shot.wav");
	pickupS.loadFromFile("pickup.wav");
	collisionS.loadFromFile("collition.wav");

	sf::Sound shotSound, pickupSound, collisionSound;
	shotSound.setBuffer(shot);
	shotSound.setVolume(50);
	pickupSound.setBuffer(pickupS);
	pickupSound.setVolume(20);
	collisionSound.setBuffer(collisionS);
	collisionSound.setVolume(50);

    sf::Music musicmenu;
	musicmenu.openFromFile("music.wav");
	musicmenu.setVolume(20);
	musicmenu.play();

	//---View----
	sf::View view1(sf::FloatRect(200, 200, 1980, 1080));
	view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	view1.setCenter(sf::Vector2f(window.getPosition().x / 2, window.getPosition().y / 2));
	window.setView(view1);
	//----Class objec player---//
	class player player1;

	player1.sprite.setTexture(textureSprite);
	//Projectile   VectorArray 
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;

	class projectile projectile1;
	projectile1.sprite.setTexture(texturefire1);

	class enemyBullet enemyBullet1;
	//projectile1.sprite.setTexture(texturefire1);
	//Enemy   VectorArray 
	vector<enemyBullet>::const_iterator iter13;
	vector<enemyBullet> enemyBulletArray;
	enemyBullet1.sprite.setTexture(textureSpeb);

	//Enemy   VectorArray 
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	

	class enemy enemy1;
	enemy1.rect.setPosition(600, 1000);
	enemy1.sprite.setTexture(textureEnemy);
	enemyArray.push_back(enemy1);

	//boss   VectorArray 
	vector<boss>::const_iterator iter21;
	vector<boss> bossArray;

	class boss boss1;
	boss1.rect.setPosition(600, 1000);
	boss1.sprite.setTexture(textureBoss);
	//bossArray.push_back(boss1);
	//pickup vector
	vector<pickup>::const_iterator iter11;
	vector<pickup> pickupArray;

	class pickup pickup1;
	pickup1.sprite.setTexture(textureItem);
	pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
	//pickup1.rect.setPosition(800, 800);
	//pickupArray.push_back(pickup1);

	//Text  VectorArray 
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArray;
	//----Text objec Text----//
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font1);
	textDisplay1.text.setPosition(300, 300);

	//Text  VectorArray 
	vector<textDisplay>::const_iterator iter23;
	vector<textDisplay> textLVArray;
	class textDisplay textLV;
	textLV.text.setFont(font1);
	textLV.text.setFillColor(sf::Color::Red);
	textLV.text.setPosition(300, 300);

	sf::Text textScore;
	textScore.setFont(font1);
	textScore.setFillColor(sf::Color::Yellow);
	textScore.setCharacterSize(50);

	sf::RectangleShape rectHp;
	rectHp.setFillColor(sf::Color::Green);
	//rectHp.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().x - 50);
	//rectHp.setSize(sf::Vector2f(player1.hp, 10));

	sf::RectangleShape rectMana;
	rectMana.setFillColor(sf::Color::Blue);
	//rectMana.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().x - 70);
	//rectMana.setSize(sf::Vector2f(player1.mana, 10));


	//set menu
	menu menu1(window.getSize().x, window.getSize().y);
	//set pause
	pause pause1(window.getSize().x, window.getSize().y);

	//file
	ifstream readscoreFile;
	ifstream readnameFile;
	/////////////////////////////////-------------Window loop--------------//////////////////////////////////////

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////---------------Clear Screen--------------///////////////////////////////////////

		if (windowscreen == 0)
		{
			std::cout << "state 0";
			while (true)
			{
				window.setView(view1);
				view1.setCenter(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
				sf::Text sumet;
				string namesumet = "63011013 Sumet Suansamran";
				sumet.setString(namesumet);
				sumet.setFont(font1);
				sumet.setCharacterSize(25);
				sumet.setPosition(0, 0);
				sumet.setFillColor(sf::Color::White);
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::W:
							menu1.moveUp();
							break;

						case sf::Keyboard::S:
							menu1.moveDown();
							break;
						case sf::Keyboard::Enter:
							if (menu1.selectedItem == 0)
							{
								windowscreen = 5;
								break;
							}
							if (menu1.selectedItem == 2)
							{
								window.close();
								break;
							}
							if (menu1.selectedItem == 1)
							{
								windowscreen = 6;
								break;
							}
						}
					}
					if (event.type == sf::Event::Closed)
						window.close();
				}
				if (windowscreen != 0)break;
				window.clear();
				window.draw(menuTexture);
				menu1.draw(window);
				window.draw(sumet);
				window.display();
			}
		}
		if (windowscreen == 1) {
			while (true)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					windowscreen = 2;
					break;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					
				}
				window.clear();
				window.draw(background);
				window.draw(map1);
				sf::Time elapsed1 = clock.getElapsedTime();
				sf::Time elapsed2 = clock2.getElapsedTime();
				sf::Time elapsed3 = clock3.getElapsedTime();
				//take Damage
				if (elapsed3.asSeconds() >= 0.5)
				{
					clock3.restart();
					counter = 0;
					for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
					{
						if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
						{
							player1.hp -= enemyArray[counter].attackDamage;
						}
						counter++;
					}
				}
				std::cout << player1.rect.getPosition().x << "  " << player1.rect.getPosition().y << endl;
				if (player1.rect.getPosition().x <= 1)
				{
					player1.rect.setPosition(1, player1.rect.getPosition().y);
				}
				if (player1.rect.getPosition().y <= 1)
				{
					player1.rect.setPosition(player1.rect.getPosition().x, 1);
				}
				if (player1.rect.getPosition().y >= 1030)
				{
					player1.rect.setPosition(player1.rect.getPosition().x, 1030);
				}
				if (player1.rect.getPosition().x >= 1950)
				{
					player1.rect.setPosition(1950, player1.rect.getPosition().y);
				}
				//////Projectile collision with Enemy////
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					counter2 = 0;
					for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
					{
						if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
						{
							collisionSound.play();
							std::cout << "Collision" << endl;
							//Text Display
							textDisplay1.text.setString(to_string(projectileArray[counter].attack));
							textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x, enemyArray[counter2].rect.getPosition().y);
							textDisplayArray.push_back(textDisplay1);

							//delete projectile
							projectileArray[counter].destroy = true;

							enemyArray[counter2].hp -= projectileArray[counter].attack;
							if (enemyArray[counter2].hp <= 0)
							{
								enemyArray[counter2].alive = false;
								//textLVArray.erase(iter23);
							}
						}
						counter2++;
					}
					counter++;
				}
				//////Projectile collision with Boss////
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					counter2 = 0;
					for (iter21 = bossArray.begin(); iter21 != bossArray.end(); iter21++)
					{
						if (projectileArray[counter].rect.getGlobalBounds().intersects(bossArray[counter2].rect.getGlobalBounds()))
						{
							collisionSound.play();
							std::cout << "Collision" << endl;
							//Text Display
							textDisplay1.text.setString(to_string(projectileArray[counter].attack));
							textDisplay1.text.setPosition(bossArray[counter2].rect.getPosition().x+90, bossArray[counter2].rect.getPosition().y+60);
							textDisplayArray.push_back(textDisplay1);

							//delete projectile
							projectileArray[counter].destroy = true;

							bossArray[counter2].hp -= projectileArray[counter].attack;
							if (bossArray[counter2].hp <= 0)
							{
								bossArray[counter2].alive = false;
							}
						}
						counter2++;
					}
					counter++;
				}
				//Check player collision enemy Bullet
				counter2 = 0;
				for (iter13 = enemyBulletArray.begin(); iter13 != enemyBulletArray.end(); iter13++)
				{
					if (player1.rect.getGlobalBounds().intersects(enemyBulletArray[counter2].rect.getGlobalBounds()))
					{
						collisionSound.play();
						if (enemyBulletArray[counter2].type == 1)
						{
							player1.hp -= enemy1.attackDamage;
							if (player1.hp <= 0)player1.hp = 0;
						}
						if (enemyBulletArray[counter2].type == 2)
						{
							player1.movementspeed = 0.5;
						}
						enemyBulletArray[counter2].destroy = true;
					}
					counter2++;
				}
				//pickup collision player
				counter2 = 0;
				for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
				{
					if (player1.rect.getGlobalBounds().intersects(pickupArray[counter2].rect.getGlobalBounds()))
					{
						pickupSound.play();
						if (pickupArray[counter2].item == 1)
						{
							projectile1.attack += 20;
						}
						if (pickupArray[counter2].item == 2)
						{
							player1.hp += 50;
						}
						if (pickupArray[counter2].item == 3)
						{
							player1.mana += 50;
						}
						if (pickupArray[counter2].item == 44)
						{
							projectile1.movementspeed += 0.2;
						}
						pickupArray[counter2].destroy = true;
					}
					counter2++;
				}

				//////-------------------------////
				//Check dead
				if (player1.hp <= 0)
				{
					windowscreen = 7;
					break;
				}
				//CHECK pickup delete
				counter = 0;
				for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
				{
					if (pickupArray[counter].destroy == true)
					{
						pickupArray.erase(iter11);
						counter = 0;
						break;
					}
					counter++;
				}
				//CHECK enemyBullet delete
				counter = 0;
				for (iter13 = enemyBulletArray.begin(); iter13 != enemyBulletArray.end(); iter13++)
				{
					if (enemyBulletArray[counter].destroy == true)
					{
						enemyBulletArray.erase(iter13);
						counter = 0;
						break;
					}
					counter++;
				}
				//check player kill
				if (player1.countKill >= 10)
				{
					player1.countKill = 0;
					enemy1.hp += 10;
					enemy1.attackDamage += 2;
					if (enemyBullet1.movementspeed <= 4)
					{
						enemyBullet1.movementspeed += 0.5;
					}
					boss1.hp = enemy1.hp * 10;
					boss1.rect.setPosition(generateRandom(1900), generateRandom(1000));
					bossArray.push_back(boss1);
				}
				//CHECK ENEMY ALIFE
				counter = 0;
				for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
				{
					if (enemyArray[counter].alive == false)
					{
						cout << "alive false" << endl;
						player1.countKill++;
						
						pickup1.item = generateRandom(7);
						if (pickup1.item == 1)
						{
							pickup1.rect.setFillColor(sf::Color::Red);
							pickup1.sprite.setTextureRect(sf::IntRect(3 * 24, 8 * 24, 24, 24));
							pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 2)
						{
							pickup1.rect.setFillColor(sf::Color::Green);
							pickup1.sprite.setTextureRect(sf::IntRect(10 * 24, 7 * 24, 24, 24));
							pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 3)
						{
							pickup1.rect.setFillColor(sf::Color::Blue);
							pickup1.sprite.setTextureRect(sf::IntRect(5 * 24, 13 * 24, 24, 24));
							pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 4)
						{
							pickup1.rect.setFillColor(sf::Color::Yellow);
							pickup1.sprite.setTextureRect(sf::IntRect(8 * 24, 8 * 24, 24, 24));
							pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						enemyArray.erase(iter4);
						counter = 0;
						for (int i = 0; i < 1; i++)
						{
							enemy1.rect.setPosition(generateRandom(1900), generateRandom(1000));
							enemy1.lv++;
							textLV.text.setString(to_string(enemy1.lv));
							textLV.text.setPosition(enemy1.rect.getPosition().x - 60, enemy1.rect.getPosition().y + 60);
							enemyArray.push_back(enemy1);
							//textLVArray.push_back(textLV);
						}
						player1.score += 10;
						break;
					}
					counter++;
				}
				//CHECK Boss ALIFE
				counter = 0;
				for (iter21 = bossArray.begin(); iter21 != bossArray.end(); iter21++)
				{
					if (bossArray[counter].alive == false)
					{
						cout << "alive false" << endl;
						player1.countKill++;

						pickup1.item = generateRandom(15);
						if (pickup1.item == 1)
						{
							pickup1.rect.setFillColor(sf::Color::Red);
							pickup1.sprite.setTextureRect(sf::IntRect(3 * 24, 8 * 24, 24, 24));
							pickup1.rect.setPosition(bossArray[counter].rect.getPosition().x, bossArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 2)
						{
							pickup1.rect.setFillColor(sf::Color::Green);
							pickup1.sprite.setTextureRect(sf::IntRect(10 * 24, 7 * 24, 24, 24));
							pickup1.rect.setPosition(bossArray[counter].rect.getPosition().x, bossArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 3)
						{
							pickup1.rect.setFillColor(sf::Color::Blue);
							pickup1.sprite.setTextureRect(sf::IntRect(5 * 24, 13 * 24, 24, 24));
							pickup1.rect.setPosition(bossArray[counter].rect.getPosition().x, bossArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						if (pickup1.item == 4)
						{
							pickup1.rect.setFillColor(sf::Color::Yellow);
							pickup1.sprite.setTextureRect(sf::IntRect(8 * 24, 8 * 24, 24, 24));
							pickup1.rect.setPosition(bossArray[counter].rect.getPosition().x, bossArray[counter].rect.getPosition().y);
							pickupArray.push_back(pickup1);
						}
						bossArray.erase(iter21);
						counter = 0;
						player1.score += 100;
						break;
					}
					counter++;
				}
				//CHECK ENEMY FOLLOW
				counter = 0;
				for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
				{
					if (enemyArray[counter].followCheck == true)
					{
						enemyArray[counter].follow(player1.rect.getPosition().x, player1.rect.getPosition().y);
						int ran = generateRandom(1000);
						if (ran == 5)
						{
							enemyBullet1.type = generateRandom(2);
							if (enemyBullet1.type == 1)
							{
								enemyBullet1.sprite.setTextureRect(sf::IntRect(0 * 30, 0, 30, 30));
								enemyBullet1.rect.setFillColor(sf::Color::Black);
							}
							if (enemyBullet1.type == 2)
							{
								enemyBullet1.sprite.setTextureRect(sf::IntRect(1 * 30, 0, 30, 30));
								enemyBullet1.rect.setFillColor(sf::Color::Green);
							}
							enemyBullet1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
							enemyBullet1.setupBullet(player1.rect.getPosition().x, player1.rect.getPosition().y);
							enemyBulletArray.push_back(enemyBullet1);
							cout << "PONGGGG" << endl;
							ran = 0;
						}
					}
					counter++;
				}
				//CHECK BOSS FOLLOW
				counter = 0;
				for (iter21 = bossArray.begin(); iter21 != bossArray.end(); iter21++)
				{
					if (bossArray[counter].followCheck == true)
					{
						bossArray[counter].follow(player1.rect.getPosition().x, player1.rect.getPosition().y);
						int ran = generateRandom(25);
						if (ran == 5)
						{
							enemyBullet1.type = generateRandom(1);
							if (enemyBullet1.type == 1)
							{
								enemyBullet1.rect.setRadius(20);
								enemyBullet1.sprite.setTexture(textureSpbs);
								enemyBullet1.sprite.setTextureRect(sf::IntRect(0 * 30, 0, 40, 40));
								enemyBullet1.rect.setFillColor(sf::Color::Black);
							}
							if (enemyBullet1.type == 2)
							{
								enemyBullet1.rect.setFillColor(sf::Color::Green);
							}
							enemyBullet1.rect.setPosition(bossArray[counter].rect.getPosition().x+70, bossArray[counter].rect.getPosition().y+60);
							enemyBullet1.setupBullet(player1.rect.getPosition().x, player1.rect.getPosition().y);
							enemyBulletArray.push_back(enemyBullet1);
							enemyBullet1.rect.setRadius(10);
							enemyBullet1.sprite.setTexture(textureSpeb);
							enemyBullet1.sprite.setTextureRect(sf::IntRect(0 * 30, 0, 30, 30));
							cout << "PONGGGG" << endl;
							ran = 0;
						}
					}
					counter++;
				}
				//CHECK DESTROY
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					if (projectileArray[counter].destroy == true)
					{
						cout << "destroy" << endl;
						projectileArray.erase(iter);
						break;
					}
					counter++;
				}
				//CHECK BULLET DESTROY
				counter = 0;
				for (iter13 = enemyBulletArray.begin(); iter13 != enemyBulletArray.end(); iter13++)
				{
					if (enemyBulletArray[counter].destroy == true)
					{
						cout << "destroyBullet" << endl;
						enemyBulletArray.erase(iter13);
						break;
					}
					counter++;
				}
				//delete Text
				counter = 0;
				for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
				{
					if (textDisplayArray[counter].destroy == true)
					{
						cout << "text Destroy" << endl;
						textDisplayArray.erase(iter8);
						counter = 0;
						break;
					}
					counter++;
				}
				//delete Text
				counter = 0;
				for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
				{
					if (pickupArray[counter].destroy == true)
					{
						cout << "pickup Destroy" << endl;
						pickupArray.erase(iter11);
						counter = 0;
						break;
					}
					counter++;
				}
				//When press space it'll fire
				if (elapsed1.asSeconds() >= 0.15)
				{
					clock.restart();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
					{
						if (player1.mana >= 10)
						{
							shotSound.play();
							projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
							projectile1.direction = player1.direction;
							projectileArray.push_back(projectile1);
							player1.mana -= 2;

						}
					}
				}
				if (elapsed1.asSeconds() >= 0.15)
				{
					clock.restart();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
					{
						if (player1.mana >= 10)
						{
							shotSound.play();
							projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
							projectile1.direction = 1;
							projectileArray.push_back(projectile1);
							projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
							projectile1.direction = 2;
							projectileArray.push_back(projectile1);
							projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
							projectile1.direction = 3;
							projectileArray.push_back(projectile1);
							projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
							projectile1.direction = 4;
							projectileArray.push_back(projectile1);
							player1.mana -= 5;
						}
					}
				}
				if (elapsed1.asSeconds() >= 0.15)
				{
					clock.restart();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
					{
						if (player1.mana >= 5)
						{
							shotSound.play();
							if (player1.direction == 1 || player1.direction == 3)
							{
								projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
								projectile1.direction = player1.direction;
								projectileArray.push_back(projectile1);
								projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
								projectile1.direction = player1.direction + 1;
								projectileArray.push_back(projectile1);
								player1.mana -= 2;
							}
							else
							{
								projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
								projectile1.direction = player1.direction;
								projectileArray.push_back(projectile1);
								projectile1.rect.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
								projectile1.direction = player1.direction - 1;
								projectileArray.push_back(projectile1);
								player1.mana -= 3;
							}
						}
					}
				}
				if (elapsed2.asSeconds() >= 0.1)
				{
					clock2.restart();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
					{
						enemy1.rect.setPosition(generateRandom(1980), generateRandom(1080));
						enemyArray.push_back(enemy1);
					}
				}
				//Draw Pickup
				counter = 0;
				for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
				{
					pickupArray[counter].update();
					//window.draw(pickupArray[counter].rect);
					window.draw(pickupArray[counter].sprite);
					counter++;
				}
				//Draw Projectile
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray[counter].update();
					//window.draw(projectileArray[counter].sprite);
					window.draw(projectileArray[counter].sprite);
					counter++;
				}
				//Draw enemyBullet
				counter = 0;
				for (iter13 = enemyBulletArray.begin(); iter13 != enemyBulletArray.end(); iter13++)
				{
					enemyBulletArray[counter].update(enemyBulletArray[counter].dir_x, enemyBulletArray[counter].dir_y);
					window.draw(enemyBulletArray[counter].sprite);
					//window.draw(pickupArray[counter].rect);
					counter++;
				}
				//Drqw Enemy
				counter = 0;
				for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
				{
					enemyArray[counter].update();
					if (enemyArray[counter].followCheck == false)
					{
						enemyArray[counter].updateMovement();
					}
					//window.draw(enemyArray[counter].rect);
					window.draw(enemyArray[counter].sprite);
					counter++;
				}
				//Drqw Enemy
				counter = 0;
				for (iter21 = bossArray.begin(); iter21 != bossArray.end(); iter21++)
				{
					bossArray[counter].update();
					if (bossArray[counter].followCheck == false)
					{
						bossArray[counter].updateMovement();
					}
					//window.draw(bossArray[counter].rect);
					window.draw(bossArray[counter].sprite);
					counter++;
				}
				//Draw score
				textScore.setString(to_string(player1.score));
				textScore.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y - 100);
				window.draw(textScore);
				//Draw hp
				rectHp.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y + 50);
				rectHp.setSize(sf::Vector2f(player1.hp, 10));
				window.draw(rectHp);
				//Draw mana
				rectMana.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y + 70);
				rectMana.setSize(sf::Vector2f(player1.mana, 10));
				window.draw(rectMana);
				//update mana
				player1.manaPlayer();
				//Update player
				player1.update();
				player1.updateMovement();
				//update picup
				pickup1.update();
				//View player
				window.setView(view1);
				view1.setCenter(player1.rect.getPosition());

				//Draw player
				window.draw(player1.sprite);
				//Draw weapon
				//weapon.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
				//window.draw(weapon);
				//Draw Text
				counter = 0;
				for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
				{
					window.draw(textDisplayArray[counter].text);
					textDisplayArray[counter].update();
					counter++;
				}
				//Draw Text
				counter = 0;
				for (iter23 = textLVArray.begin(); iter23 != textLVArray.end(); iter23++)
				{
					textLVArray[counter].text.setPosition(enemyArray[counter].rect.getPosition().x - 60, enemyArray[counter].rect.getPosition().y + 60);
					window.draw(textLVArray[counter].text);
					//textLVArray[counter].update();
					counter++;
				}
				//Update window
				window.display();
			}
		}
		if (windowscreen == 2) {
			std::cout << "state 2";
			while (true)
			{
				window.setView(view1);
				view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
				///window.setView(view1);
				//view1.setCenter(window.getPosition());
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::W:
							pause1.moveUp();
							break;

						case sf::Keyboard::S:
							pause1.moveDown();
							break;
						case sf::Keyboard::Enter:
							if (pause1.selectedItem == 0)
							{
								windowscreen = 1;
								break;
							}
							if (pause1.selectedItem == 1)
							{
								windowscreen = 0;
								break;
							}
						}
					}
					if (event.type == sf::Event::Closed)
						window.close();
				}
				if (windowscreen != 2)break;
				window.clear();
				pause1.draw(window);
				window.display();
			}
		}
		if (windowscreen == 3)
		{
			std::cout << "state 3";
			player1.countKill = 0;
			int enemyLv = 0;
			player1.hp = 100;
			player1.mana = 100;
			player1.score = 0;
			counter = 0;
			player1.movementspeed = 1.5;
			boss1.hp = 100;
			enemy1.attackDamage = 2;
			enemy1.hp = 100;
			projectile1.attack = 30;
			
			for (int z = 0; z < 100; z++)
			{
				for (iter13 = enemyBulletArray.begin(); iter13 != enemyBulletArray.end(); iter13++)
				{
					enemyBulletArray.erase(iter13);
					break;
				}
				counter = 0;
				for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
				{
					enemyArray.erase(iter4);
					break;
					counter++;
				}
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					projectileArray.erase(iter);
					break;
					counter++;
				}
				counter = 0;
				for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
				{
					pickupArray.erase(iter11);
					break;
					counter++;
				}
				counter = 0;
				for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
				{
					textDisplayArray.erase(iter8);
					break;
					counter++;
				}
				counter = 0;
				for (iter21 = bossArray.begin(); iter21 != bossArray.end(); iter21++)
				{
					bossArray.erase(iter21);
					break;
					counter++;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				enemy1.rect.setPosition(generateRandom(1900), generateRandom(1000));
				enemyArray.push_back(enemy1);
			}
			windowscreen = 1;
		}
		if (windowscreen == 4)
		{
			windowscreen = 0;
			int chang = 0,chang1=0;
			//windowscreen = 0;
			string nubscore;
			//read score
			int i = 0;
			readscoreFile.open("Score.txt");
			if (readscoreFile.is_open() == 1)
			{
				while (getline(readscoreFile, nubscore) && i < 5)
				{
					hightscore[i] = stoi(nubscore);
					i++;
				}
			}
			readscoreFile.close();
			cout << hightscore[0] << endl;
			cout << hightscore[1] << endl;
			cout << hightscore[2] << endl;
			cout << hightscore[3] << endl;
			cout << hightscore[4] << endl;

			//write score
			ofstream writescoreFile;
			writescoreFile.open("Score.txt");
			if (writescoreFile.is_open() == 1)
			{
				for (int i = 0; i < 5; i++)
				{
					if (player1.score > hightscore[i])
					{
						chang = 1;
						chang1 = i;
						for (int j = 4; j > i; j--)
						{
							hightscore[j] = hightscore[j - 1];
						}
						hightscore[i] = player1.score;
						break;
					}
				}
				for (int j = 0; j < 5; j++)
				{
					writescoreFile << hightscore[j] << endl;
				}
			}
			writescoreFile.close();
			//read name
			i = 0;
			readnameFile.open("playername.txt");
			if (readnameFile.is_open() == 1)
			{
				while (getline(readnameFile, nubscore) && i < 5)
				{
					hightName[i] = nubscore;
					i++;
				}
			}
			readnameFile.close();
			cout << hightName[0] << endl;
			cout << hightName[1] << endl;
			cout << hightName[2] << endl;
			cout << hightName[3] << endl;
			cout << hightName[4] << endl;
			//write name
			ofstream writenameFile;
			writenameFile.open("playername.txt");
			if (writenameFile.is_open() == 1)
			{
				for (int i = 0; i < 5; i++)
				{
					if (chang==1)
					{
						chang = 0;
						//chang1 = i;
						for (int j = 4; j > i; j--)
						{
							hightName[j] = hightName[j - 1];
						}
						hightName[i] = playerName;
						break;
					}
				}
				for (int j = 0; j < 5; j++)
				{
					writenameFile << hightName[j] << endl;
				}
			}
			writescoreFile.close();
		}
		if (windowscreen == 5)
		{
			window.setView(view1);
			view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
			string Entername = "ENTERYOURNAME ";
			sf::Texture texture;
			sf::Text Text;
			sf::Text Text1;
			sf::RectangleShape background;

			background.setSize(sf::Vector2f(1080, 720));
			Text.setPosition(1980 / 2 , 1080 / 2 - 110);
			Text.setCharacterSize(50);
			Text.setFillColor(sf::Color::Black);
			Text.setFont(font1);

			Text1.setPosition(1980 / 2 - 230, 1080 / 2 - 110);
			Text1.setCharacterSize(50);
			Text1.setFillColor(sf::Color::Black);
			Text1.setFont(font1);
			Text1.setString(Entername);


			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128)
						{
							if (event.text.unicode == static_cast <sf::Uint32>(8) && playerName.getSize() > 0)
							{
								playerName.erase(playerName.getSize() - 1);
							}
							else
							{
								if (playerName.getSize() < 100 && event.text.unicode != 13)
								{
									if (event.text.unicode == 32)
									{
										event.text.unicode = 95;
									}
									playerName += event.text.unicode;
								}
							}
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && playerName.getSize() >= 1)
				{
					windowscreen = 3;
					break;
				}
				window.clear();
				Text.setString(playerName);
				window.draw(menuTexture);
				window.draw(background2);
				window.draw(Text);
				window.draw(Text1);
				window.display();
			}


		}
		if(windowscreen==6)
		{
			window.setView(view1);
			view1.setCenter(sf::Vector2f(window.getSize().x / 2-50, window.getSize().y / 2));
			ostringstream sctostring;
			sctostring << player1.score;
			sf::Text lblNamePlayer, lblScorePlayer,Scorelbl[5],Namelbl[5];
			sf::Text textL;
			string gameover = "LEADERBOARD";
			textL.setString(gameover);
			textL.setFont(font1);
			textL.setCharacterSize(100);
			textL.setPosition(window.getSize().x + 200, window.getSize().y / 2-50);
			textL.setFillColor(sf::Color::White);

			ostringstream arragesc[6];

			for (int i = 0; i < 5; i++)
			{
				arragesc[i] << hightscore[i];
			}
			for (int i = 0; i < 5; i++)
			{
				Scorelbl[i].setFont(font1);
				Scorelbl[i].setCharacterSize(50);
				Scorelbl[i].setFillColor(sf::Color::Black);
				Scorelbl[i].setString(arragesc[i].str());
				Namelbl[i].setFont(font1);
				Namelbl[i].setCharacterSize(50);
				Namelbl[i].setFillColor(sf::Color::Black
				);
				Namelbl[i].setString(hightName[i]);
			}
			Scorelbl[0].setPosition(718*2, 200);
			Scorelbl[1].setPosition(718*2, 300);
			Scorelbl[2].setPosition(718*2, 400);
			Scorelbl[3].setPosition(718*2, 500);
			Scorelbl[4].setPosition(718*2, 600);
			Namelbl[0].setPosition(262, 200);
			Namelbl[1].setPosition(262, 300);
			Namelbl[2].setPosition(262, 400);
			Namelbl[3].setPosition(262, 500);
			Namelbl[4].setPosition(262, 600);
			while (true)
			{
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Enter:
							windowscreen = 0;
							break;
						case sf::Keyboard::Escape:
							windowscreen = 0;
							break;
						}
					}
				}
				if (windowscreen == 0)
				{
					break;
				}
				window.clear();
				window.draw(menuTexture);
				window.draw(textL);

				for (int i = 0; i < 5; i++)
				{
					window.draw(Scorelbl[i]);
					window.draw(Namelbl[i]);
				}
				window.display();
			}

		}
		if (windowscreen == 7)
		{
			window.setView(view1);
			view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
			sf::Text textover;
			string gameover = "GAME OVER";
			textover.setString(gameover);
			textover.setFont(font1);
			textover.setCharacterSize(100);
			textover.setPosition((window.getPosition().x / 2)+200, window.getPosition().y /2+150);
			textover.setFillColor(sf::Color::White);
			while (true)
			{
				window.setView(view1);
				view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Enter:
							windowscreen = 4;
							break;
						case sf::Keyboard::Escape:
							windowscreen = 4;
							break;
						}
					}
				}
				window.clear();
				window.draw(background1);
				//window.draw(textover);
				window.display();
				if (windowscreen == 4)
				{
					break;
				}
			}
		}
	}
		//return 0;
	return 0;
}
        
//Draw vertorarray thing
/*
int counter = 0;
for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
{
	projectileArray[counter].update();
	window.draw(projectileArray[counter].rect);
	counter++;
}
*/