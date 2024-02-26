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
#include "Trackable.h"

using namespace std;

class Animation;
class Game;
class GraphicsSystem;


class Unit : public Trackable
{
private:
	Vector2D mlocation;
	Animation* mpanimate1;

	GraphicsSystem* mpgraphicsSystem;

public:
	Unit(Vector2D vec);
	~Unit();

	void update();
	void draw();
	void setAnimation(Animation* animation);
	void setCurrentSpeed(bool add, float rate);
	void setPosition(Vector2D position);
	Vector2D getSource() { return mlocation; }
	Animation* getAnimation() { return mpanimate1; }
	GraphicsSystem* getGraphicsSystem() { return mpgraphicsSystem; }
};