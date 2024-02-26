#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include <iostream>
#include "Trackable.h"
#include "Game.h"

using namespace std;

class GraphicsBuffer;
class Font;
class Color;
class Sprite;
class Game;



class HUD :public Trackable
{
private:
	GraphicsBuffer* mpGraphicsBuffer;
	Font* mpFont;
	Sprite* mpSprite;

	Color* mpColorWhite;
	Color* mpColorBlack;

	int mScoreN = 0;
	string mScoreS;

	string mTime; // shows the elasped time
	string mLives; // shows how many lives there are left
	

public:
	HUD();
	~HUD();

	void hudInit();

	void displayScreen();
	void displayScore(int score);
	void displayTotalScore();
	void displayPlayAgain();
	void displayWin();
	void displayLose();
	void displayOptions();
	void displaySound();
	void displaySpeed();
	void displayMainMenu();
	void displayElapsedTime(double elapse);
	void displayLives(int life);
	void displayGameOver();

	void addScore(int score);
	string getScore();
	string sResetScore();
	int nResetScore();

	void convertIntToString(int score);

	void clearScreen(Color* color);
	void highScore();

	GraphicsBuffer* getGraphicsBuffer() { return mpGraphicsBuffer; };
	Font* getFont() { return mpFont; };
	Sprite* getSprite() { return mpSprite; };
	Color* getBlack() { return mpColorBlack; };
	Color* getWhite() { return mpColorWhite; };
};