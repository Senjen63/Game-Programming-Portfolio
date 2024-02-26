#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Vector2D.h>
#include "Trackable.h"

using namespace std;

class GraphicsBuffer;
class Unit;
class Sprite;
class EventListener;

class FoodManager :public Trackable
{
private:
	Unit* mpFood;

	int mRanX;
	int mRanY;


public:
	FoodManager();
	~FoodManager();

	void init();

	void random();

	Unit* getFood() { return mpFood; };
};