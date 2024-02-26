/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 1
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "GraphicsBuffer.h"
#include "Color.h"

GraphicsBuffer::GraphicsBuffer(string filename, int height, int width)
{
	mOwnsBitmap = false;
	mpbitmap = al_load_bitmap((ASSET_PATH + filename).c_str());
	assert(mpbitmap);
	mheight = height;
	mwidth = width;
}

GraphicsBuffer::GraphicsBuffer(Color color, int height, int width)
{
	mOwnsBitmap = false;
	mpbitmap = al_create_bitmap(height, width);
	assert(mpbitmap);

	al_set_target_bitmap(mpbitmap);
	al_clear_to_color(color.mgetColor());
	mheight = height;
	mwidth = width;
}

GraphicsBuffer::~GraphicsBuffer()
{
	if (mOwnsBitmap)
	{
		al_destroy_bitmap(mpbitmap);
		mpbitmap = NULL;
	}
}