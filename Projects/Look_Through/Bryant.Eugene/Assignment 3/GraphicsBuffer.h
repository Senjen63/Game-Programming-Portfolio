#pragma once
/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
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
#include "Trackable.h"
using namespace std;
class Color;
class GraphicsBuffer : public Trackable
{
	friend class GraphicsSystem;
private:
	ALLEGRO_BITMAP* mpbitmap = nullptr;
	int mheight = 0;
	int mwidth = 0;
	const string ASSET_PATH = "..\\..\\common\\assets\\";
	
	ALLEGRO_BITMAP* getBitmap() { return mpbitmap; }
	bool mOwnsBitmap;

public:
	GraphicsBuffer(string filename, int height, int width);
	GraphicsBuffer() {};
	~GraphicsBuffer();
	void createColorBuffer(Color color, int height, int width);
	int getHeight() { return mheight; }
	int getWidth() { return mwidth; }
};