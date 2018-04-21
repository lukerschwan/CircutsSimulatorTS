#include "Wire.h"
#include "stdafx.h"



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

int Wire::getHistory() const
{
	return history;
}

vector<Gate*> Wire::getDrive(int gateIndex) const
{
	return drive;
}

void Wire::setDrive(Gate * d)
{
	//drive.insert(d);
}
