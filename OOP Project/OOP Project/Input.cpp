#include "Input.h"
#include "OOP_Project.h"
#include <complex>
#include <conio.h> // For _getch
#include <iostream>
#include <limits>
#define NOMINMAX
#include <windows.h>

using namespace std;

extern double Vm, w, phi;
extern complex<double> Vphasor;

void ShowWelcomeScreen() {
    CLEAR_SCREEN;
    cout << GREEN;
    cout << "     ____           _            ____  " << endl;
    cout << "  U |  _\"\\ u       |\"|        U /\"___| " << endl;
    cout << "   \\| |_) |/     U | | u      \\| | u   " << endl;
    cout << "    |  _ <        \\| |/__      | |/__  " << endl;
    cout << "    |_| \\_\\        |_____|      \\____| " << endl;
    cout << "    //   \\\\_       //  \\\\      _// \\\\  " << endl;
    cout << "   (__)  (__)     (_\")(\"_)    (__)(__)" << endl;
    cout << RESET << endl;
    cout << BG_CYAN << "                                        \n"
        << RESET;
    cout << BG_CYAN << " " << RESET << "                                      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "      " << RED << "WELCOME TO THE RLC CIRCUIT      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "          " << RED << "CALCULATOR PROGRAM          " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   This program allows you to input   " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   an RLC circuit and calculate the   " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   impedance, voltage, and current    " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   of each component. Follow the      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   instructions to input components   " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "   and get your results!              " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "            Press ENTER to start...   " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                      " << BG_CYAN << " \n";
    cout << BG_CYAN << "                                        \n"
        << RESET;

    cin.get();
}

void ShowInputVoltageInstructions() {
    CLEAR_SCREEN;
    cout << BG_CYAN << "                                      \n"
        << RESET;
    cout << BG_CYAN << " " << RESET << "                                    " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "      " << RED << "INPUT THE VOLTAGE SOURCE      " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                    " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    V(t) = V_max . cos(wt + phi)    " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                    " << BG_CYAN << " \n";
    cout << BG_CYAN << "                                      \n\n"
        << RESET;
}

void ShowInputInstructions() {
    CLEAR_SCREEN;
    cout << BG_CYAN << "                                                    \n"
        << RESET;
    cout << BG_CYAN << " " << RESET << "                                                  " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                " << RED << "INPUT YOUR CIRCUIT                " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                                  " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    " << CYAN << "R" << RESET << " - Resistor                                  " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    " << CYAN << "L" << RESET << " - Inductor                                  " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    " << CYAN << "C" << RESET << " - Capacitor                                 " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    Input " << CYAN << "any Number" << RESET << " to make a parallel branch    " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "    " << CYAN << "E" << RESET << " - End the current branch or end circuit     " << BG_CYAN << " \n";
    cout << BG_CYAN << " " << RESET << "                                                  " << BG_CYAN << " \n";
    cout << BG_CYAN << "                                                    \n\n"
        << RESET;
}

void disableInputBuffering() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT); // Disable line input and echo
    SetConsoleMode(hStdin, mode);
}

void enableInputBuffering() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode |= (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT); // Enable line input and echo
    SetConsoleMode(hStdin, mode);
}

void MoveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H";
}

void InputVoltage() {
    cout << "Enter the Max Voltage\n";
    cout << "V_max = ";
    Vm = GetDoubleInput();

    cout << "Enter the Voltage Source's Angular Frequency\n";
    cout << "w = ";
    w = GetDoubleInput();

    cout << "Enter the Voltage Source's Offset Angle in degrees\n";
    cout << "phi = ";
    phi = GetDoubleInput();

    cout << "The Voltage Source:\nV(t) = " << Vm << " . cos(" << w
        << "t + " << phi << "deg)" << endl;
    double phirad = phi * PI / 180.0;
    Vphasor = complex<double>(cos(phirad), sin(phirad)) * Vm;

    cout << "Press Enter to Confirm...";
    cin.get();
    cin.ignore();
}

string ToLowercase(const string& str) {
    string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

double GetDoubleInput() {
    while (true) {
        // cout << "Enter a number with a unit (e.g., 10m, 0.7u, 5k): ";
        string input;
        cin >> input;

        // Split number and unit
        size_t pos = 0;
        for (size_t i = 0; i < input.size(); ++i) {
            if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-') {
                pos = i;
                break;
            }
        }
        if (pos == 0) {
            try {
                double value = stod(input);
                return value;
            }
            catch (...) {
                PrintErrorMessage(false);
                continue;
            }
        }
        string numberPart = input.substr(0, pos);
        string unitPart = input.substr(pos);

        try {
            // Attempt to convert the number part
            double value = stod(numberPart);

            // Determine the multiplier based on the unit
            double multiplier = 1.0;
            if (unitPart == "m") { // milli
                multiplier = 1e-3;
            }
            else if (unitPart == "u") { // micro
                multiplier = 1e-6;
            }
            else if (unitPart == "n") { // nano
                multiplier = 1e-9;
            }
            else if (unitPart == "p") { // pico
                multiplier = 1e-12;
            }
            else if (unitPart == "k") { // kilo
                multiplier = 1e3;
            }
            else if (unitPart == "M") { // mega
                multiplier = 1e6;
            }
            else if (unitPart == "") { // No unit
                multiplier = 1.0;
            }
            else {
                throw invalid_argument("Unknown unit");
            }

            return value * multiplier;

        }
        catch (...) {
            PrintErrorMessage(false);
        }
    }
}

int GetIntInput() {
    int n;
    while (true) {
        if (cin >> n) {
            return n;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
        }
    }
}

void PrintErrorMessage(bool stop) {
    cout << BG_RED << WHITE << "Invalid Input. Please try again...\n"
        << RESET;
    if (stop) {
        cout << "Press Enter to try again...\n";
        cin.get();
        cin.get();
    }
}