#pragma once

#include <iostream>
#include "Trackable.h"

using namespace std;

class WallManager;
class SnakeManager;

class LevelManager :public Trackable
{
private:

	int increase = 2;
	int level = 1;

	WallManager* mpWall;
	SnakeManager* mpSnake;

public:
	LevelManager();
	~LevelManager();

	void init();

	int nextlevel(int num);

	void difficulty();

	void saveLevel();
};