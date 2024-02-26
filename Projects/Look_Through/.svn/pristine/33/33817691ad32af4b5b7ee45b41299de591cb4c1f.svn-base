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

using namespace std;

class GraphicsSystem;
class InputSystem;
class GraphicsBuffer;
class GraphicsBufferManager;
class Sprite;
class Animation;
class Unit;
class UnitManager;

const string ASSET_PATH = "..\\..\\common\\assets\\";
const string BACKGROUND_FILENAME = "Woods.png";
const string DEAN_FILENAME = "dean_sprites.png";
const string SMURFS_FILENAME = "smurf_sprites.png";



class Game : public Trackable
{
	friend class Unit;
private:
	GraphicsSystem* mpgsystem;
	InputSystem* mpisystem;
	GraphicsBuffer* mpbuffer;
	GraphicsBufferManager* mpbufferManager;
	Sprite mpsprite;
	Animation* mpAnimate;
	UnitManager* mpunitManager;

	GraphicsBuffer* mpBackGround;
	GraphicsBuffer* mpSmurf;
	GraphicsBuffer* mpDeanSmurf;

	Animation* mpaSmurf;
	Animation* mpaDean;

	Unit* mpUnit1;

	Vector2D mlocation = Vector2D(0, 0);

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
	Sprite getSprite();
	Animation* getAnimation();
	Vector2D getLocation();
	

};
