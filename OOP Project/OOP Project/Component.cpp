
#include <iostream>
#include <cmath>
#include <complex>
#include "Component.h"

using namespace std;
extern double Vm, w, phi;

Component::Component(const ComponentType& type_, double& value_){
	type = type_;
	value = value_;
	double Z;
	if (type == Resistor) impedance = complex<double>(value_, 0.0);
	else if (type == Capacitor)
	{
		Z = w * value;
		Z = -1 / Z;
		impedance = complex<double>(0.0, Z);
	}
	else if (type == L_Inductor)
	{
		Z = w * value;
		impedance = complex<double>(0.0, Z);
	}
}

Component::Component()
{
	//empty component
	type = Resistor;
	value = 0;
	impedance = complex<double>(0, 0);
}

Component::Component(const Component& comp_) {
	type = comp_.getType();
	value = comp_.getValue();
	impedance = comp_.getImpedance();
}

Component& Component::operator=(const Component& comp_)
{
	type = comp_.getType();
	value = comp_.getValue();
	impedance = comp_.getImpedance();
	return *this;
}

ComponentType Component::getType() const {
	return type;
}

double Component::getValue() const {
	return value;
}

complex<double> Component::getImpedance() const {
	return impedance;
}