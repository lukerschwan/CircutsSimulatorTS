#include "Gate.h"
#include "stdafx.h"

Gate::Gate(Wire* in1New, Wire* in2New, Wire* outNew, string typeNew, int delayNew)
{
	in1 = in1New;
	in2 = in2New;
	outWire = outNew;
	type = typeNew;
	delay = delayNew; 
}

Wire * Gate::getIn1() const
{
	return in1;
}

Wire * Gate::getIn2() const
{
	return in2;
}

Wire * Gate::getOutWire() const
{
	return outWire;
}

string Gate::getType() const
{
	return type;
}

int Gate::getDelay() const
{
	return delay;
}

