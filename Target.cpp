#include "Target.h"
#include "CannonBall.h"

#pragma region Constructors

Target::Target() //Default Constructor
{
	setPosition(sf::Vector2f(0, 0));
	shape.setFillColor(defaultTargetColor);
	shape.setOrigin(sf::Vector2f(defaultTargetRadius, defaultTargetRadius));
	shape.setRadius(defaultTargetRadius);
	setBaseValue(defaultTargetBaseScore);
}

Target::Target(sf::Vector2f pos) //Constructs at Pos
{
	setPosition(pos);
	shape.setFillColor(defaultTargetColor);
	shape.setOrigin(sf::Vector2f(defaultTargetRadius, defaultTargetRadius));
	shape.setRadius(defaultTargetRadius);
	setBaseValue(defaultTargetBaseScore);
}

Target::Target(float input_x, float input_y) //Constructs at (x,y)
{
	setPosition(sf::Vector2f(input_x, input_y));
	shape.setFillColor(defaultTargetColor);
	shape.setOrigin(sf::Vector2f(defaultTargetRadius, defaultTargetRadius));
	shape.setRadius(defaultTargetRadius);
	setBaseValue(defaultTargetBaseScore);
}

Target::Target(sf::Vector2f input_Position, float input_Radius, sf::Color input_Color, float input_BaseValue) //Constructor for special Targets
{
	setBaseValue(input_BaseValue);
	setPosition(input_Position);
	shape.setFillColor(input_Color);
	shape.setOrigin(sf::Vector2f(input_Radius, input_Radius));
	shape.setRadius(input_Radius);
}

#pragma endregion

void Target::update()
{
	
	if (velocity != sf::Vector2f(0, 0))
	{

		setPosition(getPosition() + velocity); //Set new position

		if (this->getPosition().y > windowHeight || this->getPosition().x > windowWidth || this->getPosition().x < 0 || this->getPosition().y < 0) //If target is out of bounds then destroy it
		{
			score += baseValue * comboMultiplier;
			//Kill object
			setIsDead(true);
		}
	}
}


Target::~Target()
{
}
