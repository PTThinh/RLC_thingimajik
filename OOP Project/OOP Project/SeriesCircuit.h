#ifndef _SERIES_CIRCUIT_HEADER_
#define _SERIES_CIRCUIT_HEADER_

#include "Component.h"
#include "Circuit.h"
using namespace std;

class SeriesCircuit : public Circuit
{
private:
	Circuit** circuits; //* of array, * of polymorphism // circuit: array of single circuit
	// no need for length since Circuit.h has it
public:
	void allocate();
	void deallocate();

	//constructor and copy
	SeriesCircuit(int length_, Circuit** circuits_); 
	SeriesCircuit& operator= (const SeriesCircuit& circuit); 

	void CalculatePrintedDimension();
	void PrintCircuit(int* row, int* col);
	void CalculateImpedance();
	void CalculateRUI(complex<double> voltageEq);
};
#endif