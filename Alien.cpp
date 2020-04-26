#include "Alien.h"
#include "Collision.h"

//Constructor for alien object. Sets hit paramaters and loads texture to create sprite
Alien::Alien(float xPos, float yPos) {
	currHits = 0; //starts with 0 hits, will be updated when hit by laser
	maxHits = 0; // this will change in the inherited classes 
	if (!pTexture.loadFromFile("alienDefault6.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "alienDefault6.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
}

//draws the alien to the window
void Alien::drawAlien(sf::RenderWindow& window){
	window.draw(pSprite);
	for (auto laser : lasers) {
		if (laser != nullptr)
			laser->drawlaser(window);
	}
}

//moves alien left, right, or down. 
void Alien::moveAlien(char direction, float alienSpeed){
	switch (direction)
	{
	case 'l':
		pSprite.move(-alienSpeed, 0);
		break;
	case 'r':
		pSprite.move(+alienSpeed, 0);
		break;
	case 'd':
		pSprite.move(0, +alienSpeed);
		break;
	default:
		break;
	}
}

//its unclear to me what this will be for, but for now it is here
sf::Vector2f Alien::getPosition() {
	return pSprite.getPosition();
}


const sf::Sprite& Alien::getSprite() {
	return pSprite;
}

void Alien::remove() {
	sf::Vector2f currPos = pSprite.getPosition();
	pSprite.setPosition(currPos.x,currPos.y + 10000);
};

/*
Name: Shoot
Description: Fires a laser starting from the player's current position
*/
void Alien::shoot() {
	sf::Vector2f currPos = pSprite.getPosition();
	Laser* laser = new Laser('d');
	laser->shoot(currPos.x + 10, currPos.y);
	lasers.push_front(laser);
}

/*
Name: getLasers
Description: Returns the vector of laser pointers
*/
list<Laser*> Alien::getLasers() {
	return lasers;
}


