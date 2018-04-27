#include "Gate.h"
#include "stdafx.h"
#include "Event.h"
#include<queue>

Gate::Gate(Wire* in1New, Wire* in2New, Wire* outNew, string typeNew, int delayNew)
{
	in1 = in1New;
	in2 = in2New;
	outWire = outNew;
	type = typeNew;
	delay = delayNew; 
}

 void Gate::gateResult(priority_queue<Event> &q, int &cc)
{
char v;
	if (type == "AND") {

		if (in1->getVal() == '0' || in2->getVal() == '0') {
			v = '0';
		}
		else if (in1->getVal() == '1' && in2->getVal() == '1') {
			v = '1';
		}
		else {
			v = 'X';
		}
	}
	if (type == "NAND") {
		if (in1->getVal() == '0' || in2->getVal() == '0') {
			v = '1';
		}
		else if (in1->getVal() == '1' && in2->getVal() == '1') {
			v = '0';
		}
		else {
			v = 'X';
		}
	}
	if (type == "OR") {
		if (in1->getVal() == '0' && in2->getVal() == '0') {
			v = '0';
		}
		else if (in1->getVal() == '1' || in2->getVal() == '1') {
			v = '1';
		}
		else {
			v = 'X';
		}
	}
	if (type == "NOR") {
		if (in1->getVal() == '0' && in2->getVal() == '0') {
			v = '1';
		}
		else if (in1->getVal() == '1' || in2->getVal() == '1') {
			v = '0';
		}
		else {
			v = 'X';
		}
	}
	if (type == "XOR") {
		if (in1->getVal() ==  in2->getVal() && in1->getVal() != 'X') {
			v = '0';
		}
		else if (in1->getVal() != in2->getVal() && in1->getVal() != 'X') {
			v = '1';
		}
		else {
			v = 'X';
		}
	}
	if (type == "XNOR") {
		if (in1->getVal() == in2->getVal() && in1->getVal() != 'X') {
			v = '1';
		}
		else if (in1->getVal() != in2->getVal() && in1->getVal() != 'X') {
			v = '0';
		}
		else {
			v = 'X';
		}
	}
	if (type == "NOT") {
		if (in1->getVal() == '0') {
			v = '1';
		}
		else if (in1->getVal() == '1') {
			v = '0';
		}
		else {
			v = 'X';
		}
	}
	q.emplace(outWire, q.top().getTime() + delay, v, cc);
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

