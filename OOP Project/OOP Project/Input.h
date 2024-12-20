#ifndef _INPUT_HEADER_
#define _INPUT_HEADER_

#include <string>
//defining color:
// Foreground colors
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Background colors
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Reset color
#define RESET "\033[0m"

#define CLEAR_SCREEN system("cls");
#define CLEAR_ROW(rowCount) cout << "\033[" << rowCount << ";1H" << "\033[J"

using namespace std;

void ShowWelcomeScreen();
void ShowInputVoltageInstructions();
void ShowInputInstructions();

void disableInputBuffering();
void enableInputBuffering();

void MoveCursor(int row, int col);

void InputVoltage();

string ToLowercase(const string& str);
double GetDoubleInput();
int GetIntInput();
void PrintErrorMessage(bool stop);

#endif