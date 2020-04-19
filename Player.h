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
	Player();

	void drawPlayer(sf::RenderWindow& window);

	void movePlayer(char direction, float moveSpeed);

	const sf::Vector2f& getPosition();
};
