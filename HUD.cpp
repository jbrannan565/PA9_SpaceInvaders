#include "HUD.h"

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

void HUD::drawLivesSprites(sf::RenderWindow& window) {
}

void HUD::drawScore(sf::RenderWindow& window) {
}
