#pragma once

#include <iostream>
#include <Vector2D.h>
#include "Trackable.h"

using namespace std;

class Unit;
class InputSystem;

class PlayerManager : public Trackable
{
private:
	Unit* mpPlayer;
	InputSystem* mpController; // controls the player's movement

	Vector2D mGrid = Vector2D(50, 0); // movement

public:

	PlayerManager();
	~PlayerManager();

	void init();

	void movement();

	Unit* getPlayer() { return mpPlayer; };
};