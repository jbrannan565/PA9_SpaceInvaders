#include "Bunker.h"
#include <iostream>

/*
Name: Bunker construcor
Description: Creates a bunker with the bunker1.png texture, and places the bunker at (x,y).
	Also init hits to 0.
*/
Bunker::Bunker(float x, float y) {
	if (!bTexture.loadFromFile("bunker1.png"))
		std::cerr << "Error in Blayer constructor" << std::endl;
	bSprite.setTexture(bTexture);
	bSprite.setPosition(x, y);

	hits = 0;
}

/*
Name: drawBunker
Description: draws the bunker sprite to window.
*/
void Bunker::drawBunker(sf::RenderWindow& window) {
	window.draw(bSprite);
}

/*
Name: takeHit
Description: Increments hits and changes the sprite of the bunker depending on the number of hits the
bunker has taken.
*/
void Bunker::takeHit() {
	sf::Vector2f curPos;
	hits++;
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
		curPos = bSprite.getPosition();
		bSprite.setPosition(curPos.x, curPos.y + 10000);
		break;
	default:
		break;
	}
}

/*
Name: getPosition
Description: returns a vector of the bunker's current position
*/
const sf::Vector2f& Bunker::getPosition() {
	return bSprite.getPosition();;
}
	
sf::Sprite Bunker::getSprite() {
	return bSprite;
}
