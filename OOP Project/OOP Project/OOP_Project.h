#ifndef _OOP_PROJECT_HEADER_
#define _OOP_PROJECT_HEADER_

#define COMPONENT_WIDTH 7 // how long a component is 
#define CLEAR_SCREEN cout <<"\033[2J" 

void InputVoltage(); // Input voltage source
void ShowInputInstructions(); //guide
void InputCircuit();


Circuit** InputSectionOfCircuit(int* length);
void MoveCursor(int row, int col);


#endif 