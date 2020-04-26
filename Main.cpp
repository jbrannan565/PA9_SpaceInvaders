#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Bunker.h"
#include "Alien.h"
#include "Crab.h"
#include "Squid.h"
#include "Octopus.h"
#include "HUD.h"
#include "WinScreen.h"
#include "Collision.h"
#include "Tests.h"

using namespace std;

#define NUMALIENS 9
#define ALIENSPEED 20

int main()
{
	Tests tester;

	tester.playerMoves();
	tester.testAlienShot();
	tester.testPlayerShot();
	tester.testBunkerShot();
	tester.testBottomAlienColision();
	/*
    sf::RenderWindow window(sf::VideoMode(800, 800), "Space Invaders");

	bool endGame = false;
	bool win = false;
    HUD hud;
    Player player;
    Bunker bunker1(800.0/3 - 190, 575);
    Bunker bunker2(800.0/3*2 - 190, 575);
    Bunker bunker3(800.0/3*3 - 190, 575);

	int deadAliens = 0;

    Alien* alienArray[NUMALIENS] = { new Crab(200,100),new Crab(300,100), new Crab(400,100), 
		new Squid(200,200), new Squid(300,200), new Squid(400,200),
		new Octopus(200,300), new Octopus(300,300), new Octopus(400,300)};

	sf::Sprite bottom;
	sf::Texture bottomTexture;
	if (!bottomTexture.loadFromFile("bottom.png"))
		std::cerr << "Error in bottom texture loading" << std::endl;
	Collision::CreateTextureAndBitmask(bottomTexture, "bottom.png");
	bottom.setTexture(bottomTexture);
	bottom.setPosition(0, 700);

	int count = 0, downCount = 0;
	char direction = 'r', lastDirection = 'r';
	// begin window things
	while (window.isOpen()) {
		count++;

		if (endGame || hud.getLives() <= 0) {
			drawLossScreen(window);
			continue;
		}

		if (deadAliens >= NUMALIENS) {
			drawWinScreen(window);
			continue;
		}

        window.clear(sf::Color(0, 63, 99));

		// MOVE ALIENS IN ZIG ZAG PATTERN
		if (count % 100 == 0) { // they only move every 1000th run, makes them "jump" like in the game
			for (int i = 0; i < NUMALIENS; i++) { // do for every alien
				if (alienArray[i] == NULL)
					continue;
				if (rand() % 4 == 0)
					alienArray[i]->shoot();

				if (direction == 'd') { // if direction should be down, move all dowb
					i = NUMALIENS; // resent counter so we start at 1st alien next loop
					for (int k = 0; k < NUMALIENS; k++) {
						if (alienArray[k] == NULL)
							continue;
						alienArray[k]->moveAlien('d', ALIENSPEED); // move all the aliens down
					}
					if (lastDirection == 'r') { // switch from r to l
						direction = 'l';
					}
					else if (lastDirection == 'l') { // switch from l to r
						direction = 'r';
					}
				}
				else {
					alienArray[i]->moveAlien(direction, ALIENSPEED); // move left or right
					sf::Vector2f alienPos = alienArray[i]->getPosition();
					if (direction == 'r') {
						if (alienPos.x > 750) { //if we reach right border, move down
							for (int j = i + 1; j < NUMALIENS; j++) {
								if (alienArray[j] == NULL)
									continue;
								alienArray[j]->moveAlien(direction, ALIENSPEED); // move the rest of the aliens before moving down
							}
							direction = 'd';
							lastDirection = 'r';
						}
					}
					else if (direction == 'l') {
						if (alienPos.x < 50) { // if we reach left border move down
							for (int j = i + 1; j < NUMALIENS; j++) {
								if (alienArray[j] == NULL)
									continue;
								alienArray[j]->moveAlien(direction, ALIENSPEED); // move the rest of the aliens before moving down
							}
							direction = 'd';
							lastDirection = 'l';
						}
					}
				}
			}
		}

		auto lasers = player.getLasers();
		//draw all the aliens
		for (int i = 0; i < NUMALIENS; i++) {

			if (alienArray[i] == NULL)
				continue;
			alienArray[i]->drawAlien(window);

			// Alien Collision
			// End game if alien reaches bottom
			if (Collision::PixelPerfectTest(bottom, alienArray[i]->getSprite())) {
				endGame = true;
			}

			// handle alien gets shot
			for (auto laser : lasers) {
				if (Collision::PixelPerfectTest(laser->getSprite(), alienArray[i]->getSprite())) {
					laser->stoplaser();
					alienArray[i]->remove();
					deadAliens++;
				}
			}

			auto alienLasers = alienArray[i]->getLasers();

			// handle alien lasers
			for (auto laser : alienLasers) {
				// handle bunkers getting shot
				if (Collision::PixelPerfectTest(laser->getSprite(), bunker1.getSprite())) {
					laser->stoplaser();
					bunker1.takeHit();
				}
				if (Collision::PixelPerfectTest(laser->getSprite(), bunker2.getSprite())) {
					laser->stoplaser();
					bunker2.takeHit();
				}
				if (Collision::PixelPerfectTest(laser->getSprite(), bunker3.getSprite())) {
					laser->stoplaser();
					bunker3.takeHit();
				}

				// handle player getting shot

				if (Collision::PixelPerfectTest(laser->getSprite(), player.getSprite())) {
					laser->stoplaser();
					hud.decrementLives();
				}
			}
		}
		// bunker collsions
		for (auto laser : lasers) {
			if (Collision::PixelPerfectTest(laser->getSprite(), bunker1.getSprite())) {
				laser->stoplaser();
				bunker1.takeHit();
			}
			if (Collision::PixelPerfectTest(laser->getSprite(), bunker2.getSprite())) {
				laser->stoplaser();
				bunker2.takeHit();
			}
			if (Collision::PixelPerfectTest(laser->getSprite(), bunker3.getSprite())) {
				laser->stoplaser();
				bunker3.takeHit();
			}
		}

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Player movement handling
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player.movePlayer('l', 6.0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player.movePlayer('r', 6.0);
			// Player SHOOT
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Space)
                    player.shoot();
        }
		// Collisions

        // Draw Player
        player.drawPlayer(window);

        // Draw Bunker
        bunker1.drawBunker(window);
        bunker2.drawBunker(window);
        bunker3.drawBunker(window);

        // Draw HUD
        hud.drawLivesSprites(window);
        hud.drawScore(window);

		// Draw Bottom
		window.draw(bottom);

        window.display();
    }

	// Draw endgame screen
	cout << "END" << endl;

	*/
    return 0;
}