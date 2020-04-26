#include "Octopus.h"
#include "Collision.h"

Octopus::Octopus(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("octopus2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "octopus2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
