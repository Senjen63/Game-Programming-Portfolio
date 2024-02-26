/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "Animation.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"

Animation::Animation(GraphicsBuffer* frame, int columns, int rows, float bWidth, float bHeight, float time)
{
	float SpriteWidth = bWidth / columns;
	float SpriteHeight = bHeight / rows;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			Vector2D position = Vector2D(SpriteWidth * i, SpriteHeight * j);
			mpspriteL.push_back(new Sprite(position, SpriteWidth, SpriteHeight, frame));
			mnumberSprite++;
			//mcurrentSprite = mnumberSprite - 1;
		}
	}
	mtimeFramePerSecound = time;
}

Animation::Animation()
{
	mcurrentSprite = 0;
	mtimeFramePerSecound = 0.0f;
	mloop = true;
	mtime = 0.0f;
	mtimeL = 0.0f;
	mnumberSprite = 0;
	mLastSprite = 0;
}

Animation::~Animation()
{
	clear();
	int mcurrentSprite = 0;
	double mtimeFramePerSecound = 16;
	bool mloop = false;
	double mtime = 0.0;
	int mnumberSprite = 0;
}

void Animation::addSprite(Sprite* sprite)
{
	mpspriteL.push_back(sprite);
}

void Animation::update()
{
	if (mtimeFramePerSecound < mtimeL)
	{
		mtimeL = 0;
		if (mcurrentSprite < mnumberSprite - 1)
		{
			mcurrentSprite += 1;
		}

		else if (mcurrentSprite == mnumberSprite - 1)
		{
			mcurrentSprite = 0;
		}

	}
	mtimeL++;
}

void Animation::clear()
{
	for (int i = 0; i < mpspriteL.size(); i++)
	{
		delete mpspriteL[i];
	}
	mpspriteL.clear();
}

Sprite* Animation::getCurrentSprite()
{
	return mpspriteL[mcurrentSprite];
}

void Animation::speedUp(float time)
{
	mtimeFramePerSecound -= time;
	if (mtimeFramePerSecound < 0)
	{
		mtimeFramePerSecound = 0;
	}
}

void Animation::slowDown(float time)
{
	mtimeFramePerSecound += time;
}