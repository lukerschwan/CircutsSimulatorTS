#pragma once
#include "stdafx.h"
#include<string>
#include<vector>
#include"Gate.h"

using namespace std;
class Gate; //foreward declaration
class Wire {
public:
	//wire default constructor
	Wire(string n = "", char v = 'X', int i = 0, string h = "", Gate * d = nullptr);
	static int drivingNumber;

	//wire getters 
	string getName() const;
	char getVal() const;
	int getIndex() const;
	string getHistory() const;
	vector<Gate*> getDrive() const;

	//wire setters
	void setVal(const char &v);
	void setDrive(Gate* d);
	void correctDrive();
private:
	

	string name;
	char val;
	int index;
	string history;
	vector<Gate*> drive;
};