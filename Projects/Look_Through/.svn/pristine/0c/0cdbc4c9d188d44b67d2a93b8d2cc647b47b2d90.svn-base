/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Game.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "InputSystem.h"
#include "Sprite.h"
#include "Animation.h"
#include "Unit.h"
#include "Events.h"
#include "HUD.h"
#include "SoundSystem.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "Blaster.h"
#include "SystemManager.h"

#include <Timer.h>

Game* Game::mpsGame = NULL;



Game::Game(int width, int height)
{
	mpgsystem = new GraphicsSystem(width, height);
	mpisystem = new InputSystem();
}

Game::Game()
{
	mpgsystem = nullptr;
	mpisystem = nullptr;
	mpbuffer = nullptr;
	mpAnimate = nullptr;
	mlocation = Vector2D(0, 0);
	mpFont = nullptr;
	mpColorWhite = nullptr;
	mpColorBlack = nullptr;
	mpHUD = nullptr;
	mRate = 0.0f;
	misAnimated = true;
	mpSoundSystem = nullptr;
}

Game::~Game()
{
	cleanup();
}

void Game::createInstance()
{
	if (mpsGame == NULL)
	{
		mpsGame = new Game;
	}
}

void Game::destroyInstance()
{
	delete mpsGame;
}

Game* Game::getInstance()
{
	return mpsGame;
}

void Game::init()
{
	mpgsystem = new GraphicsSystem(700, 900);
	mpisystem = new InputSystem();
	mpHUD = new HUD;
	mpSoundSystem = new SoundSystem();
	mpPlayerManager = new PlayerManager();
	mpEnemyManager = new EnemyManager();
	mpBlaster = new Blaster;
	mpSystemManager = new SystemManager();
	getSystem()->init();
	getInputSystem()->init();
	getHUD()->hudInit();
	mpSoundSystem->init();
	mpPlayerManager->init();
	mpEnemyManager->init();
	mpBlaster->init(mpPlayerManager);
	mpSystemManager->init();
	

	mpColorWhite = new Color(0, 255, 0);
	mpColorBlack = new Color(0, 0, 0);

	mlocation = Vector2D(0, 0);

	mpFont = new Font (FONT_FILENAME, 30);

	mpPlayer = new GraphicsBuffer(PLAYER_FILENAME, 591, 591);
	mpsPlayer = new Sprite(mlocation, 591, 591, mpPlayer);

	mpEnemy = new GraphicsBuffer(ENEMY_FILENAME, 860, 459);
	mpsEnemy = new Sprite(mlocation, 860, 459, mpEnemy);

	mpBullet = new GraphicsBuffer(BLASTER_FILE, 591, 591);
	mpaBullet = new Animation(mpBullet, 11, 11, 591, 591, 60.0f);
}

void Game::cleanup()
{
	mpgsystem->cleanup();
	mpisystem->cleanup();
	delete mpgsystem;
	delete mpisystem;
	delete mpHUD;
	delete mpColorWhite;
	delete mpColorBlack;
	delete mpFont;
	delete mpSoundSystem;
	delete mpPlayer;
	delete mpsPlayer;
	delete mpPlayerManager;
	delete mpEnemy;
	delete mpsEnemy;
	delete mpEnemyManager;
	delete mpBullet;
	delete mpaBullet;
	delete mpBlaster;
	delete mpSystemManager;
}

void Game::doLoop()
{
	Timer time;
	bool keepGoing = true;
	PerformanceTracker* pTracker = new PerformanceTracker();
	float timing = .0005;
	bool playAgain = true;
	bool play = false;
	
	float onOff = 1;
	int score = 0;
	int lives = 3;
	bool isFired = false;
	double playerScale = 0.5;
	double enemyScale = 0.2;
	bool isSaved = false;
	bool isFinish = false;
	bool isloaded = false;
	getSoundSystem()->loadAudio();
	int size = getEnemyManager()->getEnemy().size();
	
	
	
	while (playAgain && lives != 0)
	{
		getHUD()->clearScreen(getBlack());
		getHUD()->displayMainMenu();

		if (onOff == 1)
		{
			play = getSoundSystem()->playIntro(play);
		}
		
		else if(onOff == 0)
		{
			play = getSoundSystem()->stopIntro(play);
		}

		if (getInputSystem()->getKeyState(getInputSystem()->O_KEY))
		{
			play = getSoundSystem()->stopIntro(play);
			
			if (onOff == 1)
			{
				play = getSoundSystem()->playOption(play);
			}

			else if (onOff == 0)
			{
				play = getSoundSystem()->stopOption(play);
			}			
			
			getHUD()->clearScreen(getBlack());
			getSystemManager()->options(getHUD());
			
			deltaTime = getSystemManager()->getSpeed(deltaTime);
			play = getSoundSystem()->stopOption(play);
			if (onOff == 1)
			{
				play = getSoundSystem()->playIntro(play);
			}

			else if (onOff == 0)
			{
				play = getSoundSystem()->stopIntro(play);
			}

			onOff = getSystemManager()->onOff(onOff);
		}
		
		if (getInputSystem()->getKeyState(getInputSystem()->L_KEY))
		{
			getHUD()->clearScreen(getBlack());
			getSystemManager()->loadGame(getPlayerManager(), getEnemyManager());
			cout << "Player Position Loaded: " << getPlayerManager()->getPlayer()->getSource() << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "Enemy Position " << i <<" Loaded" << getEnemyManager()->getEnemies(i)->getSource() << endl;
			}
			
			deltaTime = getSystemManager()->getSpeed(deltaTime);
			cout << "Speed Loaded: " << deltaTime << endl;

			score = getSystemManager()->loadScore(score);
			cout << "Score Loaded: " << score << endl;
			
			isloaded = true;
		}

		keepGoing = getSystemManager()->quit(keepGoing);
		playAgain = getSystemManager()->quit(playAgain);
		
		if(getInputSystem()->getKeyState(getInputSystem()->P_KEY)
			|| isloaded)
		{
			play = getSoundSystem()->stopIntro(play);

			while (keepGoing && lives != 0)
			{
				time.start();
				pTracker->clearTracker("pTracker");
				pTracker->startTracking("pTracker");
				
				if (onOff == 1)
				{
					play = getSoundSystem()->playGame(play);
				}

				else if(onOff == 0)
				{
					play = getSoundSystem()->stopGame(play);
				}
				
				getHUD()->clearScreen(getBlack());

				//Quick Save

				keepGoing = getSystemManager()->quit(keepGoing);
				playAgain = getSystemManager()->quit(playAgain);

				getHUD()->displayScore(score);
				getHUD()->displayElapsedTime(pTracker->getElapsedTime("pTracker"));
				getHUD()->displayLives(lives);
				
				for (int j = 0; j < size; j++)
				{
					if (getEnemyManager()->getEnemies(j)->getSource().getY() >= 990)
					{
						lives -= 1;
					}
				}

				getBlaster()->getBullet()->setAnimation(mpaBullet);

				getAnimatedBullet()->update();
				getBlaster()->update(getPlayerManager(), getEnemyManager());

				getSystem()->draw(getPlayerManager()->getPlayer()->getSource(), getPlayerSprite(), playerScale);
				getPlayerManager()->movement();

				for (int i = 0; i < size; i++)
				{
					getSystem()->draw(getEnemyManager()->getEnemies(i)->getSource(), getEnemySprite(), enemyScale);
				}

				 // Enemy movement updated
				getEnemyManager()->enemyMovement();

				// when the blaster is fired
				getBlaster()->fire();
				isFired = getBlaster()->isFired(isFired);

				for (int j = 0; j < size; j++)
				{
					if (getEnemyManager()->getEnemies(j)->getSource().getX() < 
						getBlaster()->getBullet()->getSource().getX()
						&&
						getBlaster()->getBullet()->getSource().getX() < 
						getEnemyManager()->getEnemies(j)->getSource().getX() + 
						(getSpriteEnemy()->getWidth() * enemyScale)
						&&
						getEnemyManager()->getEnemies(j)->getSource().getY() < 
						getBlaster()->getBullet()->getSource().getY()
						&&
						getBlaster()->getBullet()->getSource().getY() <
						getEnemyManager()->getEnemies(j)->getSource().getY() + 
						(getSpriteEnemy()->getHeight() * enemyScale) && isFired)
					{
						score += 50;
						getEnemyManager()->reset(j);
						getBlaster()->reset(getPlayerManager());
						deltaTime = getSystemManager()->speedUp(deltaTime);
						isFired = false;
					}
				}

				for (int h = 0; h < size; h++)
				{
					if (getEnemyManager()->getEnemies(h)->getSource().getX() <
						getPlayerManager()->getPlayer()->getSource().getX()
						&& getPlayerManager()->getPlayer()->getSource().getX() <
						getEnemyManager()->getEnemies(h)->getSource().getX() + 
						(getSpriteEnemy()->getWidth() * enemyScale)
						&& getEnemyManager()->getEnemies(h)->getSource().getY() <
						getPlayerManager()->getPlayer()->getSource().getY()
						&& getPlayerManager()->getPlayer()->getSource().getY() <
						getEnemyManager()->getEnemies(h)->getSource().getY() + 
						(getSpriteEnemy()->getHeight() * enemyScale)
						 && !isFired)
					{
						cout << "GAME OVER!!" << endl;

						while (!isFinish)
						{
							getHUD()->clearScreen(getBlack());
							getSoundSystem()->stopGame(true);
							getHUD()->displayGameOver();

							isFinish = getSystemManager()->proceed(isFinish);
							
							getSystem()->flip();
						}

						keepGoing = false;
						playAgain = false;
					}
				}

				if (lives == 0)
				{
					cout << "GAME OVER!!" << endl;

					while (!isFinish)
					{
						getHUD()->clearScreen(getBlack());
						getSoundSystem()->stopGame(true);
						getHUD()->displayGameOver();

						isFinish = getSystemManager()->proceed(isFinish);

						getSystem()->flip();
					}

					keepGoing = false;
					playAgain = false;
				}

				getSystem()->flip();

				time.sleepUntilElapsed(deltaTime);
				pTracker->stopTracking("pTracker");
			}
		}
		getSystem()->flip();
	}

	for (int g = 0; g < size; g++)
	{
		if (getEnemyManager()->getEnemies(g)->getSource().getX() <
			getPlayerManager()->getPlayer()->getSource().getX()
			&& getPlayerManager()->getPlayer()->getSource().getX() <
			getEnemyManager()->getEnemies(g)->getSource().getX() + 
			(getSpriteEnemy()->getWidth() * enemyScale)
			&& getEnemyManager()->getEnemies(g)->getSource().getY() <
			getPlayerManager()->getPlayer()->getSource().getY()
			&& getPlayerManager()->getPlayer()->getSource().getY() <
			getEnemyManager()->getEnemies(g)->getSource().getY() + 
			(getSpriteEnemy()->getHeight() * enemyScale)
			|| getEnemyManager()->getEnemies(g)->getSource().getY() >= 1000)
		{
			getEnemyManager()->reset(g);
		}

		else if (!(getPlayerManager()->getPlayer()->getSource() ==
			getEnemyManager()->getEnemies(g)->getSource()) && !isSaved
			|| !(getEnemyManager()->getEnemies(g)->getSource().getY() >= 1000) && !isSaved)
		{
			getSystemManager()->saveGame(getPlayerManager(), getEnemyManager(), deltaTime);
			cout << "Game Saved" << endl;
			getHUD()->addScore(score);
			getSystemManager()->saveScore(getHUD());
			cout << "Score Saved" << endl;
			isSaved = true;
		}
	}

	delete pTracker;
}