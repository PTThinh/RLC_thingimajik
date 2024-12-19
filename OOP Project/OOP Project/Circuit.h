#ifndef _CIRCUIT_HEADER_
#define _CIRCUIT_HEADER_

using namespace std;

class Circuit
{
protected:
	int length = 0; // length = the number of component on the circuit

public:
	//keep track of the length and height of the circuit when we display:
	int printedLength = 0; 
	int printedHeight = 0;

	virtual void allocate() = 0; // = 0 mean we dont implement this function in Circuit class
	virtual void deallocate() = 0; // virtual mean it is in the base class that derived class can overide
	// currently debating whether or not Circuit.cpp should exist or not since this class implement nothing

	virtual void CalculatePrintedDimension() = 0;
	virtual void PrintCircuit(int* row, int* col) = 0; //it is to printe the circuit


};
#endif