/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <string>
#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include <Timer.h>
#include "Game.h"

using namespace std;

int main()
{
	Game::createInstance();
	//EventSystem::initInstance();
	//EventSystem::getInstance()->init();

	Game* pGame = Game::getInstance();

	pGame->init();
	pGame->doLoop();
	pGame->destroyInstance();

	//EventSystem::cleanupInstance();
	

	

	
	MemoryTracker::getInstance()->reportAllocations(cout);
	system("pause");
	return 0;
}