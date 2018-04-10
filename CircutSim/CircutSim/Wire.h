#pragma once
#include<string>
using namespace std;
class Wire {
public:
	//wire default constructor
	Wire(string n = "", char v = 'X';, int i = 0, int h = 0);


	//wire getters 
	string getName() const;
	char getVal() const;
	int getIndex() const;
	int getHistory() const;

	//wire setters
	void setName(string n);
	void setVal(char v);
	void setIndex(int i);

private:
	void setHistory(int h); //I think this should be private since it will only be accessed by member functions

	string name;
	char val;
	int index;
	int history;
};