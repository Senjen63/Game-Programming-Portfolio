#include "SnakeManager.h"
#include "Unit.h"
#include "UnitManager.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"
#include "GraphicsBufferManager.h"
#include "Animation.h"
#include "InputSystem.h"
#include "PowerUpManager.h"
#include "Game.h"
#include "LevelManager.h"

SnakeManager::SnakeManager()
{
	mpuSnakeHead = nullptr;
	mpAnimation = nullptr;
	mpInput = nullptr;
}

SnakeManager::~SnakeManager()
{
	clear();
	delete mpuSnakeHead;
	delete mpInput;
	delete mpLevel;
	
}

void SnakeManager::init()
{
	mStartBodyParts = 4;

	mpuSnakeHead = new Unit(Vector2D(350, 200));
	for (int i = 0; i < mStartBodyParts; i++)
	{
		mpuSnakeBody.push_back(new Unit(Vector2D(350 - GRIDSIZE * (i + 1), 200)));
	}

	mpInput = new InputSystem;
	mpLevel = new LevelManager();

	directionh = Vector2D(1, 0);
}

void SnakeManager::update()
{

}

void SnakeManager::movement()
{
	int headX = mpuSnakeHead->getSource().getX();
	int headY = mpuSnakeHead->getSource().getY();
	Vector2D tempDirection = directionh;

	//Up
	if (mpInput->getKeyState(mpInput->UP_ARROW_KEY) ||
		mpInput->getKeyState(mpInput->W_KEY))
	{
		tempDirection = Vector2D(0, -1);
	}

	//Down
	if (mpInput->getKeyState(mpInput->DOWN_ARROW_KEY) ||
		mpInput->getKeyState(mpInput->S_KEY))
	{
		tempDirection = Vector2D(0, 1);
	}

	//Left
	if (mpInput->getKeyState(mpInput->LEFT_ARROW_KEY) ||
		mpInput->getKeyState(mpInput->A_KEY))
	{
		tempDirection = Vector2D(-1, 0);
	}

	//Right
	if (mpInput->getKeyState(mpInput->RIGHT_ARROW_KEY) ||
		mpInput->getKeyState(mpInput->D_KEY))
	{
		tempDirection = Vector2D(1, 0);
	}

	if (tempDirection != directionh * -1)
	{
		directionh = tempDirection;
	}
	int size = mpuSnakeBody.size();
	
	for (int i = size - 1; i > 0; i--)
	{
		mpuSnakeBody[i]->setPosition(mpuSnakeBody[i-1]->getSource());
	}

	if (size > 0)
	{
		mpuSnakeBody[0]->setPosition(mpuSnakeHead->getSource());
	}

	mpuSnakeHead->setPosition(mpuSnakeHead->getSource() + directionh * GRIDSIZE);

	if (mpuSnakeHead->getSource().getX() > 800)
	{
		mpuSnakeHead->setPosition(Vector2D(-50, headY));
	}

	if (mpuSnakeHead->getSource().getX() < -50)
	{
		mpuSnakeHead->setPosition(Vector2D(800, headY));
	}

	if (mpuSnakeHead->getSource().getY() > 600)
	{
		mpuSnakeHead->setPosition(Vector2D(headX, -50));
	}

	if (mpuSnakeHead->getSource().getY() < -50)
	{
		mpuSnakeHead->setPosition(Vector2D(headX, 600));
	}
	
}

void SnakeManager::addBodypart()
{
	int add = mpLevel->nextlevel(mStartBodyParts);

	for (int i = 0; i <= add; i++)
	{
		
		mpuSnakeBody.push_back(new Unit(Vector2D(350 - GRIDSIZE * (i + 1), 200)));

	}

	mStartBodyParts += add;
}

void SnakeManager::rest()
{
	mpuSnakeHead->setPosition(Vector2D(350, 200));
	for (int i = 0; i < mStartBodyParts - 1; i++)
	{
		mpuSnakeBody[i]->setPosition((Vector2D(350 - GRIDSIZE * (i + 1), 200)));
	}
}

Vector2D SnakeManager::direction()
{
	Vector2D directionh = Vector2D(1, 0);
	/*Vector2D directionb = Vector2D(1, 0);*/

	return directionh;
}

Unit* SnakeManager::getBody(int list)
{ 
	return mpuSnakeBody[list]; 
}

vector <Unit*> SnakeManager::getBodyVector()
{
	return mpuSnakeBody;
}

void SnakeManager::reset()
{
	for (int i = 0; i < 4; i++)
	{
		delete mpuSnakeBody[i];
	}
}

void SnakeManager::clear()
{
	int size = mpuSnakeBody.size();
	for (int i = 0; i < size; i++)
	{
		delete mpuSnakeBody[i];
	}
	mpuSnakeBody.clear();
}