#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Player
{
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;

public:
	Player() {
		if (!pTexture.loadFromFile("player.png"))
			std::cerr << "Error in Player constructor" << std::endl;
		pSprite.setTexture(pTexture);
		pSprite.setPosition(250-25, 700);
	}

	void drawPlayer(sf::RenderWindow& window) {
		window.draw(pSprite);
	}

	void movePlayer(char direction, float moveSpeed) {
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

	const sf::Vector2f& getPosition() {
		return pSprite.getPosition();
	}
};
