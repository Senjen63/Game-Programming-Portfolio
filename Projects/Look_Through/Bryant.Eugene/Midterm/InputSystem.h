/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
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

public:

	enum mKeyCode
	{
		F_KEY = ALLEGRO_KEY_F,
		S_KEY = ALLEGRO_KEY_S,
		A_KEY = ALLEGRO_KEY_A,
		D_KEY = ALLEGRO_KEY_D,
		W_KEY = ALLEGRO_KEY_W,
		Y_KEY = ALLEGRO_KEY_Y,
		N_KEY = ALLEGRO_KEY_N,
		ENTER_KEY = ALLEGRO_KEY_ENTER,
		ESCAPE_KEY = ALLEGRO_KEY_ESCAPE,
		SPACEBAR_KEY = ALLEGRO_KEY_SPACE,
		LEFT_ARROW_KEY = ALLEGRO_KEY_LEFT,
		RIGHT_ARROW_KEY = ALLEGRO_KEY_RIGHT,
		UP_ARROW_KEY = ALLEGRO_KEY_UP,
		DOWN_ARROW_KEY = ALLEGRO_KEY_DOWN
	};

	enum mMouseButton
	{
		Left_CLICK = 1,
		RIGHT_CLICK = 2
	};

	InputSystem();
	~InputSystem();

	void init();
	void cleanup();

	bool getKeyState(mKeyCode key);
	bool getMouseState(mMouseButton button);

	Vector2D getMousePosition();
	
private:
	ALLEGRO_KEYBOARD_STATE mkstate; //Key State
	ALLEGRO_MOUSE_STATE mmstate; //Mouse State
	
};