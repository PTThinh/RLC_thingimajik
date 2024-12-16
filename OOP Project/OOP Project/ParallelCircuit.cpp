#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "ParallelCircuit.h"
using namespace std;

void ParallelCircuit::allocate() {
	branches = new Circuit * [length];
}

void ParallelCircuit::deallocate() {
	delete[] branches;
	branches = nullptr;
	length = 0;
}

//constructor and copy
ParallelCircuit::ParallelCircuit(int length_, Circuit** branches_) {
	length = length_;
	allocate();
	for (int i = 0; i < length; i++) {
		branches[i] = branches_[i];
	}

}
ParallelCircuit& ParallelCircuit::operator= (const ParallelCircuit& circuit) {
	length = circuit.length;
	allocate();
	for (int i = 0; i < length; i++) {
		branches[i] = circuit.branches[i];
	}
	return *this;
}