#include "Game.h"
#include <PerformanceTracker.h>
#include <Timer.h>
#include <iostream>
#include <allegro5/allegro.h>

Game* gpGame = nullptr;

Game::Game()
{
	gpGame;
}

void Game::doLoop()
{
	bool keepGoing = true;
	double targetTime = 16.7;
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;
	Unit unit;

	al_install_keyboard();
	al_install_mouse();


	while (keepGoing)
	{
		pPerformanceTracker->clearTracker("loop");
		pPerformanceTracker->startTracking("loop");
		Timer loopTimer;
		loopTimer.start();

		ALLEGRO_KEYBOARD_STATE state;
		ALLEGRO_MOUSE_STATE mouseState;

		al_get_mouse_state(&mouseState);
		al_get_keyboard_state(&state);

		if (al_key_down(&state, ALLEGRO_KEY_A))
			std::cout << "A Key down\n";
		//if (mouseState.buttons & 1) 
		{
			std::cout << mouseState.x << " " << mouseState.y << std::endl;
		}

		unit.update(targetTime);
	
		loopTimer.sleepUntilElapsed(targetTime);
		pPerformanceTracker->stopTracking("loop");
		
		//std::cout << "Frame Took:" << pPerformanceTracker->getElapsedTime("loop") << " ms" << std::endl;
	}
	delete pPerformanceTracker;
}

void Unit::update(double dt)
{
	mAnimation.update(dt);
}

