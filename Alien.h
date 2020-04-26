#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Laser.h"

using namespace std;

class Alien
{
protected: 
	int currHits; // the current number of hits on the alien
	int maxHits; // the number of hits the alien takes before dying
	sf::Texture pTexture; // texture (the pixel images)
	sf::Sprite pSprite; // sprite (will be the texture + the shape)
	list<Laser *> lasers;

public:
	Alien(float xPos, float yPos); // constructor. X and Y positions for where the alien is placed on the screen (will be changed for each alien)
	void drawAlien(sf::RenderWindow& window); //draws the alien to the screen
	void moveAlien(char direction, float alienSpeed); //moves alien in a direction specified by the character (left, right, down)
	sf::Vector2f getPosition();
	const sf::Sprite& getSprite();
	void remove();
	void shoot();
	list<Laser*> getLasers();
};

