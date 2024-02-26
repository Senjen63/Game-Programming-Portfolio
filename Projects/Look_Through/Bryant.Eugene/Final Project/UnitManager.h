/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "Trackable.h"
#include "Unit.h"

using namespace std;

class Unit;

class UnitManager : public Trackable
{
private:
	vector <Unit*> mlUnit;
	int mNumberOfUnit = 0;

public:

	UnitManager();
	~UnitManager();

	void addUnit(Unit* unit);
	void deleteUnit(int search);
	Unit* getUnit(int search);
	void stopUnit();
	void clearAllUnits();
	void updateAll();
	void drawAll();
};