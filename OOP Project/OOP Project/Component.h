#ifndef _componentheader_
#define _componentheader_


#include <iostream>
#include <cmath>
#include <complex>

using namespace std;


class Component
{

private:
	string type;
	double value;
	complex<double> Impedance;

public:
	Component(string t, double v) //v mean R for resistor, L and C for inductor and capacitor / t is type of component (RLC)
	{
		type = t;
		value = v;
		if (type == "R") Impedance = complex<double>(v, 0.0);
		else if (type == "C") 
		{
			double Zc = w*v;
			Zc = -1 / Zc;
			Impedance = complex<double>(0.0, Zc);
		}
		else if (type == "L")
		{
			double Zl = w * v;
			Impedance = complex<double>(0.0, Zl);
		}
	}
};
















#endif