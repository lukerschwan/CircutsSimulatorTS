#include "Event.h"

Event::Event(Wire * w = nullptr, int t = 0, int v = 0, int c = 0)
{
	eventWire.push_back(w);
	time = t;
	val = v;
	creationCnt = c;
}

void Event::setEventWire(Wire *w)
{
	eventWire.push_back(w);
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

Wire * Event::getEventWire(int index) const
{
	return eventWire.at(index);
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
