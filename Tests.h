#pragma once
class Tests
{
private:
	int collisionX;
	int collisionY;
public:
	Tests();
	void testBottomAlienColision();
	void testAlienShot();
	void testPlayerShot();
	void testBunkerShot();
	void playerMoves();
};

