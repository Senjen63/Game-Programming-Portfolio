#pragma once

#include <iostream>
#include <vector>
#include <Vector2D.h>
#include <stdlib.h>
#include <time.h>
#include "Trackable.h"

using namespace std;

class Unit;
class LevelManager;

class WallManager : public Trackable
{
private:
	vector<Unit*> mpWall;
	LevelManager* mpLevel;

	int listOfWalls;

	int ranX;
	int ranY;
	Vector2D randomPosition = Vector2D(ranX, ranY);

public:
	WallManager();
	~WallManager();

	void init();

	void addWall();

	void random();

	void reset();

	void clear();

	Unit* getWall(int list);
	vector <Unit*> getWallVector();
};