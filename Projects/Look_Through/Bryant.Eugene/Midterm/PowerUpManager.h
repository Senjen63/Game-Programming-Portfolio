#pragma once

#include <iostream>
#include <Vector2D.h>
#include "Timer.h"
#include "Trackable.h"

using namespace std;

class Unit;

class PowerUpManager : public Trackable
{
private:
	

	int spranX;
	int spranY;
	int slranX;
	int slranY;

	float increaseSpeed;
	float decreaseSpeed;

	Vector2D mRandom;

	Unit* mPowerUp;
	Unit* mPowerDown;

public:
	PowerUpManager();
	~PowerUpManager();

	void init();

	float speedUp(float time);
	float slowDown(float time);

	void spRandom();
	void slRandom();

	Unit* getPowerUp() { return mPowerUp; };
	Unit* getPowerDown() { return mPowerDown; };

};