#include "Octopus.h"
#include "Collision.h"

/*
Name: Octopus Constructor
Description: sets the Octopus sprite to the octopus2.png image and creates a bitmap for colliosions.
Then it sets the initial position of Octopus sprite to xPos, yPos
*/
Octopus::Octopus(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("octopus2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "octopus2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
