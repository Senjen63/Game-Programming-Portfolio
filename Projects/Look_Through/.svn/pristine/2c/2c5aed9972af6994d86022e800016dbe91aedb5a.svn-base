#include "FoodManager.h"
#include "Unit.h"

FoodManager::FoodManager()
{

}

FoodManager::~FoodManager()
{
	delete mpFood;
}

void FoodManager::init()
{
	srand(time(NULL));
	int mRanX = rand() % 16;
	int mRanY = rand() % 12;

	mpFood = new Unit(Vector2D(mRanX * 50, mRanY * 50));
}

void FoodManager::random()
{
	int mRanX = rand() % 16;
	int mRanY = rand() % 12;

	mpFood->setPosition(Vector2D(mRanX * 50, mRanY * 50));
}