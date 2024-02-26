/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <cassert>
#include <string>
#include <Vector2D.h>
#include "Trackable.h"


using namespace std;

class Animation;
class Game;

class InputSystem : public Trackable
{
	friend class Game;

public:

	enum mKeyCode
	{
		F_KEY = ALLEGRO_KEY_F,
		S_KEY = ALLEGRO_KEY_S,
		ENTER_KEY = ALLEGRO_KEY_ENTER,
		ESCAPE_KEY = ALLEGRO_KEY_ESCAPE
	};


	InputSystem();
	~InputSystem();

	void init();
	void cleanup();

	Vector2D getMousePosition() { return Vector2D(mmstate.x, mmstate.y); };
	
private:
	ALLEGRO_KEYBOARD_STATE mkstate; //Key State
	ALLEGRO_MOUSE_STATE mmstate; //Mouse State
	bool getKeyState(mKeyCode key);
	bool getMouseState();
};