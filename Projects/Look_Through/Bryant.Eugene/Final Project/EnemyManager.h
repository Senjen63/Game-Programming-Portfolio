#pragma once

#include <iostream>
#include <Vector2D.h>
#include "Trackable.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Unit;
class UnitManager;

class EnemyManager : public Trackable
{
private:
	vector<Unit*> mpEnemy;
	Vector2D mMovement = Vector2D(0, 5);

	int mEnemyPositionX;
	int mSpace;
	float mEnemyY;
	float mRandomX;

public:
	
	EnemyManager();
	~EnemyManager();

	void init();

	void enemyMovement();

	void reset(int list);

	void clear();

	Unit* getEnemies(int list);

	vector<Unit*> getEnemy() { return mpEnemy; };
};