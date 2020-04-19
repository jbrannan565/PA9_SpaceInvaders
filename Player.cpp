#include "Player.h"

/*
Name: Player constructor
Description: loads player.png into a sprite for the player, then puts that player
at (250-25, 700).
*/
Player::Player() {
	if (!pTexture.loadFromFile("player.png"))
		std::cerr << "Error in Player constructor" << std::endl;
	pSprite.setTexture(pTexture);
	pSprite.setPosition(250-25, 700);
}

/*
Name: drawPlayer
Description: draws the player sprite on the provided window.
*/
void Player::drawPlayer(sf::RenderWindow& window) {
	window.draw(pSprite);
}

/*
Name: movePlayer
Description: chages the player position by moveSpeed in the provided
direction.
*/
void Player::movePlayer(char direction, float moveSpeed) {
	switch (direction)
	{
		case 'l':
			pSprite.move(-moveSpeed, 0);
			break;
		case 'r':
			pSprite.move(moveSpeed, 0);
			break;
		default:
			break;
	}
}

/*
Name: getPosition
Description: returns a vectore of the player's current position.
*/
const sf::Vector2f& Player::getPosition() {
	return pSprite.getPosition();
}
