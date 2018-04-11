#pragma once
#include "stdafx.h"
#include "Wire.h"
#include <string>
using namespace std;
#define AND =1111;
#define OR = 2222;
#define NOT = 3333;
#define NAND = 4444;
#define NOT = 5555;
#define XOR = 6666;
#define XNOR =7777;
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
	int	   getType() const;
	int	   getDelay() const;
	//setters
	void   setIn1(Wire * inPtr);
	void   setIn2(Wire * inPtr);
	void   setoutWire(Wire * inPtr);
	void   setType(int inType);
	void   setDelay(int inDelay);



protected:
	

private:
	//pointer to wire inputs
	Wire * in1;
	Wire * in2;
	//pointer to the gate output
	Wire * outWire;
	//string to what type of gate it is
	int type; 
	int delay;

};