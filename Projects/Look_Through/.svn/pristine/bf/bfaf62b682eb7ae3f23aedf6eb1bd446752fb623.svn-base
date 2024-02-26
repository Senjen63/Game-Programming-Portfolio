#pragma once

#include <iostream>
#include <Vector2D.h>
#include <vector>
#include "Trackable.h"

using namespace std;

class UnitManager;
class Unit;
class Sprite;
class GraphicsBufferManager;
class GraphicsBuffer;
class Animation;
class InputSystem;
class PowerUpManager;
class LevelManager;

//const string SNAKE_HEAD_FILENAME = "SnakeHead.png";
//const string SNAKE_BODY_FILENAME = "SnakeBody.png";

class SnakeManager : public Trackable
{
private:

	Unit* mpuSnakeHead;
	vector <Unit*> mpuSnakeBody;
	LevelManager* mpLevel;

	Sprite* mpSprite;
	GraphicsBufferManager* mpGraphicsBufferManager;
	GraphicsBuffer* mpGraphicsBuffer;
	Animation* mpAnimation;
	InputSystem* mpInput;
	PowerUpManager* mpPowerU;
	PowerUpManager* mpPowerD;

	Vector2D directionh = Vector2D(1, 0);

	float mtimeL;
	float mTime;

	int bodyParts;
	int mStartBodyParts;

public:
	SnakeManager();
	~SnakeManager();

	void init();
	void update();
	void movement();
	void addBodypart();
	void rest();
	void reset();
	void clear();

	Vector2D direction();

	Unit* getHead() { return mpuSnakeHead; };
	Unit* getBody(int list);
	vector <Unit*> getBodyVector();
	Sprite* getSprite() { return mpSprite; };
	GraphicsBufferManager* getGraphicsBufferManager() { return mpGraphicsBufferManager; };
	GraphicsBuffer* getGraphicsBuffer() { return mpGraphicsBuffer; };
	Animation* getAnimation() { return mpAnimation; };
};