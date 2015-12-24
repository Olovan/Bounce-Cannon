
#include <SFML/Graphics.hpp>
#include "GlobalFunctions.h"
#include "Target.h"
#include "CannonBall.h"

sf::Vector2f vectReflect(sf::Vector2f vector, sf::Vector2f normal)
{
	return vector - 2 * (vector.x*normal.x + vector.y*normal.y) * normal;
}

float my_range(float input, float bottom, float top)
{
	if (input > top)
		input = top;
	if (input < bottom)
		input = bottom;
	return input;
}

void postBounce(Target& target)
{
	target.setComboMultiplier(target.getComboMultiplier() + 1); //Change Combo Multiplier

	float colorFloat = my_range(target.getComboMultiplier() , 1, 9); //Returns between 0 and 1 depending on whether the ball is worth 0 - ColorShiftValue
	float newColorRed = my_range(255 - (80 * (colorFloat - 3)),0,255);
	float newColorGreen = target.getComboMultiplier() <= 5 ? my_range(50 * colorFloat,0,255) : my_range(255 - (65 * (colorFloat-5)),0,255);
	float newColorBlue = my_range(80 * (colorFloat - 6),0,255);
	sf::Color newColor(newColorRed,newColorGreen,newColorBlue, 255);
	target.setColor(newColor);
}

bool isColliding(float x, float y, Target target)
{
	sf::Vector2f distance = sf::Vector2f(x,y) - target.getPosition();
	float magDistance = sqrt(distance.x*distance.x + distance.y*distance.y);
	if (magDistance < (target.getRadius() + defaultTargetRadius)) //If they are colliding
	{
		return true;
	}
	else
	{
		return false;
	}
}