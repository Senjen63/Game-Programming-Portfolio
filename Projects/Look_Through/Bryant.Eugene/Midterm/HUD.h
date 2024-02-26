#pragma once

#include <iostream>
#include "Trackable.h"
#include "Game.h"

using namespace std;

class GraphicsSystem;
class GraphicsBuffer;
class Font;
class Color;
class Sprite;
class Game;

//const string ASSET_PATH = "..\\..\\common\\assets\\";
//const string MY_ASSET_PATH = "..\\..\\Midterm\\Assets\\";
//const string FONT_FILENAME = "cour.ttf";

class HUD :public Trackable
{
private:

	GraphicsSystem* mpGraphicsSystem;
	GraphicsBuffer* mpGraphicsBuffer;
	Font* mpFont;
	Sprite* mpSprite;

	Color* mpColorWhite;
	int mScoreN;
	string mScoreS;
	

public:
	HUD();
	~HUD();

	void hudInit();

	void displayScreen();
	void displayScore();
	void displayPlayAgain();
	void displayWin();
	void displayLose();
	void addScore(int score);
	string getScore();
	string sResetScore();
	int nResetScore();
	void convertIntToString();
	void clearScreen(Color* color);

	GraphicsSystem* getGraphicsSystem() { return mpGraphicsSystem; };
	GraphicsBuffer* getGraphicsBuffer() { return mpGraphicsBuffer; };
	Font* getFont() { return mpFont; };
	Sprite* getSprite() { return mpSprite; };
};