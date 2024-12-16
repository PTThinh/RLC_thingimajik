#ifndef _PARALLEL_CIRCUIT_HEADER_
#define _PARALLEL_CIRCUIT_HEADER_

#include "Component.h"
#include "Circuit.h"
using namespace std;

class ParallelCircuit : public Circuit
{
private:
	Circuit** branches; // branches in one parallel part ( number of components parallel
	// no need for length since Circuit.h has it

public:
	void allocate();
	void deallocate();

	//constructor and copy
	ParallelCircuit(int length_, Circuit** branches_);
	ParallelCircuit& operator= (const ParallelCircuit& circuit);

};

#endif