#include "CannonBall.h"
#include "GlobalVariables.h"
#include <SFML/Window.hpp>


#pragma region PrimaryFunctions
CannonBall::CannonBall() //Constructor
{
	_texture.loadFromFile("./Images/BallTexture.png");
	_sprite.setTexture(_texture);
	_sprite.setScale(2 * cannonBallRadius / 90, 2 * cannonBallRadius /90);
	_sprite.setPosition(windowWidth / 2, windowHeight);
	_sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
	_shape.setPosition(windowWidth/2, windowHeight);
	_shape.setOrigin(cannonBallRadius, cannonBallRadius);
	_shape.setRadius(cannonBallRadius);
	_shape.setFillColor(cannonBallColor);
	_isActive = false;
}

void CannonBall::update(sf::RenderWindow& window) //WORK IN PROGRESS
{
	//Velocity Code
	setPosition(getPosition() + getVelocity());

	//Reset position after hitting wall
	if (getPosition().x > windowWidth || getPosition().x < 0 || getPosition().y > windowHeight || getPosition().y < 0)
	{
		setPosition(sf::Vector2f(windowWidth / 2, windowHeight));
		setVelocity(sf::Vector2f(0, 0));
		setIsActive(false);
	}
}

void CannonBall::launch(sf::Vector2f target) //WORK IN PROGRESS
{
	target = target - getPosition(); //Find vector between cannonBall and Target
	float targetMag = sqrt(target.x * target.x + target.y * target.y); //get Magnitude
	target = sf::Vector2f(target.x / targetMag, target.y / targetMag); //Turn it into Unit Vector
	setVelocity(target * cannonBallVelocity);
}

#pragma endregion


