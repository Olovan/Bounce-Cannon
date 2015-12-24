#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"


class Target;
class CannonBall;

extern sf::Vector2f vectReflect(sf::Vector2f vector, sf::Vector2f normal);  //Vector Reflection Function

extern float my_range(float input, float bottom, float top);

extern void postBounce(Target& target);

extern bool isColliding(float x, float y, Target target);


#pragma region Templates

	template <class Object1, class Object2> void bounce(Object1& striker, Object2& receiver)  //Bounce Function
	{
		sf::Vector2f normal = striker.getPosition() - receiver.getPosition(); //Find Normal vector
		normal = normal / (float)sqrt(powf(normal.x, 2) + powf(normal.y, 2)); //Turn normal into a unit vector
		striker.setVelocity(vectReflect(striker.getVelocity(), normal));
		receiver.setVelocity(-1.f*normal*targetSpeed);
	}

	template <class Class1, class Class2> bool isColliding(Class1& object1, Class2& object2) //Collision Function
	{
		sf::Vector2f distance = object1.getPosition() - object2.getPosition();
		float magDistance = sqrt(distance.x*distance.x + distance.y*distance.y);
		if (magDistance < (object1.getRadius() + object2.getRadius())) //If they are colliding
		{
			return true;
		}
		else
		{
			return false;
		}
	}

#pragma endregion


