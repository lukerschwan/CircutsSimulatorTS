#include "WirePrint.h"
#include "stdafx.h"
using namespace std;

WirePrint::WirePrint(string n, string f)
{
	wireName = n;
	waveForm = f;
}

void WirePrint::setWireName(string n)
{
	wireName = n;
}

void WirePrint::setWaveForm(char f)
{
	waveForm.back() = f;
}

void WirePrint::pushWaveForm(char f)
{
	waveForm.push_back(f);
}

string WirePrint::getWireName() const
{
	return wireName;
}

string WirePrint::getWaveForm() const
{
	return waveForm;
}
