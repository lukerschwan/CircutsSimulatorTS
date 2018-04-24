// CircutSim.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<fstream>
#include<queue>
#include<fstream>
#include<cstdlib>
#include<vector>
#include <ctype.h>
#include<string>
#include "stdafx.h"
#include "Wire.h"
#include "Gate.h"
#include "Event.h"
using namespace std;

int ParseGate( vector<Wire*> wirePtrs, vector<Gate*> gatePtrs);
int ParseVector(priority_queue<Event> &q, vector<Wire*> &w);
int Simulate(priority_queue<Event> &q, vector<Wire*> &w, vector<Gate*> &g);
int Print();
int main()

{
	//Step 1: parse Gate file
	vector<Wire*> wirePtrs;
	vector<Gate*> gatePtrs;
	//Step 2: parse vector file 
	int errorValueGate = ParseGate(wirePtrs,gatePtrs); //returning 1 is error
	priority_queue<Event> eventQueue;

   int errorValueVector = ParseVector(eventQueue, wirePtrs); //returning 1 is error
	//Step 3: simulation 
	int errorValueSimulate = Simulate(eventQueue, wirePtrs, gatePtrs);
	//Step 4: Print


	return 0;
}

int ParseGate( vector<Wire*> wirePtrs, vector<Gate*> gatePtrs)
{
	int gateSize = 2;
	bool previousNot =false; 
	bool firstRun = true;
	string strIn3 = "";
	string name;
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
			
			string type;
			in >> type;

			while (type=="INPUT" || type=="OUTPUT") {
				//TODO add somethign to make sure that inputs and outputs are differentianted

				//this will figure out if the gate is an input or an output
				
				//this will tell what thename of the wire is. this is pretty much used mostly in the output
				string wireName = "";
				in >> wireName;
				//this will store the vector lookup location of the wire within the vector
				int wireVectorIndex = -1;
				in >> wireVectorIndex;
				//type checking if needed at the end
				//creat the wire
					Wire *temp= new Wire(wireName, 'X', wireVectorIndex, "", nullptr);
					if (wireVectorIndex >= wirePtrs.size()) {
						wirePtrs.resize(wireVectorIndex + 1);
					}
					//cout << endl << wireName<< "added a wire at" << wireVectorIndex;
					wirePtrs.at(wireVectorIndex) = temp;
				
				in >> type;
				name = type;
			}
			//anything below here is parsing gates
			gateSize++;
			gatePtrs.resize(gateSize);
			if (previousNot) {
				name = strIn3;
				previousNot = false;
			}
			else if (firstRun) {
				firstRun = false;
			}
			else {
				in >> name;
			}
			int delay;
			in >> delay;
			string junk;
			in >> junk;
			int in1;
			in >> in1;
			int in2;
			in >> in2;
			in >> strIn3;
			int intIn3;
			string wireType;
			//everything but not gates 
			if (name!="NOT") {
				intIn3 = stoi(strIn3);
				Gate* tempGate = new Gate(wirePtrs.at(in1), wirePtrs.at(in2), wirePtrs.at(intIn3), name, delay);
				gatePtrs.push_back(tempGate);
			}
			else {
				previousNot = true; 
				//set up not gate attributes 
				//this is a not gate so in2 is a nullptr
				Gate* tempGate = new Gate(wirePtrs.at(in1), nullptr,wirePtrs.at(in2), name, delay );
				name = strIn3; 
				gatePtrs.push_back(tempGate);
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
	
	return 0;
}



int ParseVector(priority_queue<Event> &q, vector<Wire*> &w)
{
	string filename; // can we use strings for the .open()
	cout << "Please enter Vector file name" << endl;
	cin >> filename;
	string temp;
	string fileType;
	string wireName;
	char wireVal;
	int time;
	int cc = 0;
	ifstream vectorFile;
	vectorFile.open(filename);
	if (!vectorFile.is_open()) {
		cerr << "File failed to open";
		return 1;
	}
	vectorFile >> fileType >> temp;
	if (fileType != "VECTOR") { // file verification
		cerr << "Wrong file type input" << endl;
		return 1;
	}
	while (!vectorFile.eof()) {
		vectorFile >> temp >> wireName >>  time >> wireVal;
		for (int i = 0; i < w.size(); ++i) {
			if (w.at(i)->getName() == wireName) {
				q.emplace(w.at(i), time, wireVal, cc);
				cc++;
				break;

			}
		}
	}
	vectorFile.close();
	return 0;
}

int Simulate(priority_queue<Event>& q, vector<Wire*>& w, vector<Gate*>& g)
{
	int currTime = 0;
	for (int i = 0; i < q.size(); i++) {
		q.pop();
	}
	return 0;
}


int Print()
{
	return 0;
}
