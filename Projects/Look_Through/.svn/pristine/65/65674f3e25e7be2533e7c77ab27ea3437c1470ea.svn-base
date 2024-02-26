/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 1
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include <Vector2D.h>
#include <Timer.h>

#include "Color.h"
#include "Font.h"
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Sprite.h"

using namespace std;

int main()
{
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;

	const string INIT_TRACKER_NAME = "init";
	const string DRAW_TRACKER_NAME = "draw";
	const string WAIT_TRACKER_NAME = "wait";
	const string BACKGROUND_FILENAME = "steps.png";
	const string QUIMBY_FILENAME = "mayor_quimby.png";
	const string SMURFS_FILENAME = "smurf_sprites.png";
	const string FONT_FILENAME = "cour.ttf";
	const int FONT_SIZE = 24;
	Vector2D corner = Vector2D(0, 0);
	Vector2D position;
	
	
	const double SLEEP_TIME = 5.0;

	Timer timer;

	GraphicsSystem sys(800, 600);

	Color red(255, 0, 0);
	Color blue(0, 255, 0);
	Color green(0, 0, 255);
	Color black(0, 0, 0);

	sys.Init();

	srand((unsigned int)time(NULL));
	
	GraphicsBuffer background(BACKGROUND_FILENAME, 1600, 1200);
	GraphicsBuffer smurfs(SMURFS_FILENAME, 240, 240);
	GraphicsBuffer mayorQuimby(QUIMBY_FILENAME, 264, 3999);
	GraphicsBuffer colorBuffer(red, 800, 600); // the Red Buffer

	Sprite block(corner, 800, 600, &colorBuffer); //To place the Red Buffer in front of display but behind Quimby
	
	// s = Sprite
	Sprite sbackground(corner, 1200, 1600, &background);
	Sprite smayorQuimby(corner, 264, 399, &mayorQuimby);
	Sprite ssmurf(corner, 60, 60, &smurfs);

	Font whyYou(FONT_FILENAME, 48); // The variable for the text "Curse you Papa Smurff!!!"
	
	sys.Draw(&colorBuffer, corner, smayorQuimby, 1.0);
	sys.WriteText(&colorBuffer, corner, whyYou, black, "Curse you Papa Smurf!!!");
	sys.Draw(corner, sbackground, 1.0);
	sys.Draw(Vector2D(800 * 0.166667f, 600 * 0.166667f), block, 0.666667f);

	float RX; // Random position X
	float RY; // Random position Y

	//Randomly generates smurfs
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			position.setX(i * 60);
			position.setY(j * 60);

			RX = rand() % (800 - ssmurf.getWidth());
			RY = rand() % (800 - ssmurf.getHeight());

			sys.Draw(Vector2D(RX, RY), ssmurf, 0.25f);
		}
	}

	pPerformanceTracker->stopTracking("loop");
	

	pPerformanceTracker->clearTracker("loop");

	
	

	sys.SaveBuffer(colorBuffer, "redbuffer.jpg"); // saves both the backbuffer and buffer

	sys.Flip();

	timer.sleep(5000.0);

	sys.Cleanup();

	delete pPerformanceTracker;

	MemoryTracker::getInstance()->reportAllocations(cout);
	system("pause");
	return 0;
}