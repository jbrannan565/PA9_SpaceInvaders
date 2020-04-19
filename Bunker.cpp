#include "Bunker.h"
#include <iostream>

Bunker::Bunker(float x, float y) {
	if (!bTexture.loadFromFile("bunker1.png"))
		std::cerr << "Error in Blayer constructor" << std::endl;
	bSprite.setTexture(bTexture);
	bSprite.setPosition(x, y);

	hits = 0;
}

void Bunker::drawBunker(sf::RenderWindow& window) {
	window.draw(bSprite);
}

void Bunker::takeHit() {
	hits++;
	std::cout << "Hits: " << hits << std::endl;
	switch (hits)
	{
	case 1:
		if (!bTexture.loadFromFile("bunker2.png"))
			std::cerr << "Error loading bunker image";
		bSprite.setTexture(bTexture);
		break;
	case 2:
		if (!bTexture.loadFromFile("bunker3.png"))
			std::cerr << "Error loading bunker image";
		bSprite.setTexture(bTexture);
		break;
	case 3:
		if (!bTexture.loadFromFile("bunker4.png"))
			std::cerr << "Error loading bunker image";
		bSprite.setTexture(bTexture);
		break;
	case 4:
		if (!bTexture.loadFromFile("bunker5.png"))
			std::cerr << "Error loading bunker image";
		bSprite.setTexture(bTexture);
		break;
	case 5:
		if (!bTexture.loadFromFile("bunker6.png"))
			std::cerr << "Error loading bunker image";
		bSprite.setTexture(bTexture);
		break;
	default:
		break;
	}
}
