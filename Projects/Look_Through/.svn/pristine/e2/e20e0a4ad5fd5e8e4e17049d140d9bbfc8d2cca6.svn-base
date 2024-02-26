#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <cassert>
#include <string>
#include "Trackable.h"

using namespace std;

class Color : public Trackable
{
	friend class GraphicsSystem;
	friend class GraphicsBuffer;
private:
	const ALLEGRO_COLOR RED = al_map_rgb(255, 0, 0);
	const ALLEGRO_COLOR BLUE = al_map_rgb(0, 0, 255);
	const ALLEGRO_COLOR GREEN = al_map_rgb(0, 255, 0);
	const ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	const ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	const ALLEGRO_COLOR PURPLE = al_map_rgb(128, 64, 212);

	int mred;
	int mblue;
	int mgreen;

	ALLEGRO_COLOR mgetColor() { return al_map_rgb(mred, mgreen, mblue); }

public:
	Color(int red, int blue, int green);
	Color();

	ALLEGRO_COLOR getRed() { return RED; }
	ALLEGRO_COLOR getBlue() { return BLUE; }
	ALLEGRO_COLOR getGreen() { return GREEN; }
	ALLEGRO_COLOR getBlack() { return BLACK; }
	ALLEGRO_COLOR getWhite() { return WHITE; }
	ALLEGRO_COLOR getPurple() { return PURPLE; }
};