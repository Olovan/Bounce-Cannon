#include <SFML/Graphics.hpp>
#include <string>
#include "CannonBall.h"
#include "Target.h"

//Window Stuff
sf::Color backgroundColor = sf::Color(40,40,40,255);
int windowWidth = 1920;
int windowHeight = 1080;
std::string title = "Bounce Cannon V.1";
bool vSyncEnabled = true;

//Text Stuff
sf::Font font;
sf::Text text;
float fontSize = 20;
sf::Vector2f textPosition{ 50, 50 };
sf::Color textColor{ sf::Color::White };

//CannonBall Stuff
float cannonBallRadius = 20;
float cannonBallVelocity = 10;
sf::Color cannonBallColor = sf::Color::Green;


//Target Stuff
sf::Color defaultTargetColor = sf::Color::Red;
float defaultTargetRadius = 30;
float defaultTargetBaseScore = 10;
float targetSpeed = 5;
int maxTargets = 20;
float maxTargetColorShift = 1000;



//Block Generator Stuff
float baseTargetSpawn = 2;
float targetSpawnRange = 3;
int randomNumberPool = 60;
int xMargin = 100;
int yMargin = 100;

//Score Stuff
int score;