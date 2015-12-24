#pragma once

#include <SFML/Graphics.hpp>
#include <string>


//Window Stuff
extern sf::Color backgroundColor;
extern int windowWidth;
extern int windowHeight;
extern std::string title;
extern bool vSyncEnabled;

//Text Stuff
extern sf::Font font;
extern sf::Text text;
extern float fontSize;
extern sf::Vector2f textPosition;
extern sf::Color textColor;


//CannonBall Stuff
extern float cannonBallRadius;
extern float cannonBallVelocity;
extern sf::Color cannonBallColor;



//Target Stuff
extern sf::Color defaultTargetColor;
extern float defaultTargetRadius;
extern float defaultTargetBaseScore;
extern float targetSpeed;
extern int maxTargets;
extern float maxTargetColorShift;


//Block Generator Stuff
extern float baseTargetSpawn;
extern float targetSpawnRange;
extern int randomNumberPool;
extern int xMargin;
extern int yMargin;

//Score Stuff
extern int score;