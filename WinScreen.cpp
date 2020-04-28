#include "WinScreen.h"
#include <iostream>

/*
Name: drawWinScreen	
Description: Replaces the window with a magenta background, and notifies the player that they have won.
*/
void drawWinScreen(sf::RenderWindow& window) {
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text;
	sf::Font font;

	window.clear(sf::Color::Magenta);

	if (!font.loadFromFile("arial.ttf"))
		std::cerr << "Error loading arial font in drawWinScreen" << std::endl;
	// Draw lives as a number
	text.setFont(font);
	text.setString("YOU WIN!!! :D:D:D:D:D:D:D:D");
	text.setPosition(125, 400);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(0, 90, 94));

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.draw(text);
	window.display();
}

/*
Name: drawLossScreen	
Description: Replaces the window with a read background, and notifies the player that they have lost.
*/
void drawLossScreen(sf::RenderWindow& window) {
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text;
	sf::Font font;

	window.clear(sf::Color(255, 0, 34));

	if (!font.loadFromFile("arial.ttf"))
		std::cerr << "Error loading arial font in drawWinScreen" << std::endl;
	// Draw lives as a number
	text.setFont(font);
	text.setString("YOU LOST!!! D:D:D:D:D:D:D:D:");
	text.setPosition(125, 400);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	window.draw(text);
	window.display();
}
