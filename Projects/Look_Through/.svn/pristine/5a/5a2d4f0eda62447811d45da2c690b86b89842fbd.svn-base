#include "LevelManager.h"
#include "WallManager.h"
#include "SnakeManager.h"
#include "Game.h"

LevelManager::LevelManager()
{

}

LevelManager::~LevelManager()
{
	//Game::destroyInstance();
}

void LevelManager::init()
{
	//Game::getInstance()->getWallManager();
	Game::getInstance()->getSnakeManager();
}

int LevelManager::nextlevel(int num)
{
	return num + increase;
}

void LevelManager::saveLevel()
{

}

void LevelManager::difficulty()
{
	//Game::getInstance()->getWallManager()->addWall();
	Game::getInstance()->getSnakeManager()->addBodypart();
}