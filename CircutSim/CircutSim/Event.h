#pragma once
#include "stdafx.h"
#include "Wire.h"

using namespace std;
class Wire; //forward declaration
class Event{
	//added event class
public:
	Event(Wire *w = nullptr, int t = 0, char v = 'X' , int c = 0);

	void setEventWire(Wire *w);
	void setTime(int &t);
	void setVal(char &v);
	void setCreationCnt(int &c);
	Wire *getEventWire() const;
	int getTime() const;
	char getVal() const;
	int getCreationCnt() const;
	bool operator ==(const Event& e1)const;
	friend bool operator<(const Event& e1, const Event& e2); //Reversed because greater parameter does not work for the priority queue
	//Event& operator=(const Event& e1);

private:

	Wire * eventWire;
	int time;
	char val;
	int creationCnt;
};
