#pragma once
#include "Wire.h"
using namespace std;
class Event{
	//added event class
public:
	Event(Wire *w = nullptr, int t = 0, int v = 0, int c = 0);
	void setEventWire(Wire *w);
	void setTime(int t);
	void setVal(int v);
	void setCreationCnt(int c);
	Wire *getEventWire(int index) const;
	int getTime() const;
	int getVal() const;
	int getCreationCnt() const;

private:

	vector<Wire *> eventWire;
	int time;
	int val;
	int creationCnt;
};