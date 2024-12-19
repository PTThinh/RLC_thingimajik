#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"

using namespace std;

complex<double> Circuit::getImpedance() {
	return impedance;
}
complex<double> Circuit::getCurrent() {
	return current;
}
complex<double> Circuit::getVoltage() {
	return voltage;
}