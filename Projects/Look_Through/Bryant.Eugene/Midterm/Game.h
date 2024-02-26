/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <Vector2D.h>
#include <PerformanceTracker.h>
#include "Trackable.h"
#include "Sprite.h"
#include "UnitManager.h"
#include "Font.h"
#include "Color.h"
#include "EventListeners.h"
#include "EventSystems.h"
#include "Events.h"

using namespace std;

class GraphicsSystem;
class InputSystem;
class GraphicsBuffer;
class GraphicsBufferManager;
class Sprite;
class Animation;
class Unit;
class UnitManager;
class Font;
class Color;
class HUD;
class LevelManager;
class SnakeManager;
class FoodManager;
class WallManager;
class PowerUpManager;

const string ASSET_PATH = "..\\..\\common\\assets\\";
const string MY_ASSET_PATH = "Assets\\";
const string FONT_FILENAME = "cour.ttf";
const string COLOR_BACKGROUND_FILENAME = "ColorBackground.png";
const string SNAKE_HEAD_FILENAME = "SnakeHead.png";
const string SNAKE_BODY_FILENAME = "SnakeBody.png";
const string FOOD_FILENAME = "Food.png";
const string WALL_FILENAME = "Wall.png";
const string POWER_UP_FILENAME = "Power.png";

const int GRIDSIZE = 50;



class Game : public Trackable
{
	friend class Unit;
private:
	GraphicsSystem* mpgsystem;
	InputSystem* mpisystem;
	GraphicsBuffer* mpbuffer;
	GraphicsBufferManager* mpbufferManager;
	Sprite* mpsprite;
	Sprite* mpSnakeh;
	Sprite* mpSnakeb;
	Sprite* mpsFood;
	Sprite* mpsWall;
	Animation* mpAnimate;
	UnitManager* mpunitManager;

	GraphicsBuffer* mpBackGround;
	GraphicsBuffer* mpWall;
	GraphicsBuffer* mpSnakeBody;
	GraphicsBuffer* mpSnakeHead;
	GraphicsBuffer* mpFood;
	GraphicsBuffer* mpPower;

	Animation* mpaSnakeHead;
	Animation* mpaSnakeBody;
	Animation* mpaPower;
	Animation* mpaFood;

	Unit* mpUnit1;
	Unit* mpuWall;
	Unit* mpuFood;

	int ranX = rand() % 16;
	int ranY = rand() % 12;
	Vector2D randomPosition = Vector2D(ranX * GRIDSIZE, ranY * GRIDSIZE);

	Vector2D mlocation = Vector2D(0, 0);

	Font* mpFont;
	Color* mpColorWhite;
	Color* mpColorBlack;
	
	EventSystem* mpesystem;
	EventListener* mplisten;

	HUD* mpHUD;
	LevelManager* mpLevelManager;
	SnakeManager* mpSnakeManager;
	FoodManager* mpFoodManager;
	WallManager* mpWallManager;
	PowerUpManager* mpPowerUpManager;
	int ranpX = rand() % 16;
	int ranpY = rand() % 12;

	static Game* mpsGame;

	float mRate = 60.0f;
	bool misAnimated;

	

	Game(int width, int height);
	Game() {};
	~Game();

public:
	
	

	static Game* getInstance();
	static void createInstance();
	static void destroyInstance();

	void init();
	void cleanup();
	void doLoop();

	GraphicsSystem* getSystem();
	InputSystem* getInputSystem();
	GraphicsBuffer* getGraphicsBuffer();
	GraphicsBufferManager* getGraphicsBufferManager();
	UnitManager* getUnitManager();
	Sprite* getSprite();
	Animation* getAnimation();
	Vector2D getLocation();
	Font* getFont();
	HUD* getHUD();
	LevelManager* getLevelManager();
	SnakeManager* getSnakeManager();
	WallManager* getWallManager() { return mpWallManager; };
	FoodManager* getFoodManager();

};
