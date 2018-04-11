#pragma once
#include<string>
#include<vector>
using namespace std;
class Gate; //foreward declaration
class Wire {
public:
	//wire default constructor
	Wire(string n = "", char v = 'X';, int i = 0, int h = 0, Gate* d = nullptr);


	//wire getters 
	string getName() const;
	char getVal() const;
	int getIndex() const;
	int getHistory() const;
	Gate *getDrive(int gateIndex) const;

	//wire setters
	void setName(string n);
	void setVal(char v);
	void setIndex(int i);
	void setDrive(Gate* d);

private:
	void setHistory(int h); //I think this should be private since it will only be accessed by member functions

	string name;
	char val;
	int index;
	int history;
	vector<gate*> Drive;
};