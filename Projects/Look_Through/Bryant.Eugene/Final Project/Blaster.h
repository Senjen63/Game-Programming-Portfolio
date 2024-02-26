#pragma once

#include <iostream>
#include "Trackable.h"
#include <Vector2D.h>

using namespace std;

class Unit;
class PlayerManager;
class InputSystem;
class EnemyManager;

class Blaster : public Trackable
{
private:
	Unit* mpBullet;

	InputSystem* mpTrigger; // firing input

	Vector2D velocity = Vector2D(0, 20); // how fast the bullet

	/****Bullet Position***************/
	int bulletX;
	int bulletY;
	/**********************************/

	bool mIsFired = false; // checks to see if the bullet is fired

public:

	Blaster();
	~Blaster();

	void init(PlayerManager* player);
	void fire();
	void follow(PlayerManager* player);
	void update(PlayerManager* player, EnemyManager* enemy);
	void reset(PlayerManager* player);
	bool isFired(bool fire);
	Unit* getBullet() { return mpBullet; };
};