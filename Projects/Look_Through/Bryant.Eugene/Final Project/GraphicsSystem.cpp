/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Font.h"
#include "Color.h"


GraphicsSystem::GraphicsSystem(int width, int height)
{
	mwidth = width;
	mheight = height;
}

GraphicsSystem::GraphicsSystem()
{
	mpdisplay = nullptr;
	mpbackBuffer = nullptr;
	mwidth = 0;
	mheight = 0;
}

GraphicsSystem::~GraphicsSystem()
{
	cleanup();
}
void GraphicsSystem::init()
{
	if (!al_init())
	{
		cout << "error initting Allegro\n";
		system("pause");

	}
	if (!al_init_image_addon())
	{
		cout << "error - Image Add-on not initted\n";
		system("pause");

	}
	if (!al_init_font_addon())
	{
		cout << "error - Font Add-on not initted\n";
		system("pause");

	}
	if (!al_init_ttf_addon())
	{
		cout << "error - TTF Add-on not initted\n";
		system("pause");
		//return 1;
	}
	if (!al_init_primitives_addon())
	{
		cout << "error - primitives Add-on not initted\n";
		system("pause");
		//return 1;
	}
	if (!al_install_audio())
	{
		cout << "error - Audio Add-on not initted\n";
		system("pause");
		//return 1;
	}
	if (!al_init_acodec_addon())
	{
		cout << "error - Audio Codec Add-on not initted\n";
		system("pause");
		//return 1;
	}
	if (!al_reserve_samples(50))
	{
		cout << "error - samples not reserved\n";
		system("pause");
		//return 1;
	}
	mpdisplay = al_create_display(mwidth, mheight);
	assert(mpdisplay);

}
void GraphicsSystem::cleanup()
{
	if (!(mpdisplay == NULL))
	{
		al_destroy_display(mpdisplay);
	}
	mpdisplay = NULL;
}
void GraphicsSystem::flip()
{
	al_flip_display();
}
void GraphicsSystem::draw(Vector2D tLoc, Sprite* spr, float scale)
{
	al_set_target_bitmap(al_get_backbuffer(mpdisplay));
	al_draw_scaled_bitmap(spr->getGraphicsBuffer()->getBitmap(), 
		spr->getSourceLoc().getX(), spr->getSourceLoc().getY(), 
		spr->getWidth(), spr->getHeight(), tLoc.getX(), tLoc.getY(), 
		al_get_bitmap_width(spr->getGraphicsBuffer()->getBitmap()) * scale, 
		al_get_bitmap_height(spr->getGraphicsBuffer()->getBitmap()) * scale, 0);
}
void GraphicsSystem::draw(GraphicsBuffer* ptbuffer, Vector2D tLoc, Sprite* spr, float scale)
{
	al_set_target_bitmap(ptbuffer->getBitmap());
	al_draw_scaled_bitmap(spr->getGraphicsBuffer()->getBitmap(), 
		spr->getSourceLoc().getX(), spr->getSourceLoc().getY(), 
		spr->getWidth(), spr->getHeight(), tLoc.getX(), tLoc.getY(), 
		al_get_bitmap_width(spr->getGraphicsBuffer()->getBitmap()) * scale,
		al_get_bitmap_height(spr->getGraphicsBuffer()->getBitmap()) * scale, 0);
}
void GraphicsSystem::writeText(Vector2D tLoc, Font* font, Color* color, string text)
{
	al_set_target_bitmap(al_get_backbuffer(mpdisplay));
	al_draw_text(font->mpfont, color->mgetColor(), 
		tLoc.getX(), tLoc.getY(), 0, text.c_str());
}
void GraphicsSystem::writeText(GraphicsBuffer* ptbuffer, Vector2D tLoc, Font* font, Color* color, string text)
{
	al_set_target_bitmap(ptbuffer->getBitmap());
	al_draw_text(font->mpfont, color->mgetColor(),
		tLoc.getX(), tLoc.getY(), 0, text.c_str());

}
void GraphicsSystem::saveBuffer(GraphicsBuffer* saveBuffer, string file)
{
	al_save_bitmap(file.c_str(), saveBuffer->getBitmap());
}

