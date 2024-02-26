#include "PowerUpManager.h"
#include "Unit.h"

PowerUpManager::PowerUpManager()
{
	
}

PowerUpManager::~PowerUpManager()
{
	delete mPowerUp;
	delete mPowerDown;
}

void PowerUpManager::init()
{
	srand(time(NULL));
	spranX = rand() % 16;
	spranY = rand() % 12;
	slranX = rand() % 16;
	slranY = rand() % 12;

	increaseSpeed = 30;
	decreaseSpeed = 30;

	mPowerUp = new Unit(Vector2D(spranX * 50, spranY * 50));
	mPowerDown = new Unit(Vector2D(slranX * 50, slranY * 50));
}

float PowerUpManager::speedUp(float time)
{

	return time - increaseSpeed;
}

float PowerUpManager::slowDown(float time)
{
	return time + decreaseSpeed;
}

void PowerUpManager::spRandom() 
{
	spranX = rand() % 16;
	spranY = rand() % 12;

	mPowerUp->setPosition(Vector2D(spranX * 50, spranY * 50));
}

void PowerUpManager::slRandom()
{
	slranX = rand() % 16;
	slranY = rand() % 12;
		
	mPowerDown->setPosition(Vector2D(slranX * 50, slranY * 50));
}