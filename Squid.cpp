#include "Squid.h"
#include "Collision.h"

Squid::Squid(float xPos, float yPos) :Alien(xPos, yPos) {
	if (!pTexture.loadFromFile("squid2.png"))
		std::cerr << "Error in alien constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "squid2.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(xPos, yPos);
};
