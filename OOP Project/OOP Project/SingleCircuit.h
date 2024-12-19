#ifndef _SINGLE_CIRCUIT_HEADER_
#define _SINGLE_CIRCUIT_HEADER_

#include "Component.h"
#include "Circuit.h"

using namespace std;

class SingleCircuit : public Circuit
{
private:
	Component singleComponent;
public:
	
	void allocate();
	void deallocate();

	SingleCircuit(const Component& comp); // single circuit contain only 1 component , create
	SingleCircuit& operator=(const SingleCircuit& circuit); //to assign value
	void CalculatePrintedDimension();
	void PrintCircuit(int* row, int* col);

};

#endif

