#include "Crab.h"
#include "Collision.h"

/*
Name: Crab
Description: sets the Crab sprite to the crab2.png image and creates a bitmap for colliosions.
Then it sets the initial position of Crab sprite to xPos, yPos
*/
Crab::Crab(float xPos, float yPos):Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("crab2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "crab2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
