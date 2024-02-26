#pragma once

#include <string>
struct ALLEGRO_BITMAP;

class GraphicsBuffer
{
	friend class GraphicsSystem;
public:
	GraphicsBuffer(std::string filename);
	~GraphicsBuffer();

	GraphicsBuffer(GraphicsBuffer&) = delete;
private:
	GraphicsBuffer(ALLEGRO_BITMAP* pBitmap);

	ALLEGRO_BITMAP* mpBitmap = nullptr;
	ALLEGRO_BITMAP* getBitmap() { return mpBitmap; }

	bool mOwnsBitmap;

};

class Sprite
{
	GraphicsBuffer* mpBuffer;
	int x, y, w, h;
};
/*class Color
{
	friend class GraphicsSystem;
private:
	int mr, mg, mb, ma;
	ALLEGRO_COLOR getColor() { return al_map_rgba(mr, mg, mb, ma); };
};*/

