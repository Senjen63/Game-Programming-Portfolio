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
class Font : public Trackable
{
	friend class GraphicsSystem;
private:
	ALLEGRO_FONT* mpfont;
	int mfontSize;
	const string ASSET_PATH = "..\\..\\common\\assets\\";
	int getSize() { return mfontSize; }
	ALLEGRO_FONT* getfont() { return mpfont; }
public:
	Font(ALLEGRO_FONT* pfont, int size);
	Font(string fountName /*rewording of fileName*/, int fontsize);
	Font();
	~Font();

};