#include "Crab.h"

Crab::Crab(float xPos, float yPos):Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("crab2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
