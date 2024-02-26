#pragma once

#include <string>
#include <trackable.h>
#include <Event.h>

using namespace std;

enum GameEventType
{
	MOVE_EVENT= NUM_BASE_EVENT_TYPES,
	MESSAGE_EVENT,
	NUM_GAME_EVENT_TYPES
};

class GameEvent:public Event
{
public:
	GameEvent( GameEventType type );
	virtual ~GameEvent();

private:

};