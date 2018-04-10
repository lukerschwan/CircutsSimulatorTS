#include "Gate.h"

Gate::Gate(Wire * in1, Wire * in2, Wire * out, int type, int delay)
{
}

Wire * Gate::getIn1() const
{
	return nullptr;
}

Wire * Gate::getIn2() const
{
	return nullptr;
}

Wire * Gate::getOutWire() const
{
	return nullptr;
}

int Gate::getType() const
{
	return 0;
}

int Gate::getDelay() const
{
	return 0;
}

void Gate::setIn1(Wire * inPtr)
{
}

void Gate::setIn2(Wire * inPtr)
{
}

void Gate::setoutWire(Wire * inPtr)
{
}

void Gate::setType(int inType)
{
}

void Gate::setDelay(int inDelay)
{
}
