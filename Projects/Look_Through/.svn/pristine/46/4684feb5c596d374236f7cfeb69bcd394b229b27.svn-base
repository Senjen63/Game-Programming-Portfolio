/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Unit.h"
#include "Animation.h"
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Game.h"
#include "Sprite.h"
#include "InputSystem.h"



Unit::Unit(Vector2D vec)
{
	mlocation = vec;
}

Unit::Unit()
{
	mlocation = Vector2D(0, 0);
	mpanimate1 = nullptr;
	mDestroy = true;
}

Unit::~Unit()
{
	
}

void Unit::update()
{
	Vector2D vec = Game::getInstance()->getInputSystem()->getMousePosition();
	float radius = getAnimation()->getSprite().at(0)->getHeight() * 0.5;
	Vector2D distance = vec - mlocation;
	if (distance.getLengthSquared() < radius * radius && 
		Game::getInstance()->getInputSystem()->getMouseState(InputSystem::mMouseButton::RIGHT_CLICK))
	{
		mDestroy = true;
	}
	getAnimation()->update();
}

void Unit::draw()
{
	Game::getInstance()->getSystem()->draw(getSource(), getAnimation()->getCurrentSprite(), 0.23f);
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