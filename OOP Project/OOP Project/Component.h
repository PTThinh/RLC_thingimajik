#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <complex>

using namespace std;

enum ComponentType //declare a new "datatype"
{
	Resistor,
	L_Inductor,
	Capacitor
};

class Component
{

private:
	ComponentType type;
	double value;
	complex<double> impedance;
	complex<double> voltage;
	complex<double> current;

public:
	Component(const ComponentType &type_, double &value); // create new component; the _ help us - the coder to differ to the private data
	Component(); // create empty component
	Component(const Component& comp_); // copy component from another component
	
	Component& operator= (const Component& comp_); // operator = to assign value

	
	//Getters:
	ComponentType getType() const;
	double getValue() const;
	complex<double> getImpedance() const;

	// set R, U, I. We don't do R here because R can be calculated already
	void SetRUI(complex<double> U, complex<double> I);

	// print out the information of the component
	void DisplayInfo();
};

#endif