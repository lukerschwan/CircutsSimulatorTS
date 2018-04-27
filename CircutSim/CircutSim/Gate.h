#pragma once
#include "stdafx.h"
#include <string>
//#include "Wire.h"
#include "Event.h"
using namespace std;

//class Wire; //foreward declaration
class Gate {
	/*
In1 
Int2
Out
Type
Delay
	*/
public:
	//default constructor
	Gate(Wire* in1New  =nullptr, Wire* in2New = nullptr, Wire* outNew = nullptr, string typeNew = "", int delayNew = 0);

	void gateResult(priority_queue<Event> &q, int &cc);
	Wire * getIn1() const;
	Wire * getIn2() const;
	Wire * getOutWire() const;
	string	   getType() const;
	int	   getDelay() const;


protected:
	

private:
	//pointer to wire inputs
	Wire * in1;
	Wire * in2;
	//pointer to the gate output
	Wire * outWire;
	//string to what type of gate it is
	string type; 
	int delay;

};