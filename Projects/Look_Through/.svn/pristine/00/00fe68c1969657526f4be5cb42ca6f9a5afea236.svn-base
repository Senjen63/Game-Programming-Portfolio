/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "EventListeners.h"
#include "EventSystems.h"
#include "Events.h"

// most is the base from deanlib

EventListener::EventListener()
{
	EventSystem* mpEventSystem = EventSystem::getInstance();
	mpEventSystem->addListener(ADD_SCORE_EVENT, this);
}

EventListener::~EventListener()
{
	EventSystem::getInstance()->removeListenerFromAllEvents(this);
}

void EventListener::handleEvent(const Event& theEvent)
{
	cout << "Handle, Event, Called" << endl;
	switch (theEvent.getType())
	{
		case ADD_SCORE_EVENT:
		{
			cout << "case, add score" << endl;
			addScoreEvent();
			break;
		}

		case MOVE_SNAKE_EVENT:
		{
			cout << "" << endl;
			moveSnakeEvent();
			break;
		}

		case TRANSITION_EVENT:
		{
			cout << "" << endl;
			transitionEvent();
			break;
		}

		case INCREASE_BODY_EVENT:
		{
			cout << "" << endl;
			increaseBodyEvent();
			break;
		}
		
	}
}

void EventListener::addScoreEvent()
{
	cout << "Score, Event, Handle" << endl;
}

void EventListener::moveSnakeEvent()
{
	cout << "Move Snake, Event, Handle" << endl;
}

void EventListener::transitionEvent()
{
	cout << "Transition, Event, Handle" << endl;
}

void EventListener::increaseBodyEvent()
{
	cout << "Increase Body, Event, Handle" << endl;
}

void EventListener::collisionEvent()
{
	cout << "Collision, Event, Handle" << endl;
}