#pragma once
#include <SFML/Graphics.hpp>

class Bunker
{
private:
	sf::Texture bTexture;
	sf::Sprite bSprite;

public:
	Bunker(float x, float y);

	void drawBunker(sf::RenderWindow& window);

	void takeHit();

	const sf::Vector2f& getPosition();
};

