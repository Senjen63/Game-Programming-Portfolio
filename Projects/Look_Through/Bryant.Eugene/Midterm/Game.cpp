/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Game.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "GraphicsBufferManager.h"
#include "InputSystem.h"
#include "Sprite.h"
#include "Animation.h"
#include "Unit.h"
#include "UnitManager.h"
#include "EventListeners.h"
#include "EventSystems.h"
#include "Events.h"
#include "HUD.h"
#include "SnakeManager.h"
#include "WallManager.h"
#include "PowerUpManager.h"
#include "FoodManager.h"
#include "LevelManager.h"
#include <Timer.h>

Game* Game::mpsGame = NULL;



Game::Game(int width, int height)
{
	//mpgsystem = new GraphicsSystem(width, height);
	//mpisystem = new InputSystem();
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
	mpgsystem = new GraphicsSystem(800, 600);
	mpisystem = new InputSystem();
	mpHUD = new HUD;
	mpSnakeManager = new SnakeManager;
	mpSnakeManager->init();
	mpWallManager = new WallManager();
	mpWallManager->init();
	mpPowerUpManager = new PowerUpManager();
	mpPowerUpManager->init();
	mpFoodManager = new FoodManager();
	mpFoodManager->init();
	mpLevelManager = new LevelManager();
	mpLevelManager->init();
	getSystem()->init();
	getInputSystem()->init();
	getHUD()->hudInit();

	

	mpColorWhite = new Color(0, 255, 0);
	mpColorBlack = new Color(0, 0, 0);

	mpWall = new GraphicsBuffer(WALL_FILENAME, 50, 50);
	mpSnakeBody = new GraphicsBuffer(SNAKE_BODY_FILENAME, 50, 50);
	mpSnakeHead = new GraphicsBuffer(SNAKE_HEAD_FILENAME, 50, 50);
	mpFood = new GraphicsBuffer(FOOD_FILENAME, 50, 50);
	mpPower = new GraphicsBuffer(POWER_UP_FILENAME, 50, 50);

	mlocation = Vector2D(0, 0);
	mpSnakeh = new Sprite(mlocation, 20, 20, mpSnakeHead);
	mpSnakeb = new Sprite(mlocation, 20, 20, mpSnakeBody);
	//mpsFood = new Sprite(mlocation, 20, 20, mpFood);
	mpsWall = new Sprite(mlocation, 20, 20, mpWall);

	mpFont = new Font (FONT_FILENAME, 30);
	
	mpUnit1 = new Unit(mlocation);
	mpuWall = new Unit(Vector2D(0, 0));
	
	mpuFood = new Unit(randomPosition);
	mpunitManager = new UnitManager();
	

	mpaPower = new Animation(mpPower, 10, 10, 225, 225, 60.0f);
	mpaFood = new Animation(mpFood, 10, 10, 255, 255, 60.0f);
	mpesystem = EventSystem::getInstance();
	mplisten = new EventListener();

	srand(time(NULL));
}

void Game::cleanup()
{
	
	mpgsystem->cleanup();
	mpisystem->cleanup();
	mpesystem->cleanup();
	delete mpgsystem;
	delete mpisystem;
	delete mpHUD;
	delete mpSnakeManager;
	delete mpWallManager;
	delete mpPowerUpManager;
	delete mpFoodManager;
	delete mpLevelManager;
	delete mpColorWhite;
	delete mpColorBlack;
	delete mpWall;
	delete mpSnakeBody;
	delete mpSnakeHead;
	delete mpFood;
	delete mpPower;
	delete mpSnakeh;
	delete mpSnakeb;
	//delete mpsFood;
	delete mpsWall;
	delete mpFont;
	delete mpUnit1;
	delete mpuWall;
	delete mpuFood;
	delete mpunitManager;
	delete mpaPower;
	delete mplisten;
	delete mpaFood;
}

void Game::doLoop()
{
	mpesystem->fireEvent(AddScoreEvent());
	
	Timer time;
	bool leave = false;
	PerformanceTracker* pTracker = new PerformanceTracker();
	float timing = .0005;
	float animationTimer = 0;
	int numberOfUnit = 0;
	bool playAgain = true;
	bool startOver = false;
	int score = 0;
	int body = 0;
	float deltaTime = 120.0f;
	int leval = 0;
	int wallSize = mpWallManager->getWallVector().size();
	ranpX = rand() % 16;
	ranpY = rand() % 12;
	int size = mpSnakeManager->getBodyVector().size();
	
	
	
	while (playAgain)
	{
		mpHUD->displayScreen();
		getSystem()->flip();		
		
		
		
		if(getInputSystem()->getKeyState(getInputSystem()->SPACEBAR_KEY))
		{
			leave = false;
			while (!leave)
			{
				
				mpHUD->clearScreen(mpColorBlack);

				//mpesystem->fireEvent(AddScoreEvent());

				time.start();
				pTracker->clearTracker("pTracker");
				pTracker->startTracking("pTracker");


				//walls
				
				for (int i = 0; i < wallSize; i++)
				{
					getSystem()->draw(mpWallManager->getWall(i)->getSource(), mpsWall, 1.0);
				}

				

				//Snake Body
				
				
				for (int i = 0; i < body; i++)
				{
					if (body > size)
					{
						i = i - 1;
					}
					getSystem()->draw(mpSnakeManager->getBodyVector()[i]->getSource(), mpSnakeb, 1.0);
				}
				getSystem()->draw(mpSnakeManager->getHead()->getSource(), mpSnakeh, 1.0);				
				
				mpPowerUpManager->getPowerUp()->setAnimation(mpaPower);
				mpPowerUpManager->getPowerUp()->draw();



		/**************************************Power Up***********************************************************************************/
				// if the speed up power block is set to same positon as any of the walls
				for (int j = 0; j < wallSize; j++)
				{
					if (mpPowerUpManager->getPowerUp()->getSource() == mpWallManager->getWall(j)->getSource())
					{
						mpPowerUpManager->spRandom();
						mpPowerUpManager->getPowerUp()->draw();
					}
				}
				if (mpPowerUpManager->getPowerUp()->getSource() == mpPowerUpManager->getPowerDown()->getSource())
				{
					mpPowerUpManager->spRandom();
					mpPowerUpManager->getPowerUp()->draw();
				}

				if (mpPowerUpManager->getPowerUp()->getSource() == mpFoodManager->getFood()->getSource())
				{
					mpPowerUpManager->spRandom();
					mpPowerUpManager->getPowerUp()->draw();
				}


		/*************************************************************************************************************************/
				
				
				mpPowerUpManager->getPowerDown()->setAnimation(mpaPower);

				mpPowerUpManager->getPowerDown()->draw();
		


		/***************************************************Power Down**********************************************************************/
				// if the slow down power block is set to same positon as any of the walls
				for (int j = 0; j < wallSize; j++)
				{
					if (mpPowerUpManager->getPowerDown()->getSource() == mpWallManager->getWall(j)->getSource())
					{
						mpPowerUpManager->slRandom();
						mpPowerUpManager->getPowerDown()->draw();
					}
				}

				if (mpPowerUpManager->getPowerDown()->getSource() == mpPowerUpManager->getPowerUp()->getSource())
				{
					mpPowerUpManager->slRandom();
					mpPowerUpManager->getPowerDown()->draw();
				}

				if (mpPowerUpManager->getPowerDown()->getSource() == mpFoodManager->getFood()->getSource())
				{
					mpPowerUpManager->slRandom();
					mpPowerUpManager->getPowerDown()->draw();
				}

				mpaPower->speedUp(175);
				
				mpaPower->update();
				
		/*************************************************************************************************************************/
				
		
		/***************************************************Food**********************************************************************/

				// if food is set to same positon as any of the walls
				mpFoodManager->getFood()->setAnimation(mpaFood);
				getSystem()->draw(mpFoodManager->getFood()->getSource(), mpFoodManager->getFood()->getAnimation()->getCurrentSprite(), 0.07);
				//mpFoodManager->getFood()->draw();

				for (int j = 0; j < wallSize; j++)
				{
					if (mpFoodManager->getFood()->getSource() == mpWallManager->getWall(j)->getSource())
					{
						mpFoodManager->random();
						getSystem()->draw(mpFoodManager->getFood()->getSource(), mpFoodManager->getFood()->getAnimation()->getCurrentSprite(), 0.07);
					}
				}

				if (mpFoodManager->getFood()->getSource() == mpPowerUpManager->getPowerUp()->getSource())
				{
					mpFoodManager->random();
					getSystem()->draw(mpFoodManager->getFood()->getSource(), mpFoodManager->getFood()->getAnimation()->getCurrentSprite(), 0.07);
				}

				if (mpFoodManager->getFood()->getSource() == mpPowerUpManager->getPowerDown()->getSource())
				{
					mpFoodManager->random();
					getSystem()->draw(mpFoodManager->getFood()->getSource(), mpFoodManager->getFood()->getAnimation()->getCurrentSprite(), 0.07);
				}

				mpaFood->speedUp(175);

				mpaFood->update();

		/*************************************************************************************************************************/
				if (mpSnakeManager->getHead()->getSource().getX() == mpFoodManager->getFood()->getSource().getX()
					&& mpSnakeManager->getHead()->getSource().getY() == mpFoodManager->getFood()->getSource().getY())
				{
					body++;
				}
				
				

				if (mpSnakeManager->getHead()->getSource().getX() == mpFoodManager->getFood()->getSource().getX()
					&& mpSnakeManager->getHead()->getSource().getY() == mpFoodManager->getFood()->getSource().getY())
				{
					score += 100;
					mpHUD->addScore(score);
					mpFoodManager->random();
				}

				//Emergency escape
				if (getInputSystem()->getKeyState(getInputSystem()->ESCAPE_KEY))
				{
					leave = true;
					playAgain = false;
				}

				for (int i = 0; i < wallSize; i++)
				{
					if (mpSnakeManager->getHead()->getSource().getX() ==
						mpWallManager->getWall(i)->getSource().getX() &&
						mpSnakeManager->getHead()->getSource().getY() ==
						mpWallManager->getWall(i)->getSource().getY())
					{
						mpHUD->clearScreen(mpColorBlack);
						mpHUD->displayPlayAgain();
						mpHUD->displayLose();
						score = 0;
						mpHUD->nResetScore();
						mpHUD->sResetScore();
						deltaTime = 120.0f;
						getSystem()->flip();
						while (!startOver)
						{
							if (getInputSystem()->getKeyState(getInputSystem()->N_KEY))
							{
								leave = true;
								playAgain = false;
								startOver = true;
							}

							if (getInputSystem()->getKeyState(getInputSystem()->Y_KEY))
							{
								startOver = true;
								//leave = true;
								//mpSnakeManager->rest();
							}
						}


						mpHUD->clearScreen(mpColorBlack);
						startOver = false;
						body = 0;
					}
					
				}

				
				for (int s = 0; s < size; s++)
				{
					cout << mpSnakeManager->getHead()->getSource() << endl;
					cout << mpSnakeManager->getBodyVector()[s]->getSource() << endl;
					if (mpSnakeManager->getHead()->getSource() == mpSnakeManager->getBodyVector()[s]->getSource())
					{
						mpHUD->clearScreen(mpColorBlack);
						mpHUD->displayLose();
						mpHUD->displayPlayAgain();
						deltaTime = 120.0f;
						score = 0;
						mpHUD->nResetScore();
						mpHUD->sResetScore();
						getSystem()->flip();
						while (!startOver)
						{
							if (getInputSystem()->getKeyState(getInputSystem()->N_KEY))
							{
								leave = true;
								playAgain = false;
								startOver = true;
							}

							if (getInputSystem()->getKeyState(getInputSystem()->Y_KEY))
							{
								startOver = true;
								//mpSnakeManager->rest();
							}
						}
						body = 0;

						mpHUD->clearScreen(mpColorBlack);
						startOver = false;
					}
				}
				

				if (body == 5 && leval == 1)
				{
					mpHUD->clearScreen(mpColorBlack);
					mpHUD->displayPlayAgain();
					mpHUD->displayWin();
					score = 0;
					mpHUD->nResetScore();
					mpHUD->sResetScore();
					deltaTime = 120.0f;
					getSystem()->flip();
					
					while (!startOver)
					{
						if (getInputSystem()->getKeyState(getInputSystem()->N_KEY))
						{
							//break;
							leave = true;
							playAgain = false;
							startOver = true;
						}

						if (getInputSystem()->getKeyState(getInputSystem()->Y_KEY))
						{
							startOver = true;
							leave = true;
							mpSnakeManager->rest();
							//mpSnakeManager->reset();
							//mpWallManager->reset();
							leval = 0;
						}
						body = 0;
						
					}


					mpHUD->clearScreen(mpColorBlack);
					startOver = false;
				}

				else if (body == 3 && leval == 0)
				{
					mpHUD->clearScreen(mpColorBlack);
					//mpHUD->displayPlayAgain();
					mpHUD->displayWin();
					score = 0;
					mpHUD->nResetScore();
					mpHUD->sResetScore();
					deltaTime = 120.0f;
					leval++;
					getSystem()->flip();
					while (!startOver)
					{

						if (getInputSystem()->getKeyState(getInputSystem()->SPACEBAR_KEY))
						{
							startOver = true;
							mpSnakeManager->rest();
							mpLevelManager->difficulty();
						}
						body = 0;
						size = mpSnakeManager->getBodyVector().size();
						
					}


					mpHUD->clearScreen(mpColorBlack);
					startOver = false;
				}
				mpHUD->displayScore();
				mpSnakeManager->movement();
				getSystem()->flip();

				if (mpPowerUpManager->getPowerUp()->getSource().getX() ==
					mpSnakeManager->getHead()->getSource().getX() &&
					mpPowerUpManager->getPowerUp()->getSource().getY() ==
					mpSnakeManager->getHead()->getSource().getY())
				{
					deltaTime = mpPowerUpManager->speedUp(deltaTime);
					mpPowerUpManager->spRandom();
				}

				else if (mpPowerUpManager->getPowerDown()->getSource().getX() ==
					mpSnakeManager->getHead()->getSource().getX() &&
					mpPowerUpManager->getPowerDown()->getSource().getY() ==
					mpSnakeManager->getHead()->getSource().getY())
					 {
						 deltaTime = mpPowerUpManager->slowDown(deltaTime);
						 mpPowerUpManager->slRandom();
					 }



				time.sleepUntilElapsed(deltaTime);
				pTracker->stopTracking("pTracker");
				//cout << pTracker->getElapsedTime("pTracker") << endl;
			}
		}
		//getSystem()->flip();
	}
	delete pTracker;
}

Sprite* Game::getSprite()
{ 
	return mpsprite; 
}

GraphicsSystem* Game::getSystem()
{
	return mpgsystem;
}

InputSystem* Game::getInputSystem()
{
	return mpisystem;
}

GraphicsBuffer* Game::getGraphicsBuffer()
{
	return mpbuffer;
}

GraphicsBufferManager* Game::getGraphicsBufferManager()
{
	return mpbufferManager;
}

UnitManager* Game::getUnitManager()
{
	return mpunitManager;
}

Animation* Game::getAnimation()
{
	return mpAnimate;
}

Vector2D Game::getLocation()
{
	return mlocation;
}

Font* Game::getFont()
{
	return mpFont;
}

HUD* Game::getHUD()
{
	return mpHUD;
}

LevelManager* Game::getLevelManager()
{
	return mpLevelManager;
}

SnakeManager* Game::getSnakeManager()
{
	return mpSnakeManager;
}

FoodManager* Game::getFoodManager()
{
	return mpFoodManager;
}