#include "Bunker.h"
#include <iostream>

Bunker::Bunker(float x, float y) {
	if (!bTexture.loadFromFile("bunker1.png"))
		std::cerr << "Error in Player constructor" << std::endl;
	bSprite.setTexture(bTexture);
	bSprite.setPosition(x, y);
}

void Bunker::drawBunker(sf::RenderWindow& window) {
	window.draw(bSprite);
}

