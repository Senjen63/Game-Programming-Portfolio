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
#include <vector>
#include "Trackable.h"

using namespace std;

class Sprite;
class Timer;
class Trackable;
class GraphicsBuffer;

class Animation : public Trackable
{
private:
	vector <Sprite> mpspriteL;
	int mcurrentSprite = 0;
	float mtimeFramePerSecound = 16.0f;
	bool mloop = false;
	float mtime = 0.0;
	float mtimeL;
	int mnumberSprite = 0;
	int mLastSprite = 0;
	

public:
	Animation(GraphicsBuffer* frame, int columns, int rows, float bWidth, float bHeight, float time);
	~Animation();

	void addSprite(Sprite sprite);
	void update();
	Sprite getCurrentSprite();
	vector <Sprite> getSprite() { return mpspriteL; }
	void speedUp(float time);
	void slowDown(float time);
};