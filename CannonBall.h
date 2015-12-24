#pragma once

#include <SFML/Graphics.hpp>

#pragma once
class CannonBall
{
private:
	sf::CircleShape _shape;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _velocity;
	bool _isActive;
public:
	void launch(sf::Vector2f target);
	void update(sf::RenderWindow& window); //Needs window reference because of touch controls

	CannonBall();

#pragma region Get/Set functions
	float getRadius() {
		return _shape.getRadius();
	}

	sf::Sprite getSprite() { return _sprite; }

	sf::CircleShape getShape() {
		return _shape;
	}
	sf::Vector2f getVelocity() {
		return _velocity;
	}
	void setVelocity(sf::Vector2f velocity) {
		_velocity = velocity;
	}
	bool getIsActive() {
		return _isActive;
	}
	void setIsActive(bool isActive) {
		_isActive = isActive;
	}
	sf::Vector2f getPosition() {
		return _sprite.getPosition();
	}
	void setPosition(sf::Vector2f position) {
		_sprite.setPosition(position);
	}
#pragma endregion

#pragma region Convenience Functions
	float left() {
		return _shape.getPosition().x - _shape.getRadius();
	}
	float right() {
		return _shape.getPosition().x + _shape.getRadius();
	}
	float top() {
		return _shape.getPosition().y - _shape.getRadius();
	}
	float bottom() {
		return _shape.getPosition().y + _shape.getRadius();
	}
#pragma endregion
};

