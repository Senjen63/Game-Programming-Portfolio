/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "PlayerManager.h"
#include "Unit.h"
#include "InputSystem.h"

PlayerManager::PlayerManager()
{
	mpPlayer = nullptr;
	mpController = nullptr;
}

PlayerManager::~PlayerManager()
{
	delete mpPlayer;
	delete mpController;
}

void PlayerManager::init()
{
	mpPlayer = new Unit(Vector2D(300, 750));
	mpController = new InputSystem();
}

void PlayerManager::movement()
{
	if (mpController->getKeyState(mpController->D_KEY) ||
		mpController->getKeyState(mpController->RIGHT_ARROW_KEY))
	{
		mpPlayer->setPosition(mpPlayer->getSource() + mGrid);
	}

	if (mpPlayer->getSource().getX() == 650) // if player goes too far to the right
	{
		mpPlayer->setPosition(Vector2D(-50.0, mpPlayer->getSource().getY()));
	}

	if (mpController->getKeyState(mpController->A_KEY) ||
		mpController->getKeyState(mpController->LEFT_ARROW_KEY))
	{
		mpPlayer->setPosition(mpPlayer->getSource() - mGrid);
	}

	if (mpPlayer->getSource().getX() == -100) // if player goes too far to the left
	{
		mpPlayer->setPosition(Vector2D(600.0, mpPlayer->getSource().getY()));
	}
}