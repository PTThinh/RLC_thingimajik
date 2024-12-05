
#include <iostream>
#include <cmath>
#include <complex>
#include "Component.h"
#define PI 3.1415926535898 // idk why or how but M_PI from <cmath> doesnt work ?

using namespace std;
double Vm, w, phi;
complex<double> Vphasor;

void InputVoltage();

int main()
{
    InputVoltage();

    int R, C, L;
    cout << "Input your circuit here:" << endl;
    cout << "Input the number of Resistors in your circuit" << endl;
    cin >> R;
    cout << "The number of Capacitor:" << endl;
    cin >> C;
    cout << "The number of Inductor:" << endl;
    cin >> L;

}

void InputVoltage()
{
    cout << "Input your voltage source in this manner: V(t) = Vm.sin(wt + phi)" << endl;

    cout << "Input your max voltage" << endl;
    cout << "Vmax = "; cin >> Vm;
    cout << "Input your voltage source's angular frequency" << endl;
    cout << "w = "; cin >> w;
    cout << "Input your voltage source's offset angle (degree)" << endl;
    cout << "phi = "; cin >> phi;


    cout << "You have inputed the voltage source V(t) = " << Vm << ".sin(" << w << "t + " << phi << "deg)" << endl;
    double phirad = phi*PI/180.0;
    Vphasor = complex<double>(cos(phirad), sin(phirad)) * Vm;

}


void InputCircuit()
{
    int paraNumber;
    //string 
    cout << "Input the number of branches that came from your node";
    cin >> paraNumber;
    cout << "Input circuit, input R L C and its corresponding value to add component, input E to end that branch and move on new branch";
    
    //cin >> 
}