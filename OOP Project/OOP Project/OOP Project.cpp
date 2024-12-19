
#include <iostream>
#include <cmath>
#include <complex>

#include "Component.h"
#include "Circuit.h"
#include "OOP_Project.h"
#include "ParallelCircuit.h"
#include "SeriesCircuit.h"
#include "SingleCircuit.h"

// idk why or how but M_PI from <cmath> doesnt work ?
#define PI 3.1415926535898
#define MAX_COMPONENTS 10000

using namespace std;
double Vm, w, phi;
complex<double> Vphasor;

void InputVoltage();

int main()
{
    InputVoltage();
    InputCircuit();


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

void ShowInputInstructions()
{
    cout << "**************************\n";
    cout << "*   INPUT YOUR CIRCUIT   *\n";
    cout << "*                        *\n";
    cout << "*    R - Resistor        *\n";
    cout << "*    L - Inductor        *\n";
    cout << "*    C - Capacito        *\n";
    cout << "*    Number to make      *\n";
    cout << "*    parallel branch     *\n";
    cout << "*    E - End the         *\n";
    cout << "*    current branch      *\n";
    cout << "*                        *\n";
    cout << "**************************\n";
}

void InputCircuit()
{
    ShowInputInstructions();
    int len;
    Circuit** inputCircuits = InputSectionOfCircuit(&len);
    cout << "Input Done, length = " << len << "\n";
    SeriesCircuit* mainCircuit = new SeriesCircuit(len, inputCircuits);
    mainCircuit->CalculatePrintedDimension();
    CLEAR_SCREEN;
    int row = 1;
    int col = 1;
    mainCircuit->PrintCircuit(&row, &col);
    for (int i = 0; i <= mainCircuit->printedHeight; i++)
    {
        cout << "\n";
    }
}
Circuit** InputSectionOfCircuit(int* length)
{
    Circuit** inputCircuit = new Circuit*[MAX_COMPONENTS];
    int inputCircuitLength = 0;
    string input;
    double inputValue;
    
    while (true)
    {
        cout << "Enter a command: ";
        cin >> input;
        if (input == "R")
        {
            cout << "Enter the resistance: ";
            cin >> inputValue;
            inputCircuit[inputCircuitLength] = new SingleCircuit(Component(Resistor, inputValue));
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension(); // calculate its length

            inputCircuitLength++;
        }
        else if (input == "L")
        {
            cout << "Enter the inductance: ";
            cin >> inputValue;
            inputCircuit[inputCircuitLength] = new SingleCircuit(Component(L_Inductor, inputValue));
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension(); // calculate its length
            inputCircuitLength++;
        }
        else if (input == "C")
        {
            cout << "Enter the capacitance: ";
            cin >> inputValue;
            inputCircuit[inputCircuitLength] = new SingleCircuit(Component(Capacitor, inputValue));
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension(); // calculate its length
            inputCircuitLength++;
        }
        else if (input == "E")
        {
            *length = inputCircuitLength; //dereferencing pointer to get value
            return inputCircuit;
        }
        else
        {
            int branchesCount;
            try
            {
                branchesCount = stoi(input);
            }
            catch (const invalid_argument& e)//e stand for error
            {
                cout << "Invalid input! Please enter a valid input." << endl;
                continue;
            }
            Circuit** branches = new Circuit * [branchesCount];
            for (int i = 0; i < branchesCount; i++)
            {
                int branchComponentCount;
                Circuit** tmp = InputSectionOfCircuit(&branchComponentCount);
                branches[i] = new SeriesCircuit(branchComponentCount, tmp);
                branches[i]->CalculatePrintedDimension();
            }
            inputCircuit[inputCircuitLength] = new ParallelCircuit(branchesCount, branches);
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension();
            inputCircuitLength++;
        }
    }
}

void MoveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H"; //will move cursor to the dersired coord
}