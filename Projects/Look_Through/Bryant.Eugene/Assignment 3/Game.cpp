/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Game.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "GraphicsBufferManager.h"
#include "InputSystem.h"
#include "Sprite.h"
#include "Animation.h"
#include "Unit.h"
#include "UnitManager.h"
#include <Timer.h>

Game* Game::mpsGame = NULL;

Game::Game(int width, int height)
{
	//mpgsystem = new GraphicsSystem(width, height);
	//mpisystem = new InputSystem();
}

Game::~Game()
{
	cleanup();
}

void Game::createInstance()
{
	if (mpsGame == NULL)
	{
		mpsGame = new Game;
	}
}

void Game::destroyInstance()
{
	delete mpsGame;
}

Game* Game::getInstance()
{
	return mpsGame;
}

void Game::init()
{
	mpgsystem = new GraphicsSystem(800, 600);
	mpisystem = new InputSystem();
	getSystem()->init();
	getInputSystem()->init();

	mpbufferManager = new GraphicsBufferManager;
	mpunitManager = new UnitManager;

	mpBackGround = new GraphicsBuffer(BACKGROUND_FILENAME, 800, 600);
	mpDeanSmurf = new GraphicsBuffer(DEAN_FILENAME, 240, 240);
	mpSmurf = new GraphicsBuffer(SMURFS_FILENAME, 240, 240);
	mpsprite = Sprite (mlocation, 1600, 1200, mpBackGround);

	getGraphicsBufferManager()->addGraphicsBuffer(ASSET_PATH + BACKGROUND_FILENAME, mpBackGround);
	getGraphicsBufferManager()->addGraphicsBuffer(ASSET_PATH + SMURFS_FILENAME, mpSmurf);
	getGraphicsBufferManager()->addGraphicsBuffer(ASSET_PATH + DEAN_FILENAME, mpDeanSmurf);

	mpaSmurf = new Animation(mpSmurf, 4, 4, 240, 240, 60.0f);
	mpaDean = new Animation(mpDeanSmurf, 4, 4, 240, 240, 60.0f);
}

void Game::cleanup()
{
	delete mpbuffer;
	mpgsystem->cleanup();
	mpisystem->cleanup();
	delete mpbufferManager;
	delete mpunitManager;
	delete mpgsystem;
	delete mpisystem;
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
	int numberOfUnit = 0;
	

	while (!leave)
	{
		time.start();
		pTracker->clearTracker("pTracker");
		pTracker->startTracking("pTracker");

		if (mpisystem->getMouseState(getInputSystem()->Left_CLICK))
		{
			mpUnit1 = new Unit(Vector2D(800 / 2, 600 / 2));
			
			mpUnit1->setPosition(getInputSystem()->getMousePosition());
			
			//if (InputSystem::ENTER_KEY) 
			//{
				mpUnit1->setAnimation(mpaSmurf);
				getUnitManager()->addUnit(mpUnit1);
			//}

			//else
			//{
				//mpUnit1->setAnimation(mpaDean);
				//getUnitManager()->addUnit(mpUnit1);
			//}
			numberOfUnit++;
		}

		if (mpisystem->getMouseState(getInputSystem()->RIGHT_CLICK))
		{
			getUnitManager()->updateAll();
			numberOfUnit--;
		}
		
		if (getInputSystem()->getKeyState(getInputSystem()->SPACEBAR_KEY))//buggy
		{
			getUnitManager()->stopUnit();
		}

		/* set to where if you hold enter, it switches to the dean smurff
			if not it stays or switches back to regular smurf*/
		if (getInputSystem()->getKeyState(getInputSystem()->ENTER_KEY)) // it is a little buggy
		{
			getUnitManager()->getUnit(numberOfUnit - 1)->setAnimation(mpaDean);
		}

		if (getInputSystem()->getKeyState(getInputSystem()->ESCAPE_KEY))
		{
			leave = true;
		}
		
		getSystem()->draw(mlocation, mpsprite, 1.0);
		getUnitManager()->drawAll();
		
		
		getUnitManager()->updateAll();
		getSystem()->flip();

		time.sleepUntilElapsed(16.0f);
		pTracker->stopTracking("pTracker");
		cout << pTracker->getElapsedTime("pTracker") << endl;
	}
	delete pTracker;
}

Sprite Game::getSprite()
{ 
	return mpsprite; 
}

GraphicsSystem* Game::getSystem()
{
	return mpgsystem;
}

InputSystem* Game::getInputSystem()
{
	return mpisystem;
}

GraphicsBuffer* Game::getGraphicsBuffer()
{
	return mpbuffer;
}

GraphicsBufferManager* Game::getGraphicsBufferManager()
{
	return mpbufferManager;
}

UnitManager* Game::getUnitManager()
{
	return mpunitManager;
}

Animation* Game::getAnimation()
{
	return mpAnimate;
}

Vector2D Game::getLocation()
{
	return mlocation;
}