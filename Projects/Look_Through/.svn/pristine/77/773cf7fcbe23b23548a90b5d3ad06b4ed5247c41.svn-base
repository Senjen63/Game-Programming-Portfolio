/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "GraphicsBuffer.h"
#include "Color.h"

GraphicsBuffer::GraphicsBuffer(string filename, int height, int width)
{
	mOwnsBitmap = false;
	//mpbitmap = al_load_bitmap((ASSET_PATH + filename).c_str());
	mpbitmap = al_load_bitmap((MY_ASSET_PATH + filename).c_str());
	assert(mpbitmap);
	mheight = height;
	mwidth = width;
}

GraphicsBuffer::GraphicsBuffer(Color* color, int height, int width)
{
	mOwnsBitmap = false;
	mpbitmap = al_create_bitmap(height, width);
	assert(mpbitmap);
	al_set_target_bitmap(mpbitmap);
	al_clear_to_color(color->mgetColor());
	mheight = height;
	mwidth = width;
}

GraphicsBuffer::GraphicsBuffer()
{
	mpbitmap = nullptr;
	mheight = 0;
	mwidth = 0;
	mOwnsBitmap = true;
}

GraphicsBuffer::~GraphicsBuffer()
{
	if (!(mpbitmap == NULL))
	{
		al_destroy_bitmap(mpbitmap);
		mpbitmap = NULL;
		//mOwnsBitmap = false;
	}
}

void GraphicsBuffer::createColorBuffer(Color* color, int height, int width)
{
	mOwnsBitmap = false;
	mpbitmap = al_create_bitmap(height, width);
	assert(mpbitmap);
	al_set_target_bitmap(mpbitmap);
	al_clear_to_color(color->mgetColor());
	mheight = height;
	mwidth = width;
}

void GraphicsBuffer::createGraphicsBuffer(string filename, int height, int width)
{
	mOwnsBitmap = false;
	mpbitmap = al_load_bitmap((MY_ASSET_PATH + filename).c_str());
	assert(mpbitmap);
	mheight = height;
	mwidth = width;
}