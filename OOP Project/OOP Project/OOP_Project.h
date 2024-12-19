#ifndef _OOP_PROJECT_HEADER_
#define _OOP_PROJECT_HEADER_

#define COMPONENT_WIDTH 7 // how long a component is
#define PI 3.1415926535898
#define MAX_COMPONENTS 10000

#define RESISTOR "-vvvvv-"
#define INDUCTOR "-uuuuu-"
#define CAPACITOR "--| |--"

#include "SeriesCircuit.h"

void InputCircuit();
Circuit** InputSectionOfCircuit(int* length, int rowsToBeCleared);
void DisplayCircuit();

void GetArrowKeysInput();
void SetColor(int compNo, string color);


#endif 