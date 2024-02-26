/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "SystemManager.h"
#include "HUD.h"
#include "InputSystem.h"
#include "SoundSystem.h"
#include "Color.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "GraphicsSystem.h"



SystemManager::SystemManager()
{
	mpHUD = nullptr;
	mpsSystem = nullptr;
	mpColor = nullptr;
}

SystemManager::~SystemManager()
{
	delete mpHUD;
	delete mpsSystem;
	delete mpColor;
	delete mpiSystem;
	delete mpLoadPlayer;
	delete mpLoadEnemy;
}

// Initializes the System Manager
void SystemManager::init()
{
	mpHUD = new HUD();
	mpHUD->hudInit();
	mpsSystem = new SoundSystem();
	mpColor = new Color(0, 0, 0);
	mpiSystem = new InputSystem();
	mpLoadPlayer = new PlayerManager();
	mpLoadPlayer->init();
	mpLoadEnemy = new EnemyManager();
	mpLoadEnemy->init();	
}

// Allows the user to change the difficulty or
// turn the sound on or off
void SystemManager::options(HUD* hud)
{
	bool stillGoing = true;	
	
	while (stillGoing)
	{
		getHUD()->displayOptions();
		if (getInput()->getKeyState(getInput()->ONE_KEY))
		{
			getHUD()->clearScreen(getColor());
			speed(hud);
		}

		else if (getInput()->getKeyState(getInput()->TWO_KEY))
		{
			getHUD()->clearScreen(getColor());
			sound(mpHUD);
		}

		else if (getInput()->getKeyState(getInput()->B_KEY))
		{
			stillGoing = false;
		}

		Game::getInstance()->getSystem()->flip();
	}

	getHUD()->clearScreen(getColor());
}

// Switches the sound on or off
void SystemManager::sound(HUD* hud)
{
	bool stillgoing = true;

	while (stillgoing)
	{
		mpHUD->displaySound();
		if (getInput()->getKeyState(getInput()->Y_KEY))
		{
			mOn = 1;
			stillgoing = false;
		}

		else if (getInput()->getKeyState(getInput()->N_KEY))
		{
			mOn = 0;
			stillgoing = false;
		}
		Game::getInstance()->getSystem()->flip();
	}
}

// returns the result of the sound switch
float SystemManager::onOff(float on)
{
	on = mOn;
	return on;
}

// lets the user quit the game or do a quick save
bool SystemManager::quit(bool endgame)
{
	if (getInput()->getKeyState(getInput()->ESCAPE_KEY))
	{
		endgame = false;
	}

	else
	{
		endgame = true;
	}

	return endgame;
}

// changes the speed of the game
float SystemManager::speed(HUD* hud)
{
	bool keepgoing = true;

	while (keepgoing)
	{
		mpHUD->displaySpeed();
		if (getInput()->getKeyState(getInput()->E_KEY))
		{
			mDT = 200;
			keepgoing = false;
		}
		
		else if (getInput()->getKeyState(getInput()->N_KEY))
		{
			mDT = 120;
			keepgoing = false;
		}

		else if (getInput()->getKeyState(getInput()->H_KEY))
		{
			mDT = 30;
			keepgoing = false;
		}
		Game::getInstance()->getSystem()->flip();
	}

	return mDT;
}

// returns the current speed
float SystemManager::getSpeed(float delta)
{
	delta = mDT;

	return delta;
}

// saves the player's position,
// enemy's position,
// and the games speed
void SystemManager::saveGame(PlayerManager* player, EnemyManager* enemy, float delta)
{
	int size = enemy->getEnemy().size();
	mSaveFile.open("SaveFile.txt");	

	msPlayerX = convertFloatToString(player->getPlayer()->getSource().getX());
	msPlayerY = convertFloatToString(player->getPlayer()->getSource().getY());

	mSaveFile << msPlayerX << endl << msPlayerY << endl << endl;

	for (int s = 0; s < size; s++)
	{
		msEnemyX = convertFloatToString(enemy->getEnemies(s)->getSource().getX());
		msEnemyY = convertFloatToString(enemy->getEnemies(s)->getSource().getY());

		mSaveFile << msEnemyX << endl << msEnemyY << endl << endl;
	}

	mDT = delta;
	msDT = convertFloatToString(mDT);

	mSaveFile << msDT << endl;

	mSaveFile.close();
}

// saves the player's score on another file
void SystemManager::saveScore(HUD* hud)
{
	mSaveScore.open("Score.txt");

	mSaveScore << hud->getScore() << endl;
	
	mSaveScore.close();
	
}

// load the player's position,
// the enemy's position,
// and the game's speed
void SystemManager::loadGame(PlayerManager* player, EnemyManager* enemy)
{
	
	mLoadFile.open("SaveFile.txt");
	
	int size = enemy->getEnemy().size();

	std::getline(mLoadFile, msPlayerX);
	mPlayerX = convertStringToFloat(msPlayerX);
	std::getline(mLoadFile, msPlayerY);
	mPlayerY = convertStringToFloat(msPlayerY);

	player->getPlayer()->setPosition(Vector2D(mPlayerX, mPlayerY));

	std::getline(mLoadFile, mTemp);

	for (int k = 0; k < size; k++)
	{
		std::getline(mLoadFile, msEnemyX);
		mEnemyX = convertStringToFloat(msEnemyX);
		std::getline(mLoadFile, msEnemyY);
		mEnemyY = convertStringToFloat(msEnemyY);

		std::getline(mLoadFile, mTemp);

		enemy->getEnemies(k)->setPosition(Vector2D(mEnemyX, mEnemyY));
	}
	
	std::getline(mLoadFile, msDT);
	mDT = convertStringToFloat(msDT);
		
	mLoadFile.close();
	
}

// Loads the player's score
int SystemManager::loadScore(int score)
{
	mLoadScore.open("Score.txt");

	mLoadScore >> mLoadScoreS;
	mLoadScoreN = convertStringToInt(mLoadScoreS);

	score = mLoadScoreN;	

	mLoadScore.close();

	return score;
}

int SystemManager::convertStringToInt(string str)
{
	return stoi(str);
}

string SystemManager::convertFloatToString(float num)
{
	return to_string(num);
}

float SystemManager::convertStringToFloat(string str)
{
	return stof(str);
}

// The game speeds up everytime an enemy is destroyed
float SystemManager::speedUp(float time)
{
	if (time <= 10)
	{
		time -= 2;
	}

	else if (time <= 2)
	{
		time = 2;
	}

	else
	{
		time -= 10;
	}


	return time;
}

// Allows the player to see what their score is
bool SystemManager::proceed(bool isFinish)
{
	if (getInput()->getKeyState(getInput()->ENTER_KEY))
	{
		isFinish = true;
	}

	else
	{
		isFinish = false;
	}
	
	return isFinish;
}