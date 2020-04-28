#include "Tests.h"
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Alien.h"
#include "Player.h"
#include "Bunker.h"
	

/*
Name: Tests constructor
Description: Initializes collisionX  and collisionY  to 100.
*/
Tests::Tests() {
	collisionX = 100;
	collisionY = 100;
}

/*
Name: testBottomAlienColision   
Description: Ensure that the aliens can colide with the bottom of the screen
*/
void Tests::testBottomAlienColision() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Alien testAlien(collisionX, collisionY);

	sf::Sprite testBottom;
	sf::Texture bottomTexture;
	if (!bottomTexture.loadFromFile("bottom.png"))
		std::cerr << "Error in bottom texture loading" << std::endl;
	Collision::CreateTextureAndBitmask(bottomTexture, "bottom.png");
	testBottom.setTexture(bottomTexture);
	testBottom.setPosition(collisionX, collisionY);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        testAlien.drawAlien(window);
        window.draw(testBottom);

        if (Collision::PixelPerfectTest(testAlien.getSprite(), testBottom))
            cout << "testBottomAlienColision: Success" << endl;
        else
            cout << "testBottomAlienColision: Fail" << endl;
        window.display();
        window.close();
    }
}
/*
Name: testBottomAlienShot
Description: Ensure that the aliens can be hit with a laser
*/
void Tests::testAlienShot() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Alien testAlien(collisionX, collisionY);
    Laser testLaser('u');
    testLaser.shoot(collisionX, collisionY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        testAlien.drawAlien(window);
        testLaser.drawlaser(window);

        if (Collision::PixelPerfectTest(testAlien.getSprite(), testLaser.getSprite()))
            cout << "testAlienShot: Success" << endl;
        else
            cout << "testAlienShot: Fail" << endl;
        window.display();
        window.close();
    }
}
/*
Name: testPlayerShot 
Description: Ensure that the player can be hit with a laser
*/
void Tests::testPlayerShot() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Player Shot Test Window");
    Laser testLaser('u');
    Player testPlayer;
    testPlayer.setPosition(collisionX - 20, collisionY - 20);
    testLaser.shoot(collisionX, collisionY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        testPlayer.drawPlayer(window);
        testLaser.drawlaser(window);
        if (Collision::PixelPerfectTest(testPlayer.getSprite(), testLaser.getSprite()))
            cout << "testPlayerShot: Success" << endl;
        else
            cout << "testPlayerShot: Fail" << endl;

        window.display();
        window.close();
    }
}
/*
Name: testBunkerShot
Description: Ensure that the bunker can be hit with a laser 
*/
void Tests::testBunkerShot() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Bunker Shot Test Window");
    Laser testLaser('u');
    Bunker testBunker(collisionX - 20, collisionY - 20);
    testLaser.shoot(collisionX, collisionY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        testLaser.drawlaser(window);
        testBunker.drawBunker(window);

        if (Collision::PixelPerfectTest(testBunker.getSprite(), testLaser.getSprite()))
            cout << "testBunkerShot: Success" << endl;
        else
            cout << "testBunkerShot: Fail" << endl;

        window.display();
        window.close();
    }
}
/*
Name: playerMoves
Description: Ensure that the player can move with keyboard input
*/
void Tests::playerMoves() {
    Player testPlayer;
    testPlayer.setPosition(collisionX, collisionY);
    sf::Vector2f pPos;

    sf::RenderWindow window(sf::VideoMode(200, 200), "Move Player Test Window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();
        testPlayer.movePlayer('l', 10);
        pPos = testPlayer.getPosition();
        if (pPos.x == collisionX - 10)
            cout << "playerMoves (Left): Success" << endl;
        else
            cout << "playerMoves (Left): Fail" << endl;
        testPlayer.setPosition(collisionX, collisionY);
        testPlayer.movePlayer('r', 10);
        pPos = testPlayer.getPosition();
        if (pPos.x == collisionX + 10)
            cout << "playerMoves (Right): Success" << endl;
        else
            cout << "playerMoves (Right): Fail" << endl;

        testPlayer.drawPlayer(window);
        window.display();
        window.close();
    }
}
