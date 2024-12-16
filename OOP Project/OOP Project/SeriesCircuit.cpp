#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "SeriesCircuit.h"
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