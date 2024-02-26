/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */
#include "Font.h"

Font::Font(string fountName /*rewording of fileName*/, int fontsize)
{
	mfontSize = fontsize;
	mpfont = al_load_ttf_font((ASSET_PATH + fountName).c_str(), mfontSize, 0);
	assert(mpfont);
}

Font::Font(ALLEGRO_FONT* pfont, int size)
{
	mpfont = pfont;
	mfontSize = size;
}

Font::Font()
{
	mpfont = nullptr;
	mfontSize = 0;
}

Font::~Font()
{
	al_destroy_font(mpfont);
	mpfont = NULL;
}