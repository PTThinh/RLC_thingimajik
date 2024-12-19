#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "SingleCircuit.h"
#include "OOP_Project.h"

using namespace std;

void SingleCircuit::allocate()
{
	//empty - since single circuit does not need any array
}
void SingleCircuit::deallocate()
{
	singleComponent = Component();
	length = 0;
}
SingleCircuit::SingleCircuit(const Component& comp)
{
	length = 1;
	singleComponent = comp;
	allocate();
}
SingleCircuit& SingleCircuit::operator=(const SingleCircuit& circuit)
{
	length = circuit.length;
	singleComponent = circuit.singleComponent;
	return *this;
}

void SingleCircuit::CalculatePrintedDimension() {
	printedHeight = 1;
	printedLength = COMPONENT_WIDTH;
}


void SingleCircuit::PrintCircuit(int* row, int* col) {
	MoveCursor(*row, *col);
	if (singleComponent.getType() == Resistor) {
		cout << "-vvvvv-";
	} // move to the locaion and print the corresponding component
	else if (singleComponent.getType() == L_Inductor) {
		cout << "-uuuuu-";
	}
	else if (singleComponent.getType() == Capacitor) {
		cout << "--| |--";
	}
	*col += COMPONENT_WIDTH;
}