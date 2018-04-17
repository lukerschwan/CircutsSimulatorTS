#pragma once
#include "Wire.h"
using namespace std;
class Event{
	//added event class
public:
	void setEventWire(Wire &w);
	void setTime(int t);
	void setVal(int v);
	void setCreationCnt(int c);
	Wire *getEventWire() const;
	int getTime() const;
	int getVal() const;
	int getCreationCnt() const;

private:

	Wire * eventWire;
	int time;
	int val;
	int creationCnt;
};