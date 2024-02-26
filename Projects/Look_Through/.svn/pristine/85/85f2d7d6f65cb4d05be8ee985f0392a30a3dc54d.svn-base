/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "UnitManager.h"
#include "Game.h"

UnitManager::UnitManager()
{
	mNumberOfUnit = 0;
}

UnitManager::~UnitManager()
{
	clearAllUnits();
}

void UnitManager::addUnit(Unit* unit)
{
	mlUnit.push_back(unit);
	//mlUnit[mNumberOfUnit] = unit;
	mNumberOfUnit += 1;
}

void UnitManager::deleteUnit(int search)
{
	if (search > mNumberOfUnit || search < 0)
	{
		//mlUnit[NULL];
	}
	delete mlUnit[search];
	mlUnit.erase(mlUnit.begin() + search);
	mNumberOfUnit -= 1;
}

Unit* UnitManager::getUnit(int search)
{
	return mlUnit[search];
}

void UnitManager::clearAllUnits()
{
	for (int i = 0; i < mlUnit.size(); i++)
	{
		delete mlUnit[i];
	}
	mlUnit.clear();
}

void UnitManager::updateAll()
{

	for (int i = 0; i < mNumberOfUnit; i++)
	{
		mlUnit[i]->update();
		if (mlUnit[i]->getDestroy())
		{
			deleteUnit(i);
		}
	}
}

void UnitManager::drawAll()
{
	for (int j = 0; j < mNumberOfUnit; j++)
	{
		mlUnit[j]->draw();
	}
}

void UnitManager::stopUnit()
{
	for (int k = 0; k < mNumberOfUnit; k++)
		mlUnit[k]->setCurrentSpeed(false, 0);
}