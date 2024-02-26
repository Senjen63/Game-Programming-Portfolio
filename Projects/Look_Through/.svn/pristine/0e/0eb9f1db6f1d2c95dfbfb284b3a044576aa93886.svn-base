#pragma once

/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

// most is the base from deanlib

#include "Trackable.h"
#include "Events.h"

class Event;
class EventSystem;

class EventListener :public Trackable
{
public:
	EventListener();
	virtual ~EventListener();

	void handleEvent(const Event& theEvent);

	void addScoreEvent();
	void moveSnakeEvent();
	void transitionEvent();
	void increaseBodyEvent();
	void collisionEvent();
private:
	
};