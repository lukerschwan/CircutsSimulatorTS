#pragma once
#include "Wire.h"
using namespace std;
class Event{
	//added event class  x

public:
	void getEventWire();


private:

	Wire * eventWire;
	int time;
	int val;
	int creationCnt;
};