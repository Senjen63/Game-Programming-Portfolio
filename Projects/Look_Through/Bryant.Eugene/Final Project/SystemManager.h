/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Vector2D.h>
#include "Trackable.h"
#include <vector>

using namespace std;

class HUD;
class InputSystem;
class SoundSystem;
class Color;
class EnemyManager;
class PlayerManager;

class SystemManager : public Trackable
{
private:
	HUD* mpHUD;
	InputSystem* mpiSystem;
	SoundSystem* mpsSystem;
	Color* mpColor;

	PlayerManager* mpLoadPlayer;
	EnemyManager* mpLoadEnemy;

	/******Game Speed*****/
	float mDT = 120;
	string msDT;
	/*********************/

	string mTemp; // skips any blank lines that is on the file

	float mOn = 1; // On/Off switch

	/**********Game's save file and Score file********/
	ifstream mLoadScore;
	ifstream mLoadFile;
	/*************************************************/

	/**********Game's save file and Score file********/
	ofstream mSaveFile;
	ofstream mSaveScore;
	/*************************************************/

	/**************Score***************/
	string mLoadScoreS;
	int mLoadScoreN;
	/**********************************/

	/*********************Player's position***************/
	float mPlayerX;
	string msPlayerX;
	float mPlayerY;
	string msPlayerY;
	/*****************************************************/

	/*************Enemy's position************************/
	float mEnemyX;
	string msEnemyX;
	float mEnemyY;
	string msEnemyY;
	/*****************************************************/

public:
	SystemManager();
	~SystemManager();

	void init();

	void options(HUD* hud);

	void sound(HUD* hud);

	float onOff(float on);

	void saveGame(PlayerManager* player, EnemyManager* enemy, float delta); 

	void saveScore(HUD* hud);

	void loadGame(PlayerManager* player, EnemyManager* enemy);

	int loadScore(int score);

	bool quit(bool endgame);

	float speed(HUD* hud);

	float getSpeed(float delta);

	int convertStringToInt(string str);

	string convertFloatToString(float num);

	float convertStringToFloat(string str);

	float speedUp(float time);

	bool proceed(bool isFinish);

	HUD* getHUD() { return mpHUD; };
	InputSystem* getInput() { return mpiSystem; };
	SoundSystem* getSoundSystem() { return mpsSystem; };
	Color* getColor() { return mpColor; };
	PlayerManager* getPlayerManager() { return mpLoadPlayer; };
	EnemyManager* getEnemyManager() { return mpLoadEnemy; };
};