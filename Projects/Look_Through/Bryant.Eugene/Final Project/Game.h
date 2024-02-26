/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <Vector2D.h>
#include <PerformanceTracker.h>
#include "Trackable.h"
#include "Sprite.h"
#include "UnitManager.h"
#include "Font.h"
#include "Color.h"
#include "EventListeners.h"
#include "EventSystems.h"
#include "Events.h"


using namespace std;

class GraphicsSystem;
class InputSystem;
class GraphicsBuffer;
class Sprite;
class Animation;
class Unit;
class Font;
class Color;
class HUD;
class LevelManager;
class SoundSystem;
class PlayerManager;
class EnemyManager;
class Blaster;
class SystemManager;
class UnitManager;

const string FONT_FILENAME = "cour.ttf";
const string PLAYER_FILENAME = "Player.png"; // credit to Far700 /*istockphoto*/
const string ENEMY_FILENAME = "Enemy.png"; // credit to Brodgro
const string BLASTER_FILE = "Color_Bullet.jpg"; // credit to RekaReka /*istockphoto*/


class Game : public Trackable
{
	friend class Unit;
private:
	GraphicsSystem* mpgsystem;
	InputSystem* mpisystem;
	GraphicsBuffer* mpbuffer;
	Animation* mpAnimate;
	SoundSystem* mpSoundSystem;

	GraphicsBuffer* mpPlayer;
	GraphicsBuffer* mpEnemy;
	GraphicsBuffer* mpBullet;

	Sprite* mpsPlayer;
	Sprite* mpsEnemy;

	Animation* mpaBullet;

	PlayerManager* mpPlayerManager;
	EnemyManager* mpEnemyManager;
	Blaster* mpBlaster;

	SystemManager* mpSystemManager;

	Vector2D mlocation = Vector2D(0, 0);

	Font* mpFont;
	Color* mpColorWhite;
	Color* mpColorBlack;

	HUD* mpHUD;

	static Game* mpsGame;

	float mRate = 60.0f;
	bool misAnimated;

	float deltaTime = 120.0f;

	Game(int width, int height);
	Game();
	~Game();

public:
	
	

	static Game* getInstance();
	static void createInstance();
	static void destroyInstance();

	void init();
	void cleanup();
	void doLoop();

	GraphicsSystem* getSystem() { return mpgsystem; };
	InputSystem* getInputSystem() { return mpisystem; };
	GraphicsBuffer* getGraphicsBuffer() { return mpbuffer; };
	PlayerManager* getPlayerManager() { return mpPlayerManager; };
	Sprite* getEnemySprite() { return mpsEnemy; };
	Sprite* getPlayerSprite() { return mpsPlayer; };
	Animation* getAnimation() { return mpAnimate; };
	Animation* getAnimatedBullet() { return mpaBullet; };
	Vector2D getLocation() { return mlocation; };
	Font* getFont() { return mpFont; };
	HUD* getHUD() { return mpHUD; };
	SoundSystem* getSoundSystem() { return mpSoundSystem; };
	Sprite* getSpriteEnemy() { return mpsEnemy; };
	EnemyManager* getEnemyManager() { return mpEnemyManager; };
	Blaster* getBlaster() { return mpBlaster; };
	SystemManager* getSystemManager() { return mpSystemManager; };
	Color* getWhite() { return mpColorWhite; };
	Color* getBlack() { return mpColorBlack; };
};
