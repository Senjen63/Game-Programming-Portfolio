#pragma once

class GraphicsBuffer;

class GraphicsSystem
{
public:
	GraphicsSystem() { new GraphicsBuffer(al_get_backbuffer(mpDisplay)); };

	void draw(GraphicsBuffer buff);
	void draw(Sprite sprite);

	GraphicsBuffer* getBackBuffer() {
		return 
	}
private:
	GraphicsBuffer* mpBackBuffer;
};