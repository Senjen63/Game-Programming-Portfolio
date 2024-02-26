#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 1
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

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

class Sprite;
class GraphicsBuffer;
class Font;
class Color;

class GraphicsSystem : public Trackable
{
private:
	ALLEGRO_DISPLAY* mpdisplay;
	GraphicsBuffer* mpbackBuffer;

	int mwidth;
	int mheight;

	int getHeight() { return al_get_display_height(mpdisplay); }
	int getWidth() { return al_get_display_width(mpdisplay); }
	ALLEGRO_BITMAP* getBackBuffer() { return al_get_backbuffer(mpdisplay); }
	ALLEGRO_DISPLAY* getDisplay() { return mpdisplay; }

public:
	GraphicsSystem(int width, int height);
	~GraphicsSystem();

	void Init();
	void Cleanup();

	

	void Flip();

	void Draw(Vector2D tLoc, Sprite spr, float scale);
	void Draw(GraphicsBuffer* tbuffer, Vector2D tLoc, Sprite spr, float scale);
	void WriteText(Vector2D tLoc, Font font, Color color, string text);
	void WriteText(GraphicsBuffer* tbuffer, Vector2D tLoc, Font font, Color color, string text);
	void SaveBuffer(GraphicsBuffer saveBuffer, string file);
};