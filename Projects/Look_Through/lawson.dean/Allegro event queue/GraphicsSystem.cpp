#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include <allegro5/allegro.h>

void GraphicsSystem::draw(GraphicsBuffer buff)
{
	al_draw_bitmap(buff.getBitmap(), 0, 0, 0);
}

void GraphicsSystem::draw(Sprite sprite)
{
	al_draw_scaled_bitmap(sprite.getBuffer()->getBitmap())
}
