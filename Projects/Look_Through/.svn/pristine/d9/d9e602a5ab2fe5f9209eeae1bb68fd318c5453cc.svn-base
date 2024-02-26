#include "GraphicsBuffer.h"
#include <allegro5/allegro.h>

GraphicsBuffer::GraphicsBuffer(std::string filename)
{
	mpBitmap = al_load_bitmap(filename.c_str());
	mOwnsBitmap = true;
}

GraphicsBuffer::GraphicsBuffer(ALLEGRO_BITMAP* pBitmap)
{
	mpBitmap = pBitmap;
	mOwnsBitmap = false;
}

GraphicsBuffer::~GraphicsBuffer()
{
	if (mOwnsBitmap)
	{
		al_destroy_bitmap(mpBitmap);
	}
}


