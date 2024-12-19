
#include <iostream>
#include <cmath>
#include <complex>
#include "Component.h"
#include "OOP_Project.h"
#include "Input.h"

using namespace std;

extern double Vm, w, phi;
extern complex<double> Vphasor;
extern SeriesCircuit* mainCircuit;

extern Component* componentList;
extern int selectedComponent;

Component::Component(const ComponentType& type_, double& value_){
	type = type_;
	value = value_;
	double Z;
	if (type == Resistor) impedance = complex<double>(value, 0.0);
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

void Component::SetRUI(complex<double> U, complex<double> I) {
	voltage = U;
	current = I;
}

void Component::DisplayInfo() {
	CLEAR_ROW(mainCircuit->printedHeight + 2);
	string compType = type == Resistor ? "Resistor" : type == L_Inductor ? "Inductor"
		: "Capacitor";
	cout << CYAN << "Component: " << RESET << compType << "\n";
	cout << CYAN << "Impedance: " << RESET << "(" << impedance.real() << " + " << impedance.imag() << "j) ohm\n";
	cout << CYAN << "Voltage: " << RESET << "(" << voltage.real() << " + " << voltage.imag() << "j) V\n";
	cout << CYAN << "Current: " << RESET << "(" << current.real() << " + " << current.imag() << "j) A\n\n";

	cout << "Use " << YELLOW << "Left/Right Arrow Keys" << RESET << " to select components.\n";
	cout << "Press " << RED << "\'Q\'" << RESET << " to exit.\n";
	cout << "Press " << GREEN << "\'R\'" << RESET << " to restart the program.\n";
}