#include "Octopus.h"

Octopus::Octopus(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("octopus2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
