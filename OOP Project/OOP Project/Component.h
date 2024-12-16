#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

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

public:
	Component(const ComponentType &type_, double &value); // create new component; the _ help us - the coder to differ to the private data
	Component(); // create empty component
	Component(const Component& comp_); // copy component from another component
	
	Component& operator= (const Component& comp_); // operator = to assign value

	void print();
	
	//Getters:
	ComponentType getType() const;
	double getDouble() const;
	complex<double> getImpedance() const;


};

#endif