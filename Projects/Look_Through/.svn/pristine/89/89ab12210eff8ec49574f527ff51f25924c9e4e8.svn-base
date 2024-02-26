/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "EnemyManager.h"
#include "Unit.h"
#include "UnitManager.h"

EnemyManager::EnemyManager()
{
	mEnemyPositionX = 0;
	int mSpace = 0;
	float mEnemyY = 0;
	float mRandomX = 0;
}

EnemyManager::~EnemyManager()
{
	clear();
}

void EnemyManager::init()
{	
	for (int i = 0; i < 3; i++)
	{
		mpEnemy.push_back(new Unit(Vector2D(mEnemyPositionX + mSpace, 0)));
		if (mSpace >= 0)
		{
			mSpace += 250;
		}
	}	
}

void EnemyManager::enemyMovement()
{
	int size = mpEnemy.size();

	for (int i = 0; i < size; i++)
	{
		mpEnemy[i]->setPosition(mpEnemy[i]->getSource() + mMovement);
		if (mpEnemy[i]->getSource().getY() >= 1000)
		{
			mpEnemy[i]->setPosition(Vector2D(mpEnemy[i]->getSource().getX(), mEnemyY));
		}
	}
}

void EnemyManager::reset(int list /*Unit* unit*/)
{
	mpEnemy[list]->setPosition(Vector2D(mpEnemy[list]->getSource().getX(), mEnemyY));
}

Unit* EnemyManager::getEnemies(int list)
{
	return mpEnemy[list];
}

void EnemyManager::clear()
{
	int size = mpEnemy.size();

	for (int i = 0; i < size; i++)
	{
		delete mpEnemy[i];
	}
	mpEnemy.clear();
}