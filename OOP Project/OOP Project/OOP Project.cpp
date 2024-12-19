#include "OOP_Project.h"
#include "Circuit.h"
#include "Component.h"
#include "Input.h"
#include "ParallelCircuit.h"
#include "SeriesCircuit.h"
#include "SingleCircuit.h"
#include <cmath>
#include <complex>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

// Global Variables
double Vm, w, phi;
complex<double> Vphasor;

SeriesCircuit* mainCircuit;

int** componentPosition = new int* [MAX_COMPONENTS];
Component** componentList = new Component * [MAX_COMPONENTS];
int componentCount = 0;
int selectedComponent = 0;

bool restart = true;

int main() {
    while (restart) {
        restart = false;
        ShowWelcomeScreen();
        ShowInputVoltageInstructions();
        InputVoltage();
        ShowInputInstructions();
        InputCircuit();
        mainCircuit->CalculateRUI(Vphasor);
        DisplayCircuit();
        GetArrowKeysInput();
    }
}

void InputCircuit()
{
    int len;
    Circuit** inputCircuits = InputSectionOfCircuit(&len, 13);
    mainCircuit = new SeriesCircuit(len, inputCircuits);
    mainCircuit->CalculateImpedance();
}
Circuit** InputSectionOfCircuit(int* length, int rowsToBeCleared)
{
    Circuit** inputCircuit = new Circuit*[MAX_COMPONENTS];
    int inputCircuitLength = 0;
    string input;
    double inputValue;
    
    while (true) {
        CLEAR_ROW(rowsToBeCleared);
        cout << "Enter a command: ";
        cin >> input;
        string lowerInput = ToLowercase(input);
        if (lowerInput == "r" || lowerInput == "l" || lowerInput == "c") {
            string promptText;
            ComponentType inputType;
            if (lowerInput == "r") {
                promptText = "Enter the Resistance: ";
                inputType = Resistor;
            }
            else if (lowerInput == "l") {
                promptText = "Enter the Inductance: ";
                inputType = L_Inductor;
            }
            else if (lowerInput == "c") {
                promptText = "Enter the Capacitance: ";
                inputType = Capacitor;
            }

            cout << promptText;
            inputValue = GetDoubleInput();
            inputCircuit[inputCircuitLength] = new SingleCircuit(Component(inputType, inputValue));
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension();
            inputCircuit[inputCircuitLength]->CalculateImpedance();
            inputCircuitLength++;
        }
        else if (lowerInput == "e") {
            *length = inputCircuitLength;
            return inputCircuit;
        }
        else {
            int branchesCount;
            try {
                branchesCount = stoi(input);
            }
            catch (const invalid_argument& e) {
                PrintErrorMessage(true);
                continue;
            }

            Circuit** branches = new Circuit * [branchesCount];
            for (int i = 0; i < branchesCount; i++) {
                CLEAR_ROW(rowsToBeCleared);
                cout << "Branch " << i + 1 << "/" << branchesCount << "\n";

                int branchComponentCount = 0;
                Circuit** tmp = InputSectionOfCircuit(&branchComponentCount, rowsToBeCleared + 1);
                branches[i] = new SeriesCircuit(branchComponentCount, tmp);
                branches[i]->CalculatePrintedDimension();
                branches[i]->CalculateImpedance();
            }

            inputCircuit[inputCircuitLength] = new ParallelCircuit(branchesCount, branches);
            inputCircuit[inputCircuitLength]->CalculatePrintedDimension();
            inputCircuit[inputCircuitLength]->CalculateImpedance();
            inputCircuitLength++;
        }
    }
}

void DisplayCircuit() {
    mainCircuit->CalculatePrintedDimension();
    CLEAR_SCREEN;
    int row = 1;
    int col = 1;
    mainCircuit->PrintCircuit(&row, &col);
}

void GetArrowKeysInput() {
    disableInputBuffering();
    SetColor(selectedComponent, YELLOW);
    componentList[selectedComponent]->DisplayInfo();
    while (true) {
        char c = _getch();         // Read a character directly from the keyboard
        if (c == 0 || c == -32) {  // Arrow keys return 0 or -32 first
            char arrow = _getch(); // Get the actual arrow key code
            if (arrow == 75) {     // Left arrow (ASCII code for left arrow in Windows)
                SetColor(selectedComponent, RESET);
                selectedComponent--;
                if (selectedComponent < 0) {
                    selectedComponent += componentCount;
                }
                SetColor(selectedComponent, YELLOW);
            }
            else if (arrow == 77) { // Right arrow (ASCII code for right arrow in Windows)
                SetColor(selectedComponent, RESET);
                selectedComponent++;
                if (selectedComponent >= componentCount) {
                    selectedComponent -= componentCount;
                }
                SetColor(selectedComponent, YELLOW);
            }
            MoveCursor(mainCircuit->printedHeight + 1, 1);
            componentList[selectedComponent]->DisplayInfo();
        }
        else if (c == 'q') { // Quit on 'q'
            break;
        }
        else if (c == 'r') {
            restart = true;
            break;
        }
    }

    enableInputBuffering();
}

void SetColor(int compNo, string color) {
    MoveCursor(componentPosition[compNo][0], componentPosition[compNo][1]);
    cout << color;
    if (componentList[compNo]->getType() == Resistor) {
        cout << RESISTOR;
    }
    else if (componentList[compNo]->getType() == L_Inductor) {
        cout << INDUCTOR;
    }
    else if (componentList[compNo]->getType() == Capacitor) {
        cout << CAPACITOR;
    }
    cout << RESET;
}