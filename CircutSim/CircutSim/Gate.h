#pragma once
#include "stdafx.h"
#include <string>
#include "Wire.h"
using namespace std;

class Wire; //foreward declaration
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
	Gate(Wire* in1 =nullptr, Wire* in2 = nullptr, Wire* out = nullptr, int type = 0, int delay = 0);


	//TODO write the get gate result function
	// gateEvent getGateResult(Wire*in1, Wire *in2, , int type, int delay);



	//consted getters
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