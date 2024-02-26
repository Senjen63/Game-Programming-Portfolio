/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 2
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

using namespace std;

class GraphicsSystem;
class InputSystem;
class GraphicsBuffer;
class Sprite;
class Animation;
class Unit;

const string ASSET_PATH = "..\\..\\common\\assets\\";
const string BACKGROUND_FILENAME = "Woods.png";
const string DEAN_FILENAME = "dean_sprites.png";
const string SMURFS_FILENAME = "smurf_sprites.png";



class Game : public Trackable
{
private:
	GraphicsSystem* mpgsystem;
	InputSystem* mpisystem;
	GraphicsBuffer* mpbuffer;
	Sprite mpsprite;
	Animation* mpAnimate = NULL;

	GraphicsBuffer* mpBackGround;
	GraphicsBuffer* mpSmurf;
	GraphicsBuffer* mpDeanSmurf;

	Animation* mpaSmurf;
	Animation* mpaDean;

	Unit* mpUnit1;

	Vector2D mlocation = Vector2D(0, 0);

	float mRate = 60.0f;
	bool misAnimated;

public:
	Game(int width, int height);
	~Game();

	void init();
	void cleanup();
	void doLoop();

	GraphicsSystem* getSystem() { return mpgsystem; }
	InputSystem* getInputSystem() { return mpisystem; }
	GraphicsBuffer* getGraphicsBuffer() { return mpbuffer; }
	Sprite getSprite();
	Animation* getAnimation() {return mpAnimate;}
	Vector2D getLocation() { return mlocation; }
	

};

extern Game* gpGame;