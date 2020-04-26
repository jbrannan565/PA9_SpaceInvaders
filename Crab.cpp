#include "Crab.h"
#include "Collision.h"

Crab::Crab(float xPos, float yPos):Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("crab2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "crab2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
