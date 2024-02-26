/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */
#include "Sprite.h"
#include "GraphicsBuffer.h"
Sprite::Sprite(Vector2D sourceLoc, int width, int height, GraphicsBuffer* pbitmap)
{
	mpbitmap = pbitmap;
	msourceLoc = sourceLoc;
	mwidth = width;
	mheight = height;
}

Sprite::Sprite()
{
	mpbitmap = NULL;
	mwidth = 0;
	mheight = 0;
}

Sprite::~Sprite()
{

}