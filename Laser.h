#pragma once
#include <SFML/Graphics.hpp>

class Laser
{
private:
	sf::Sprite laser;
	sf::Texture lTexture;
	float x;
	float y;
	int count;
	char direction;
public:
	Laser(char start_direction);
	void shoot(float start_x, float start_y);
	void drawlaser(sf::RenderWindow& window);
	void movelaser();
	void stoplaser();
	const sf::Sprite& getSprite();
};
