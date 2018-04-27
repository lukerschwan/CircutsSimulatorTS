#pragma once
#include<string>
using namespace std;

class WirePrint {
public:
	WirePrint(string n = "", string f = "X");
	void setWireName(string n);
	void setWaveForm(char f);
	void pushWaveForm(char f);
	string getWireName() const;
	string getWaveForm() const;
private:
	string wireName;
	string waveForm;
};