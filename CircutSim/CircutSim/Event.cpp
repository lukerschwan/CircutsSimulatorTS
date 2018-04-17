#include "Event.h"

Event::Event(Wire & w, int t, int v, int c)
{
	eventWire = &w;
	time = t;
	val = v;
	creationCnt = c;
}

void Event::setEventWire(Wire & w)
{
	eventWire = &w;
}

void Event::setTime(int t)
{
	time = t;
}

void Event::setVal(int v)
{
	val = v;
}

void Event::setCreationCnt(int c)
{
	creationCnt = c;
}

Wire * Event::getEventWire() const
{
	return eventWire;
}

int Event::getTime() const
{
	return time;
}

int Event::getVal() const
{
	return val;
}

int Event::getCreationCnt() const
{
	return creationCnt;
}
