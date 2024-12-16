#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "SingleCircuit.h"

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