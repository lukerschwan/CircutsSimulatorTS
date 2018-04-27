#pragma once
#include<string>
using namespace std;

class WirePrint {
public:
	WirePrint(string n = "", string f = "");
	void setWireName(string n);
	void setWaveForm(char f);
	string getWireName() const;
	string getWaveForm() const;
private:
	string wireName;
	string waveForm;
};