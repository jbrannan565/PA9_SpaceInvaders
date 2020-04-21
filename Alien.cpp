#include "Alien.h"

//Constructor for alien object. Sets hit paramaters and loads texture to create sprite
Alien::Alien(float xPos, float yPos) {
	currHits = 0; //starts with 0 hits, will be updated when hit by laser
	maxHits = 0; // this will change in the inherited classes 
	if (!pTexture.loadFromFile("alienDefault6.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
}

//draws the alien to the window
void Alien::drawAlien(sf::RenderWindow& window){
	window.draw(pSprite);
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
const sf::Vector2f& Alien::getPosition() {
	return pSprite.getPosition();
}
