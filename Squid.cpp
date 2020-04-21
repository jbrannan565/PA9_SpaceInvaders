#include "Squid.h"

Squid::Squid(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("squid2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
