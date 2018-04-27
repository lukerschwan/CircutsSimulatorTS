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

 void Gate::gateResult(priority_queue<Event> &q)
{
	static int cc = 100;
	if (type == "AND") {
		if (in1->getVal() == '0' || in2->getVal() == '0') {
			q.emplace(outWire, q.top().getTime(), '0' , cc);
		}
		else if (in1->getVal() == '1' && in2->getVal() == '1') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "NAND") {
		if (in1->getVal() == '0' || in2->getVal() == '0') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else if (in1->getVal() == '1' && in2->getVal() == '1') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "OR") {
		if (in1->getVal() == '0' && in2->getVal() == '0') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else if (in1->getVal() == '1' || in2->getVal() == '1') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "NOR") {
		if (in1->getVal() == '0' && in2->getVal() == '0') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else if (in1->getVal() == '1' || in2->getVal() == '1') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else {
			outWire->setVal('X');
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "XOR") {
		if (in1->getVal() ==  in2->getVal() && in1->getVal() != 'X') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else if (in1->getVal() != in2->getVal() && in1->getVal() != 'X') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "XNOR") {
		if (in1->getVal() == in2->getVal() && in1->getVal() != 'X') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else if (in1->getVal() != in2->getVal() && in1->getVal() != 'X') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	if (type == "NOT") {
		if (in1->getVal() == '0') {
			q.emplace(outWire, q.top().getTime(), '1', cc);
		}
		else if (in1->getVal() == '1') {
			q.emplace(outWire, q.top().getTime(), '0', cc);
		}
		else {
			q.emplace(outWire, q.top().getTime(), 'X', cc);
		}
	}
	cc++;
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

