/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
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
		A_KEY = ALLEGRO_KEY_A,
		D_KEY = ALLEGRO_KEY_D,
		B_KEY = ALLEGRO_KEY_B,
		Y_KEY = ALLEGRO_KEY_Y,
		N_KEY = ALLEGRO_KEY_N,
		P_KEY = ALLEGRO_KEY_P,
		O_KEY = ALLEGRO_KEY_O,
		L_KEY = ALLEGRO_KEY_L,
		Q_KEY = ALLEGRO_KEY_Q,
		ONE_KEY = ALLEGRO_KEY_1,
		TWO_KEY = ALLEGRO_KEY_2,
		E_KEY = ALLEGRO_KEY_E,
		M_KEY = ALLEGRO_KEY_M,
		H_KEY = ALLEGRO_KEY_H,
		ESCAPE_KEY = ALLEGRO_KEY_ESCAPE,
		ENTER_KEY = ALLEGRO_KEY_ENTER,
		SPACEBAR_KEY = ALLEGRO_KEY_SPACE,
		LEFT_ARROW_KEY = ALLEGRO_KEY_LEFT,
		RIGHT_ARROW_KEY = ALLEGRO_KEY_RIGHT
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

	int key;
	
};