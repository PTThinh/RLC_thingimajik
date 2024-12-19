#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "SeriesCircuit.h"
#include "OOP_Project.h"


using namespace std;



void SeriesCircuit::allocate() {
	circuits = new Circuit * [length]; // an array of class circuit: with [length] amount of elements
}

void SeriesCircuit::deallocate() {
	delete[] circuits;
	circuits = nullptr; //since circuits are array - pointers pointing to elements. we reset it by pointing to nullptr
}

	//constructor and copy function
SeriesCircuit::SeriesCircuit(int length_, Circuit** circuits_) {
	length = length_;
	allocate();
	for (int i = 0; i < length; i++) {
		circuits[i] = circuits_[i];
	}
}

SeriesCircuit& SeriesCircuit::operator= (const SeriesCircuit& circuit){
	length = circuit.length;
	allocate();
	for (int i = 0; i < length; i++) {
		circuits[i] = circuit.circuits[i];
	}
	return *this;
}

void SeriesCircuit::CalculatePrintedDimension()
{
	printedHeight = 0;
	printedLength = 0;
	for (int i = 0; i < length; i++) // its a box that need to accomodate the biggest height and the biggest length from the circuit
	{
		// we try to find the component with the greated height
		if (circuits[i]->printedHeight > printedHeight) // we compare circuits[i] height with the current heigh we record
		{
			printedHeight = circuits[i]->printedHeight; //we set the recorded height to the current heigh
		}
		printedLength += circuits[i]->printedLength + 2; // the additional +1 provide buffer between 2 component(make it clearer)
	}
}


void SeriesCircuit::PrintCircuit(int* row, int* col) {
	MoveCursor(*row, *col);
	for (int i = 0; i < length; i++)
	{
		MoveCursor(*row, *col);
		cout << "-";
		(*col)++;
		circuits[i]->PrintCircuit(row, col);
		MoveCursor(*row, *col);
		cout << "-";
		(*col)++;
	}
}
