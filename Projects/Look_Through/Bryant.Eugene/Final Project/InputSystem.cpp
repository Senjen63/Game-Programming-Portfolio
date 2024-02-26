/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "InputSystem.h"
#include "Game.h"

InputSystem::InputSystem()
{
	
}

InputSystem::~InputSystem()
{
	cleanup();
}

void InputSystem::init()
{
	if (!al_init())
	{
		cout << "error initting Allegro\n";
		system("pause");
	}
	if (!al_install_keyboard())
	{
		cout << "error - keyboard not installed\n";
		system("pause");
	}
	if (!al_install_mouse())
	{
		cout << "error - mouse not installed\n";
		system("pause");
	}
	al_install_keyboard();
	al_install_mouse();
}

void InputSystem::cleanup()
{
	al_uninstall_mouse();
	al_uninstall_keyboard();
}

bool InputSystem::getKeyState(mKeyCode key)
{
	al_get_keyboard_state(&mkstate);
	return al_key_down(&mkstate, key);
}

bool InputSystem::getMouseState(mMouseButton button)
{
	al_get_mouse_state(&mmstate);
	return al_mouse_button_down(&mmstate, button);
}

Vector2D InputSystem::getMousePosition() 
{ 
	//al_get_mouse_state(&mmstate);
	ALLEGRO_MOUSE_STATE mouseInput;
	al_get_mouse_state(&mouseInput);

	return Vector2D(mouseInput.x, mouseInput.y);
}