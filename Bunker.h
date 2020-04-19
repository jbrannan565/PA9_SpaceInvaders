#pragma once
#include <SFML/Graphics.hpp>

class Bunker
{
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;

public:
	Bunker();

	void drawBunker(sf::RenderWindow& window);

	void takeHit();

	const sf::Vector2f& getPosition();
};

