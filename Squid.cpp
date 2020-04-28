#include "Squid.h"
#include "Collision.h"

/*
Name: Squid Constructor
Description: sets the Squid sprite to the squid2.png image, and creates a bitmap for colliosions.
Then it sets the initial position of Squid sprite to xPos, yPos
*/
Squid::Squid(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("squid2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "squid2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
