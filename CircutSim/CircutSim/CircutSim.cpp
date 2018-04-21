// CircutSim.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<fstream>
#include<queue>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include "stdafx.h"
#include "Wire.h"
#include "Gate.h"
#include "Event.h"
using namespace std;

int ParseGate( vector<Wire*> wirePtrs);
int ParseVector(priority_queue<Event> &q, vector<Wire*> &w);
void Simulate();
void Print();
int main()
{
	//Step 1: parse Gate file
	vector<Wire*> wirePtrs;
	
	//Step 2: parse vector file
	int errorValueGate = ParseGate(wirePtrs);
	priority_queue<Event, vector<Event>, greater<Event> > eventQueue;

	int errorValue = ParseVector(eventQueue, wirePtrs);
	//Step 3: simulation

	//Step 4: Print


	return 0;
}

int ParseGate( vector<Wire*> wirePtrs)
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
		while (!in.eof()) {
			//this will figure out if the gate is an input or an output
			string type;
			in >> type;
			//this will tell what thename of the wire is. this is pretty much used mostly in the output
			string wireName = "";
			in >> wireName;
			//this will store the vector lookup location of the wire within the vector
			int wireVectorIndex = -1;
			in >> wireVectorIndex;

			if (type == "INPUT") {
				Wire temp(wireName, 'X', wireVectorIndex, 0);
			}


		}
		// open the file
		// get the 
		//creat a wire



	}


	else {
		cerr << "Wrong type of file, exiting.";
		return 1;
	}
	

}

int ParseVector(priority_queue<Event> &q, vector<Wire*> &w)
{
	string filename; // can we use strings for the .open()
	cout << "Please enter Vector file name" << endl;
	cin >> filename;
	string temp;
	string fileType;
	string wireName;
	int time;
	int wireVal;
	int iterate;
	int cc = 0;
	ifstream vectorFile;
	vectorFile.open(filename);
	if (!vectorFile.is_open()) {
		cerr << "File failed to open";
		return 1;
	}
	cin >> fileType >> temp;
	if (fileType != "VECTOR") { // file verification
		cerr << "Wrong file type input" << endl;
		return 1;
	}
	while (!vectorFile.eof()) {
		cin >> temp >> wireName >>  time >> wireVal;
		for (int i = 0; i < w.size(); ++i) {
			if (w.at(i)->getName() == wireName) {
				q.emplace(w.at(i), time, wireVal,cc);
				cc++;
				break;
			}
		}
	}
	vectorFile.close();
	return 0;
}

void Simulate()
{
}

void Print()
{
}
