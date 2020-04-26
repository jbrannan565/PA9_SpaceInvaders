#include "Laser.h"
#include "Collision.h"

/*
Name: Laser
Description: This function takes in a character input parameter and 
sets x to 0, y to 0, count to 0, direction to the input paramter character start_direction,

*/
Laser::Laser(char start_direction)
{
	Collision::CreateTextureAndBitmask(lTexture, "laser.png");
	laser.setTexture(lTexture);

	x = 0;
	y = 0;
	count = 0;
	direction = start_direction;

	return;
};
/*
Name: shoot
Description: This function takes in two float input paramteres.
redefines x with start_x input parameter,  redefines y with start_y input parameter,
and set the position of the laser on the values of x and y
*/

void Laser:: shoot(float start_x, float start_y)
{
	x = start_x;
	y = start_y;
	laser.setPosition(x,y);


	return;
};
/*
Name: drawlaser
Description: The function takes in the render window as an inputparameter, 
and prints the laser on the window, and calls the function movelaser().
*/
void Laser::drawlaser(sf::RenderWindow& window)
{
	movelaser();
	window.draw(laser);

	return;
};
/*
Name: movelaser
Description: This function increments the count by 1, 
and when the count is a number that is divisible by 5 then it will increment
y up by 1 or down by 1 depending on the character the direction variable holds.
then sets the position of the laser
*/
void Laser::movelaser()
{

	count++;
	if (count % 1 == 0)//when count is divisible by 50
	{
		if(direction == 'u')//shoot up
			y -= 5;

		if (direction == 'd')//shoot down
			y += 5;

		laser.setPosition(x, y);
	}
	return;
};
/*
Name: stoplaser
Description: this function sets the x to 1600,y to 1600,
and sets the position of the laser in the value of x and y
*/
void Laser::stoplaser()
{
	x = 1600;
	y = 1600;
	laser.setPosition(x,y);
};


const sf::Sprite& Laser::getSprite() {
	return laser;
}

