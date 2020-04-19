#pragma once
#include <SFML/Graphics.hpp>

class HUD
{
private:
	int score;
	int lives;

public:
	HUD();

	void increaseScore(int amount);

	void decrementLives();

	void drawLivesSprites(sf::RenderWindow& window);

	void drawScore(sf::RenderWindow& window);

};

