/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Game.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "InputSystem.h"
#include "Sprite.h"
#include "Animation.h"
#include "Unit.h"
#include <Timer.h>

Game* gpGame = nullptr;

Game::Game(int width, int height)
{
	mpgsystem = new GraphicsSystem(width, height);
	mpisystem = new InputSystem();
	gpGame;
}

Game::~Game()
{
	cleanup();
}

void Game::init()
{
	getSystem()->init();
	getInputSystem()->init();

	mpBackGround = new GraphicsBuffer(BACKGROUND_FILENAME, 800, 600);
	mpDeanSmurf = new GraphicsBuffer(DEAN_FILENAME, 240, 240);
	mpSmurf = new GraphicsBuffer(SMURFS_FILENAME, 240, 240);
	mpsprite = Sprite (mlocation, 1600, 1200, mpBackGround);

	mpUnit1 = new Unit(Vector2D(800 / 2, 600 / 2));

	mpaSmurf = new Animation(mpSmurf, 4, 4, 240, 240, 60.0f);
	mpaDean = new Animation(mpDeanSmurf, 4, 4, 240, 240, 60.0f);

	
	//getAnimation()->addSprite(mpsprite);

	mpUnit1->setAnimation(mpaSmurf);
}

void Game::cleanup()
{
	delete mpbuffer;
	delete mpBackGround;
	delete mpSmurf;
	delete mpDeanSmurf;
	mpgsystem->cleanup();
	mpisystem->cleanup();
	delete mpgsystem;
	delete mpisystem;
	delete mpUnit1;
	delete mpaDean;
	delete mpaSmurf;
	delete mpAnimate;
}

void Game::doLoop()
{
	Timer time;
	bool leave = false;
	PerformanceTracker* pTracker = new PerformanceTracker();
	float timing = .0005;
	float animationTimer = 0;
	mpUnit1->setAnimation(mpaSmurf);

	while (!leave)
	{
		time.start();
		pTracker->clearTracker("pTracker");
		pTracker->startTracking("pTracker");

		mpisystem->getMouseState();

		if (mpisystem->getKeyState(mpisystem->S_KEY))
		{
			mpUnit1->setCurrentSpeed(false,mRate);
		}

		if (mpisystem->getKeyState(mpisystem->F_KEY))
		{
			mpUnit1->setCurrentSpeed(true, mRate);
		}
		
		if (mpisystem->getKeyState(mpisystem->ENTER_KEY))
		{
			if (misAnimated == false)
			{
				misAnimated = true;
				mpUnit1->setAnimation(mpaDean);
			}

			else
			{
				misAnimated = false;
				mpUnit1->setAnimation(mpaSmurf);
			}
		}

		if (mpisystem->getMouseState())
		{
			mpUnit1->setPosition(getInputSystem()->getMousePosition());
		}

		if (mpisystem->getKeyState(mpisystem->ESCAPE_KEY))
		{
			leave = true;
		}
		
		getSystem()->draw(mlocation, mpsprite, 1.0);
		mpUnit1->draw();
		
		getSystem()->flip();
		mpUnit1->update();

		time.sleepUntilElapsed(16.67f);
		pTracker->stopTracking("pTracker");
		cout << pTracker->getElapsedTime("pTracker") << endl;
	}
	delete pTracker;
}

Sprite Game::getSprite()
{ 
	return mpsprite; 
}