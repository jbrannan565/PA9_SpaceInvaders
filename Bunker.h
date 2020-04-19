#pragma once
#include <SFML/Graphics.hpp>

class Bunker
{
private:
	sf::Texture bTexture;
	sf::Sprite bSprite;

public:
	Bunker();

	void drawBunker(sf::RenderWindow& window);

	void takeHit();

	const sf::Vector2f& getPosition();
};

