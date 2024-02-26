#include "Game.h"
#include <PerformanceTracker.h>
#include <Timer.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <fstream>

Game* gpGame = nullptr;

using namespace std;

Game::Game()
{
	ifstream input("data.txt");
	if (input.good())
	{
		string key;
		string background;
		string smurf;
		int width, height;

		while (!input.eof())
		{
			input >> key;

			if (key == "bkgrnd")
			{
				input >> background;

			}
			else if (key == "smrf")
			{
				input >> smurf;
			}
			else if (key == "size")
			{
				input >> width >> height;
			}
		}

			}
}

void Game::doLoop()
{
	bool keepGoing = true;
	double targetTime = 16.7;
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;
	Unit unit;

	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());



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

		/*if (al_key_down(&state, ALLEGRO_KEY_A))
			std::cout << "A Key down\n";
		//if (mouseState.buttons & 1) 
		{
			std::cout << mouseState.x << " " << mouseState.y << std::endl;
		}*/

		while(!al_is_event_queue_empty(queue))
		{
			ALLEGRO_EVENT theEvent;
			al_get_next_event(queue, &theEvent);
			if (theEvent.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				std::cout << theEvent.keyboard.keycode <<
					"key down\n";
			}
			else if (theEvent.type == ALLEGRO_EVENT_KEY_UP)
			{
				std::cout << theEvent.keyboard.keycode <<
					"key up\n";
			}
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

