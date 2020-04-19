#include "HUD.h"
#include <iostream>

/*
Name: HUD constructor
Description: Init lives to 3 and score to 0.
*/
HUD::HUD() {
	lives = 3;
	score = 0;
}

/*
Name: increaseScore
Description: Increments score by amount.
*/
void HUD::increaseScore(int amount) {
	score += amount;
}

/*
Name: decrementLives
Description: Decreases lives by 1.
*/
void HUD::decrementLives() {
	lives--;
}

/*
Name: drawLivesSprites
Description: Draw the number of lives to the bottom of the screen and a player sprite
	for each life minus 1 (to account for the current player).
*/
void HUD::drawLivesSprites(sf::RenderWindow& window) {
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text livesText;
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
		std::cerr << "Error loading arial font in HUD" << std::endl;
	// Draw lives as a number
	livesText.setFont(font);
	livesText.setString(std::to_string(lives));
	livesText.setPosition(250, 760);
	livesText.setCharacterSize(20);
	livesText.setFillColor(sf::Color::White);

	window.draw(livesText);

	// Draw lives as sprites
	if (!texture.loadFromFile("player.png"))
		std::cerr << "Error in HUD::drawLivesSprites" << std::endl;

	sprite.setTexture(texture);
	for (int i = 0; i < lives - 1; i++) {
		sprite.setPosition((i + 1) * 100 - 50, 750);
		window.draw(sprite);
	}
}

void HUD::drawScore(sf::RenderWindow& window) {
	sf::Text scoreText;
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
		std::cerr << "Error loading arial font in HUD" << std::endl;
	// Draw lives as a number
	scoreText.setFont(font);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setPosition(25, 50);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);

	window.draw(scoreText);


}
