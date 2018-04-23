#include "Wire.h"
#include "stdafx.h"



Wire::Wire(string n, char v, int i, string h, Gate * d)
{
	name = n;
	val = v;
	history = h;
	index = i;
}

string Wire::getName() const
{
	return name;
}

char Wire::getVal() const
{
	return val;
}

int Wire::getIndex() const
{
	return index;
}

string Wire::getHistory() const
{
	return history;
}

vector<Gate*> Wire::getDrive(int gateIndex) const
{
	return drive;
}

void Wire::setVal(char & v)
{
	val = v;
	for (int i = 0; i < time) {

	}
}

void Wire::setDrive(Gate * d)
{
	drive.push_back(d);
}
