#include "Game.h"
#include "Target.h"
#include "CannonBall.h"
#include "GlobalVariables.h"
#include "GlobalFunctions.h"
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


CannonBall player;
std::vector<Target> targets;  //Vector containing all targets

#pragma region Initializers
Game::Game()
{
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setColor(textColor);
	text.setPosition(textPosition);
}

Game::Game(int input_windowWidth, int input_windowHeight)
{
	windowHeight = input_windowHeight;
	windowWidth = input_windowWidth;
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setColor(textColor);
	text.setPosition(textPosition);
}
#pragma endregion

void Game::run()  //ENTRY POINT
{
	initialize();
	while (running)
	{
		frame();
	}
	shutDown();
}

void Game::initialize() //SET INITIAL VALUES AND CREATE WINDOW
{
	srand(time(NULL)); //Seed Random Generator
	window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(vSyncEnabled);
	window.display();
	running = true;
	score = 0;

#pragma region Text Initialization
	//Text Stuff
	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setColor(textColor);
	text.setPosition(textPosition);
#pragma endregion
}

void Game::shutDown() //CALLED BEFORE PROGRAM EXITS
{

}

void Game::frame() //COMPLETE ALL ACTIONS FOR THIS FRAME
{
	clearFrame();
	generateRandomBlocks();
	handleInput();
	updatePlayer();
	updateTargets();
	updateGoals();
	endFrame();
	cleanDead();
	drawFrame();
	handleWindowStuff();
}

#pragma region FrameFunctions

void Game::clearFrame() //CLEAR LAST FRAME
{
	window.clear(backgroundColor); //Clear Previous Frame
}

void Game::generateRandomBlocks() //GENERATE NEW TARGETS RANDOMLY
{
	if (rand() % randomNumberPool == 0 && targets.size() < maxTargets) //Make sure you are eligable to spawn a target this frame
	{
		bool inPosition = false;
		int randx;
		int randy;
		while (!inPosition) //Make sure the target isn't on top of another target
		{
			inPosition = true;
			randx = rand() % (windowWidth - 2 * xMargin) + xMargin;
			randy = rand() % (windowHeight - 2 * yMargin) + yMargin;
			for (Target target : targets)
			{
				if (isColliding(randx, randy, target)) //Check every target
				{
					inPosition = false; //If you're on top of a target then run through the loop again and generate a new position
				}
			}

		}
		targets.emplace_back(randx, randy);
	}
}

void Game::handleInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Make sure a button is being pressed
	{
		if (!player.getIsActive()) //Make sure player is not already active
		{
			if (sf::Mouse::getPosition().y > windowHeight - cannonBallRadius) //If they clicked on the bottom
			{
				player.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x, player.getPosition().y));
			}
			else
			{
				sf::Vector2f target = (sf::Vector2f)sf::Mouse::getPosition() - player.getPosition(); //Find vector between cannonBall and Target
				float targetMag = sqrt(target.x * target.x + target.y * target.y); //get Magnitude
				target = sf::Vector2f(target.x / targetMag, target.y / targetMag); //Turn it into Unit Vector
				player.setVelocity(target * cannonBallVelocity);
				player.setIsActive(true);
			}
		}
	}
}

void Game::updatePlayer()
{
	player.update(window);
	for (Target& target : targets)
	{
		if (isColliding(player, target))
		{
			bounce(player, target);
			postBounce(target);
		}
	}
}

void Game::updateTargets()
{
	for (Target& currentTarget : targets)
	{
		currentTarget.update();
		if (currentTarget.getVelocity() != sf::Vector2f(0, 0)) //Only do this calculation if the target is in motion
		{
			for (Target& otherTarget : targets) //Check current target against all the others
			{
				if (isColliding(currentTarget, otherTarget) && otherTarget.getPosition() != currentTarget.getPosition()) //If Colliding With another Target
				{
					bounce(currentTarget, otherTarget);
					postBounce(currentTarget);
					postBounce(otherTarget);
				}
			}
		}
	}
}

void Game::updateGoals()
{

}

void Game::endFrame()
{
	text.setString("Score: " + patch::to_string(score));
}

void Game::cleanDead()
{
	if (targets.size() > 0)
	{
		auto iterator = std::remove_if(targets.begin(), targets.end(), [](Target mTarget) {return mTarget.getIsDead(); });
		if (iterator < targets.end())
		{
			targets.erase(iterator, targets.end()); //C++ 11 Lambda functions are confusing as shit
		}
		//Set Text to keep track of destruction calls
		//text.setString("iterator: ");
	}
}

void Game::drawFrame() //DRAW EVERY OBJECT FOR CURRENT FRAME
{
	window.draw(player.getSprite());
	for (Target target : targets)
	{
		window.draw(target.getShape());
	}

	window.draw(text);

	window.display();

	handleWindowStuff();
}

void Game::handleWindowStuff() //HANDLE WINDOW EVENTS AND CHECK FOR EXIT CONDITIONS
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			running = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		running = false;
	}
}

/*
void Game::update() //UPDATES EACH OBJECT
{

	generateRandomBlocks(); //Generate any random blocks for this frame

	player.update(window); //Update Player

	for (Target& target : targets) //Update every Target
	{
		target.update();
	}
	for (GoalZone goal : goals) //Update every Goal NOT IMPLIMENTED YET
	{
		goal.update();
	}


	//Clean up Dead stuff
	//It should move the destroyed blocks to the end of the vector and then delete them.
	if (targets.size() > 0)
	{
		auto iterator = std::remove_if(targets.begin(), targets.end(), [](Target mTarget) {return mTarget.getIsDead(); });
		if (iterator < targets.end())
		{
			targets.erase(iterator, targets.end()); //C++ 11 Lambda functions are confusing as shit
		}
		//Set Text to keep track of destruction calls
		text.setString("iterator: ");
	}



}

*/

#pragma endregion



Game::~Game()
{
}
