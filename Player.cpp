#include "Player.h"
#include "Collision.h"

/*
Name: Player constructor
Description: loads player.png into a sprite for the player and creates a bitmap for collisions, 
then puts that player at (250-25, 700).
*/
Player::Player() {
	if (!pTexture.loadFromFile("player.png"))
		std::cerr << "Error in Player constructor" << std::endl;
	Collision::CreateTextureAndBitmask(pTexture, "player.png");
	pSprite.setTexture(pTexture);
	pSprite.setPosition(250-25, 700);
}

/*
Name: drawPlayer
Description: draws the player sprite on the provided window.
*/
void Player::drawPlayer(sf::RenderWindow& window) {
	window.draw(pSprite);
	for (auto laser : lasers) {
		if (laser != nullptr)
			laser->drawlaser(window);
	}
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


/*
Name: Shoot
Description: Fires a laser starting from the player's current position
*/
void Player::shoot() {
	sf::Vector2f currPos = pSprite.getPosition();
	Laser* laser = new Laser('u');
	laser->shoot(currPos.x + 20, currPos.y);
	lasers.push_front(laser);
}

/*
Name: getLasers
Description: Returns the vector of laser pointers
*/
list<Laser*> Player::getLasers() {
	return lasers;
}
/*
Name: getSprite
Description: returns the sprite of the player
*/
const sf::Sprite& Player::getSprite() {
	return pSprite;
}

/*
Name: setPosition	
Description: sets the player sprite position based on x and y
*/
void Player::setPosition(int x, int y) {
	pSprite.setPosition(sf::Vector2f(x, y));
}
