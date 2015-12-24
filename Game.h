#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Target.h"
#include "GlobalVariables.h"
#include "CannonBall.h"

class Game
{
private:
	sf::RenderWindow window; //Game Window
	bool running = false;
	std::vector<Target> targets;  //Vector containing all targets
	CannonBall player; //Player

public:
	


	Game();  //Default Initializer
	Game(int input_Width, int input_Height); //Creates window of input_Width x input_Height

	void run();
		void initialize();
		void frame();
			void clearFrame();
			void generateRandomBlocks();
			void handleInput();
			void updatePlayer();
			void updateTargets();
			void updateGoals();
			void endFrame();
			void cleanDead();
			void drawFrame();
			//void update();
			void handleWindowStuff();
		void shutDown();

	
	void reset();
	~Game();
};

