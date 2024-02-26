#pragma once

#include <allegro5/allegro.h>

enum MyKeyCode
{
	A_KEY = ALLEGRO_KEY_A,
	B_KEY = ALLEGRO_KEY_B
};

class Game
{
public:
	Game();

	void doLoop();
	bool isKeyDown(MyKeyCode theKey);
};
class Animation
{
public:
	Animation() {};
	void update(double dt)
	{
		//timeLeft -= dt
		//if( timeLeft <= 0 )
			//index++
			//timeLeft = timePerFrame
	}
private:
//data
	//list of Sprites
	//timing info
		//how long between frames: timePerFrame
		//how much time left: timeLeft
	//current sprite - index
	//looping?
};
class Unit
{
public:
	Unit() {};
	void update(double dt);

private:
	Animation mAnimation;
};

extern Game* gpGame;
