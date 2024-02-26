#pragma once

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