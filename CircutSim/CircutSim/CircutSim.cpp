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
#include "WirePrint.h"
using namespace std;

int cc;

int ParseGate(vector<Wire*> & wirePtrs, vector<Gate*> & gatePtrs);
int ParseVector(priority_queue<Event> &q, priority_queue<Event> &pq, vector<Wire*> &w);
void Simulate(priority_queue<Event> &q, priority_queue<Event> &pq);
int NameToIndex(vector<Wire*> &w, string n);
void Print(priority_queue<Event> &pq);
int main()

{

	//Step 1: parse Gate file
	vector<Wire*> wirePtrs;
	vector<Gate*> gatePtrs;
	//Step 2: parse vector file 
	int errorValueGate = ParseGate(wirePtrs, gatePtrs); //returning 1 is error
	if (errorValueGate == 1) {
		cout << "Error, exiting program";
		return 0;
	}
	priority_queue<Event> eventQueue;
	priority_queue<Event> printQueue;
	cc = 0;
	int errorValueVector = ParseVector(eventQueue, printQueue, wirePtrs); //returning 1 is error
															  //Step 3: simulation 
	if (errorValueVector == 1) {
		cout << "Error, exiting program";
		return 0;
	}
	Simulate(eventQueue, printQueue);
	//Step 4: Print
	Print(printQueue);

	return 0;
}

int ParseGate(vector<Wire*> & wirePtrs, vector<Gate*> & gatePtrs)
{
	int previousSize =0;
	int wireVectorIndex = -1;
	Wire* nullWire = new Wire("NULL", 'X', wireVectorIndex, "", nullptr);
	int gateSize = 0;
	int intIn3;
	bool previousNot = false;
	bool firstRun = true;
	string strIn3 = "";
	string name;
	string fileName;
	cout << "What is your file name?";
	cin >> fileName;
	ifstream in;
	in.open(fileName);
	string junk;
	string fileType;
	in >> fileType;
	in >> junk;

	string type;
	in >> type;

	if (fileType == "CIRCUIT" && in.is_open()) {

		while(!in.eof()){

			while (type == "INPUT" || type == "OUTPUT") {
	
				//TODO add somethign to make sure that inputs and outputs are differentianted

				//this will figure out if the gate is an input or an output

				//this will tell what thename of the wire is. this is pretty much used mostly in the output
				string wireName = "";
				in >> wireName;
				//this will store the vector lookup location of the wire within the vector
				
				in >> wireVectorIndex;
				//type checking if needed at the end
				//creat the wire
				Wire *temp = new Wire(wireName, 'X', wireVectorIndex, "", nullptr, type);
				if (wireVectorIndex >= wirePtrs.size()) {
					//add one 
					
					

					wirePtrs.resize(wireVectorIndex+1);
					while (previousSize != wirePtrs.size()) {
						wirePtrs.at(previousSize) = nullWire;
						previousSize++;
					}
					//Wire* nullWire = new Wire("NULL", 'X', wireVectorIndex, "", nullptr);
					//add 2
					wirePtrs.at(wireVectorIndex) = nullWire;

				}
				//cout << endl << wireName<< "added a wire at" << wireVectorIndex;
				wirePtrs.at(wireVectorIndex) = temp;

				in >> type;
				name = type;
			}



			//anything below here is parsing gates
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

			string wireType;
			//everything but not gates 
			if (name != "NOT") {
				int intIn3 = stoi(strIn3);
				
				gatePtrs.resize(gateSize);
			
				

				//set up wire 1
				if (wirePtrs.at(in1)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in1, "", nullptr);
					wirePtrs.at(in1) = tempWire;
					//possibly delete
				}
				//set up internal wire on 2
				if (wirePtrs.at(in2)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in2, "", nullptr);
					wirePtrs.at(in2) = tempWire;
					//wirePtrs.at(in2)->setDrive(tempGate);
				}

				if (wirePtrs.at(intIn3)->getName()== "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', intIn3, "", nullptr);
					wirePtrs.at(intIn3) = tempWire;
				}
				Gate* tempGate = new Gate(wirePtrs.at(in1), wirePtrs.at(in2), wirePtrs.at(intIn3), name, delay);
				wirePtrs.at(in1)->setDrive(tempGate);
				wirePtrs.at(in2)->setDrive(tempGate);
				gatePtrs.push_back(tempGate);
				gateSize++;
			}
			else {
				name = "NOT";
				
				gateSize++;
				int intIn3 = 0;
				previousNot = true;
				//set up not gate attributes 
				//this is a not gate so in2 is a nullptr
				//have the wires point to this gate
				//set up internal wire on 1
				if (wirePtrs.at(in1)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in1, "", nullptr);
					wirePtrs.at(in1) = tempWire;
				}
				//set up internal wire on 2
				if (wirePtrs.at(in2)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in2, "", nullptr);
					wirePtrs.at(in2) = tempWire;
				}
				Gate* tempGate = new Gate(wirePtrs.at(in1), nullptr, wirePtrs.at(in2), name, delay);
				gatePtrs.push_back(tempGate);
				gatePtrs.resize(gateSize);
				wirePtrs.at(in1)->setDrive(tempGate);
				
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
	//for some reason the last gate is read twice,
	//rather than reworking the structure with diffrent EOF checking I will just pop them off
	gatePtrs.pop_back();

	//wirePtrs.at()popDriveBack(); 
	in.close();
	return 0;
}



int ParseVector(priority_queue<Event> &q, priority_queue<Event> &pq, vector<Wire*> &w)
{
	string filename; // can we use strings for the .open()
	cout << "Please enter Vector file name" << endl;
	cin >> filename;
	string temp;
	string fileType;
	string wireName;
	char wireVal;
	int time;
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
	while (vectorFile >> temp) {
		vectorFile >> wireName >> time >> wireVal;
		q.emplace(w.at(NameToIndex(w, wireName)), time, wireVal, cc);
		pq.emplace(w.at(NameToIndex(w, wireName)), time, wireVal, cc);
		cc++;
	}
	vectorFile.close();

	return 0;
}

void Simulate(priority_queue<Event>& q, priority_queue<Event> &pq)
{
	while (!q.empty() && cc < 200) {
		q.top().getEventWire()->setVal(q.top().getVal()); //set the wire to the event value
			if (!q.top().getEventWire()->isOutput()) { //not an output
				for (int i = 1; i < q.top().getEventWire()->getDrive().size(); i++) { //for each of the gates in the fanout (Drive)
					q.top().getEventWire()->getDrive().at(i)->gateResult(q, cc); //do the logic
					cc++;
				}
			}
			else {
				pq.push(q.top());
				cc++;
			}
			q.pop(); // pop of first element
	}
}



int NameToIndex(vector<Wire*> &w, string n)
{
	int i = 1;
	while (n != w.at(i)->getName()) {
		i++;
	}
	return i;
}

void Print(priority_queue<Event>& pq)
{

	bool exists = false;
	vector<WirePrint> printWires;
	while (!pq.empty()) {
		exists = false;
		int i = 0;
		for (i = 0; i < printWires.size(); i++) {
			if (pq.top().getEventWire()->getName() == printWires.at(i).getWireName()) {
				exists = true;
				break;
			}
			else {
				exists = false;
			}
		}
		if (!exists) {
			printWires.emplace(printWires.end(), pq.top().getEventWire()->getName());
		}
		while (printWires.at(i).getWaveForm().length() <= pq.top().getTime()) {
			printWires.at(i).pushWaveForm(printWires.at(i).getWaveForm().back()); //catch up
		}
		printWires.at(i).setWaveForm(pq.top().getVal());
		pq.pop();
}
	int maxLength = 0; // printWires.front().getWaveForm().length();
	for (int i = 0; i < printWires.size(); i++) {
		if (printWires.at(i).getWaveForm().length() > maxLength) {
			maxLength = printWires.at(i).getWaveForm().length();
		}
	}
	for (int i = 0; i < printWires.size(); i++) {
		while (printWires.at(i).getWaveForm().length() < maxLength) {
			printWires.at(i).pushWaveForm(printWires.at(i).getWaveForm().back()); //catch up
		}
	}

	for (int i = 0; i < printWires.size(); i++) {
		cout << printWires.at(i).getWireName() << ":  " << printWires.at(i).getWaveForm() << endl << endl;
	}
	}
