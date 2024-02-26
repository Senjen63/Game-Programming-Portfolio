#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
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
#include <Vector2D.h>
#include "Trackable.h"

using namespace std;

class GraphicsBuffer;
class Sprite : public Trackable
{
private:
	GraphicsBuffer* mpbitmap;
	Vector2D msourceLoc;
	int mwidth;
	int mheight;

public:
	Sprite(Vector2D sourceLoc, int width, int height, GraphicsBuffer* pbitmap);
	Sprite();
	~Sprite();
	Vector2D getSourceLoc() { return msourceLoc; }
	int getHeight() { return mheight; }
	int getWidth() { return mwidth; }
	GraphicsBuffer* getGraphicsBuffer() { return mpbitmap; }

};