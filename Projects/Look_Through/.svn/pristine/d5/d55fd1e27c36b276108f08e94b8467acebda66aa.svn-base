#include "WallManager.h"
#include "Unit.h"
#include "Game.h"
#include "LevelManager.h"

WallManager::WallManager()
{

}

WallManager::~WallManager()
{
	clear();
	delete mpLevel;
}

void WallManager::init()
{
	mpLevel = new LevelManager();
	listOfWalls = 5;
	srand(time(NULL));

	for (int i = 0; i < listOfWalls; i++)
	{
		ranX = rand() % 16;
		ranY = rand() % 12;
		mpWall.push_back(new Unit(Vector2D(ranX * 50, ranY * 50)));
	}
}

void WallManager::addWall()
{
	int add = mpLevel->nextlevel(listOfWalls);

	for (int i = 0; i <= add; i++)
	{
		ranX = rand() % 16;
		ranY = rand() % 12;
		mpWall.push_back(new Unit(Vector2D(ranX * 50, ranY * 50)));
		
	}

	listOfWalls += add;
}

void WallManager::reset()
{
	for (int i = 0; i < 4; i++)
	{
		delete mpWall[i];
	}
}

void WallManager::random()
{
	for (int i = 0; i < listOfWalls; i++)
	{
		ranX = rand() % 16;
		ranY = rand() % 12;
		mpWall[i]->setPosition(Vector2D(ranX * 50, ranY * 50));
	}
}

Unit* WallManager::getWall(int list)
{
	return mpWall[list];
}

vector <Unit*> WallManager::getWallVector()
{
	return mpWall;
}

void WallManager::clear()
{
	int size = mpWall.size();
	for (int i = 0; i < size; i++)
	{
		delete mpWall[i];
	}
	mpWall.clear();
}