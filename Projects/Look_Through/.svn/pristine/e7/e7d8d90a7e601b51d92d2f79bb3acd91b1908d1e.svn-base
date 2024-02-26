#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

// most is the base from deanlib

#include <string>
#include "Trackable.h"

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	NUM_BASE_EVENT_TYPES,
	ADD_SCORE_EVENT,
	MOVE_SNAKE_EVENT,
	TRANSITION_EVENT,
	INCREASE_BODY_EVENT,
	COLLISION_EVENT,
	LEVEL_CHANGE_EVENT,
	INPUT_EVENT
};

class Event :public Trackable
{
public:
	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; };

private:
	EventType mType;
};

class AddScoreEvent : public Event
{
private:
	
	

public:
	AddScoreEvent() :Event(ADD_SCORE_EVENT) {};
	~AddScoreEvent() {};
};

class MoveSnakeEvent : public Event
{
private:

public:
	MoveSnakeEvent() :Event(MOVE_SNAKE_EVENT) {};
	~MoveSnakeEvent() {};
};

class TransitionEvent : public Event
{
private:

public:
	TransitionEvent() :Event(TRANSITION_EVENT) {};
	~TransitionEvent() {};
};

class IncreaseBodyEvent : public Event
{
private:

public:
	IncreaseBodyEvent() :Event(INCREASE_BODY_EVENT) {};
	~IncreaseBodyEvent() {};
};

class CollisionEvent : public Event
{
private:

public:
	CollisionEvent() :Event(COLLISION_EVENT) {};
	~CollisionEvent() {};
};