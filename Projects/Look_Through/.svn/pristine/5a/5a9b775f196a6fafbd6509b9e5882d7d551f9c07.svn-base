/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Unit.h"
#include "Animation.h"
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Game.h"
#include "Sprite.h"



Unit::Unit(Vector2D vec)
{
	mlocation = vec;
}

Unit::~Unit()
{
	
}

void Unit::update()
{
	getAnimation()->update();
}

void Unit::draw()
{
	gpGame->getSystem()->draw(getSource(), getAnimation()->getCurrentSprite(), 0.3f);
}

void Unit::setAnimation(Animation* animation)
{
	mpanimate1 = animation;
}

void Unit::setCurrentSpeed(bool add, float rate)
{
	if (add)
	{
		mpanimate1->speedUp(rate);
	}

	else
	{
		mpanimate1->slowDown(rate);
	}
}

void Unit::setPosition(Vector2D position)
{
	mlocation = position;
}