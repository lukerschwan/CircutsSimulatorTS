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

int ParseGate( vector<Wire*> & wirePtrs, vector<Gate*> & gatePtrs);
int ParseVector(priority_queue<Event> &q, vector<Wire*> &w);
int Simulate(priority_queue<Event> &q,priority_queue<Event> &pq);

int NameToIndex(vector<Wire*> &w, string n);
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
	priority_queue<Event> printQueue;
	int errorValueSimulate = Simulate(eventQueue, printQueue);
	//Step 4: Print


	return 0;
}

int ParseGate( vector<Wire*> & wirePtrs, vector<Gate*> & gatePtrs)
{
	int gateSize = 2;
	int intIn3;
	bool previousNot =false; 
	bool firstRun = true;
	string strIn3 = "";
	string name;
	string fileName = "circuit0.txt";
	//cout << "What is your file name?";
	//cin >> fileName;
	ifstream in;
	in.open(fileName);
	string junk;
	string fileType;
	in >> fileType;
	in >> junk;

	string type;
	in >> type;

	if (fileType == "CIRCUIT" && in.is_open()) {
		while (!in.eof()) {
			
			

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
						wirePtrs.resize(wireVectorIndex + 2);
						Wire* nullWire = new Wire("NULL", 'X', wireVectorIndex, "", nullptr);
						wirePtrs.at(wireVectorIndex + 1) = nullWire;
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

			string wireType;
			//everything but not gates 
			if (name!="NOT") {
				int intIn3 = stoi(strIn3);
				Gate* tempGate = new Gate(wirePtrs.at(in1), wirePtrs.at(in2), wirePtrs.at(intIn3), name, delay);
				wirePtrs.at(in1)->setDrive(tempGate);
				gatePtrs.push_back(tempGate);

				//set up wire 1
				if (wirePtrs.at(in1)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in1, "", nullptr);
					wirePtrs.at(in1) = tempWire;
				}
				//set up internal wire on 2
				if (wirePtrs.at(in2)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in2, "", nullptr);
					wirePtrs.at(in2) = tempWire;
				}

				if (wirePtrs.at(intIn3)->getName() == "NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', intIn3, "", nullptr);
					wirePtrs.at(intIn3) = tempWire;
				}
			}
			else {
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
				if (wirePtrs.at(in2)->getName()=="NULL") {
					Wire* tempWire = new Wire("INTERNAL", 'X', in2, "", nullptr);
					wirePtrs.at(in2) = tempWire;
				}
				Gate* tempGate = new Gate(wirePtrs.at(in1), nullptr,wirePtrs.at(in2), name, delay );
				wirePtrs.at(in1)->setDrive(tempGate);
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
	string filename = "circuit0_v.txt"; // can we use strings for the .open()
	//cout << "Please enter Vector file name" << endl;
	//cin >> filename;
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
	while (vectorFile >> temp) { //FIXME: skips lines and doesnt break out of loop
		vectorFile  >> wireName >>  time >> wireVal;
		q.emplace(w.at(NameToIndex(w, wireName)), time, wireVal, cc);
	}
	vectorFile.close();
	
	return 0;
}

int Simulate(priority_queue<Event>& q, priority_queue<Event> &pq)
{
	vector<Wire*> circuit;
	//vector<Wire*> output;
	int currTime = 0;
	int cc = 0; //creation count
	while (!q.empty()) {
		q.top().getEventWire()->setVal(q.top().getVal()); //set the wire to the event value
		currTime += q.top().getTime();//add time
		circuit.push_back(q.top().getEventWire()); //add till the circuit it done
		while (!(circuit.empty())) { //till we reach the output wire
			for (int i = 0; i < circuit.at(0)->getDrive().size(); i++) { //for each of the gates in the fanout (Drive)
				circuit.front()->getDrive().at(i)->gateResult(); //set the outWire to the correct value
				currTime += circuit.at(0)->getDrive().at(i)->getDelay(); //add gate delays
				if (circuit.at(0)->getDrive().at(i)->getOutWire() != nullptr) { //if it is not a final output wire
					circuit.push_back(circuit.at(0)->getDrive().at(i)->getOutWire()); //keep adding to the circuit vector
				}
				else {
					pq.emplace(circuit.at(0)->getDrive().at(i)->getOutWire(), currTime, circuit.at(0)->getDrive().at(i)->getOutWire()->getVal(), cc); //create events from the output of the circuit
						cc++;
				}
			}
			circuit.erase(circuit.begin()); //pop off first element
		}
		q.pop(); // pop of first element
	}
	return 0;
}



int NameToIndex(vector<Wire*> &w, string n)
{
	int i = 1;
	while (n != w.at(i)->getName()) {
		i++;
	}
	return i;
}




int Print()
{
	return 0;
}