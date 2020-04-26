#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Laser.h"
#include <list>

using namespace std;

class Player
{
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	list<Laser *> lasers;

public:
	Player();

	void drawPlayer(sf::RenderWindow& window);
	void movePlayer(char direction, float moveSpeed);
	void setPosition(int x, int y);

	const sf::Vector2f& getPosition();
	const sf::Sprite& getSprite();

	void shoot();
	list<Laser*> getLasers();
};
