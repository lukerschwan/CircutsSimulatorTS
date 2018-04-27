#include "Event.h"
#include "stdafx.h"


Event::Event(Wire * w, int t, char v, int c)
{
	eventWire =w;
	time = t;
	val = v;
	creationCnt = c;
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
	if (val == e1.val && time == e1.time && eventWire == e1.eventWire) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Event & e1, const Event & e2)
{
	if (e1.time == e2.time) {
		return (e1.creationCnt > e2.creationCnt);
	}
	return e1.time > e2.time; //return the opposite because greater in priority queue doesnt work
}
