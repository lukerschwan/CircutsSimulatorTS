// CircutSim.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<fstream>
#include<queue>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "stdafx.h"
#include "Wire.h"
#include "Gate.h"
#include "Event.h"
using namespace std;

int ParseGate();
void ParseVector(priority_queue<Event> &q, vector<Wire*> &w);
void Simulate();
void Print();
int main()
{
	//Step 1: parse Gate file
	vector<Wire*> wirePtrs;
	
	//Step 2: parse vector file
	int errorValue = ParseGate();
	priority_queue<Event> eventQueue;
	ParseVector(eventQueue, wirePtrs);
	//Step 3: simulation

	//Step 4: Print


	return 0;
}

int ParseGate()
{
	
	string fileName = "";
	cout << "What is your file name?";
	cin >> fileName;
	ifstream in;
	in.open(fileName);
	string junk;
	string fileType;
	in >> fileType;
	in >> junk;
	if (fileType == "CIRCUIT" && in.is_open()) {
		// open the file
		// get the 



	}


	else {
		cerr << "Wrong type of file, exiting.";
		return 1;
	}
	

}

void ParseVector(priority_queue<Event> &q, vector<Wire*> &w)
{
	char filename[50]; // not sure if file is passed as com line arg...
	string temp;
	string fileType;
	string wireName;
	int time;
	int wireVal;
	int iterate;
	ifstream vectorFile;
	vectorFile.open(filename);
	cin >> fileType >> temp;
	if (fileType != "VECTOR") { // file verification
		cerr << "Wrong file input" << endl;
	}
	while (!vectorFile.eof()) {
		cin >> temp >> wireName >>  time >> wireVal;
		for (int i = 0; i < w.size(); ++i) {
			if (w.at(i)->getName() == wireName) {
				//FIXME: dynamically create events for the queue
				q.push();
			}
			else {
				cerr << "Vector parsing failed" << endl;
			}
		}
	}
	vectorFile.close();
}

void Simulate()
{
}

void Print()
{
}
