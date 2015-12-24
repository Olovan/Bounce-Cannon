#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"

class Target
{
private:
	float comboMultiplier = 1; //Multiplies the number of points you get for hitting the goal with this ball defaults to 1 and gets increased by the Cannonball
	float baseValue = 10; //Base number of points this target is worth. Gets multiplied by the comboMultiplier to determine value for goal with this ball
	bool isDead = false;
	sf::CircleShape shape;
	sf::Vector2f velocity{0,0}; //Velocity - defaults to 0,0
public:

	Target(); //CONSTRUCTOR
	Target(sf::Vector2f input_position); //Constructor with position
	Target(float input_x, float input_y); //Constructor with coords
	Target(sf::Vector2f input_Position, float input_Radius, sf::Color input_Color, float input_BaseValue); //Constructor for special targets

	void update();

#pragma region Get/Set Functions

	bool getIsDead() {
		return isDead;
	}

	void setIsDead(bool input_IsDead) {
		isDead = input_IsDead;
	}

	float getRadius() {
		return shape.getRadius();
	}

	sf::CircleShape getShape()
	{
		return shape;
	}

	sf::Vector2f getPosition() {
		return shape.getPosition();
	}

	void setPosition(sf::Vector2f pos) {
		shape.setPosition(pos);
	}

	void setVelocity(sf::Vector2f vel){
		velocity = vel;
	}

	sf::Vector2f getVelocity() {
		return velocity;
	}

	float getComboMultiplier() {
		return comboMultiplier;
	}

	void setComboMultiplier(float input_ComboMultiplier) {
		comboMultiplier = input_ComboMultiplier;
	}

	float getBaseValue()
	{
		return baseValue;
	}

	void setBaseValue(float input_BaseValue)
	{
		baseValue = input_BaseValue;
	}

	void setColor(sf::Color input_color)
	{
		shape.setFillColor(input_color);
	}

#pragma endregion

#pragma region Convenience Functions
	float left(){
		return shape.getPosition().x - shape.getRadius();
	}
	float right(){
		return shape.getPosition().x + shape.getRadius();
	}
	float top(){
		return shape.getPosition().y - shape.getRadius();
	}
	float bottom(){
		return shape.getPosition().y + shape.getRadius();
	}
#pragma endregion

	~Target(); //DESTRUCTOR
};

