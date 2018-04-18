// CircutSim.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<queue>
#include<fstream>
#include<cstdlib>
#include "stdafx.h"
#include "Wire.h"
#include "Gate.h"
#include "Event.h"
using namespace std;

void ParseGate();
void ParseVector(priority_queue<Event> &q);
void Simulate();
void Print();
int main()
{
	//Step 1: parse Gate file

	//Step 2: parse vector file
	priority_queue<Event> eventQueue;
	ParseVector(eventQueue);

	//Step 3: simulation

	//Step 4: Print

	return 0;
}

void ParseGate()
{

}

void ParseVector(priority_queue<Event> &q)
{
	 
}

void Simulate()
{
}

void Print()
{
}
