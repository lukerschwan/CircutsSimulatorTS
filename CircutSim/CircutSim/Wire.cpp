#include "Wire.h"
#include "stdafx.h"



Wire::Wire(string n, char v, int i, string h, Gate * d, string type )
{
	name = n;
	val = v;
	history = h;
	index = i;
	//max fanout will be 20 this is okay becuase normal circuits can only drive like 5
	drive.push_back(d);
	if (type == "INPUT"){
		isOutputBool = false;
}
else {
	isOutputBool = true;
}
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

vector<Gate*> Wire::getDrive() const
{
	return drive;
}

bool Wire::isOutput() const
{
	return isOutputBool;
}

void Wire::setVal(const char & v)
{
	history = val;
	val = v;
}

void Wire::setDrive(Gate * d)
{
	drive.push_back(d);
}

void Wire::correctDrive()
{
	drive.pop_back();
	drive.pop_back();
}

