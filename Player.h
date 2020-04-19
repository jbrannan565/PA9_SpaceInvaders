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
};
