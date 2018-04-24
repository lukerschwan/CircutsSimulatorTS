#include "Event.h"
#include "stdafx.h"

Event::Event(Wire * w, int t, int v, int c)
{
	eventWire =w;
	time = t;
	val = v;
	creationCnt = c;
}

Event::Event(Event & e1)
{

	eventWire = e1.eventWire;
	time = e1.time;
	val = e1.val;
	creationCnt = e1.creationCnt;
}

void Event::setEventWire(Wire *w)
{
	eventWire = w;
}

void Event::setTime(int &t)
{
	time = t;
}

void Event::setVal(char &v)
{
	val = v;
}

void Event::setCreationCnt(int &c)
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

char Event::getVal() const
{
	return val;
}

int Event::getCreationCnt() const
{
	return creationCnt;
}

bool Event::operator==(const Event & e1) const
{
	return time == e1.time;
}


bool  operator<(const Event & e1, const Event & e2)
{
	if (e1 == e2) {
		return (e1.getCreationCnt() > e2.getCreationCnt());
	}
	return (e1.time > e2.time);
}


