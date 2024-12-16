
#include <iostream>
#include <cmath>
#include <complex>
#include "Component.h"

using namespace std;
extern double Vm, w, phi;
extern complex<double> Vphasor;

Component::Component(string t, double v) //v mean R for resistor, L and C for inductor and capacitor / t is type of component (RLC)
{
	type = t;
	value = v;
	if (type == "R") impedance = complex<double>(v, 0.0);
	else if (type == "C")
	{
		double Zc = w * v;
		Zc = -1 / Zc;
		impedance = complex<double>(0.0, Zc);
	}
	else if (type == "L")
	{
		double Zl = w * v;
		impedance = complex<double>(0.0, Zl);
	}
}
