#include <iostream>
#include <cmath>
#include <complex>
#include "Circuit.h"
#include "Component.h"
#include "ParallelCircuit.h"
#include "OOP_Project.h"
using namespace std;

void ParallelCircuit::allocate() {
	branches = new Circuit * [length];
}

void ParallelCircuit::deallocate() {
	delete[] branches;
	branches = nullptr;
	length = 0;
}

//constructor and copy
ParallelCircuit::ParallelCircuit(int length_, Circuit** branches_) {
	length = length_;
	allocate();
	for (int i = 0; i < length; i++) {
		branches[i] = branches_[i];
	}

}
ParallelCircuit& ParallelCircuit::operator= (const ParallelCircuit& circuit) {
	length = circuit.length;
	allocate();
	for (int i = 0; i < length; i++) {
		branches[i] = circuit.branches[i];
	}
	return *this;
}

void ParallelCircuit::CalculatePrintedDimension() {
	printedHeight = 0;
	printedLength = 0;
	//is calculated inversed compare to series circuit
	for (int i = 0; i < length; i++)
	{
		if (branches[i]->printedLength > printedLength)
		{
			printedLength = branches[i]->printedLength;
		}
		printedHeight += branches[i]->printedHeight + 1;
	}
	printedHeight--; // since we want parallel lines to have 1 empty lines in between them: this line delete the last empty line 
}


void ParallelCircuit::PrintCircuit(int* row, int* col) //pointer so we can change value in function
{
    // this is our reference to return to
    int firstRow = *row;
    int firstCol = *col; 

    //counter so far
    int totalPrintedHeight = 0;
    MoveCursor(*row, *col);
    for (int i = 0; i < length; i++)
    {
        //change cursor coord
        *row = firstRow + totalPrintedHeight;
        *col = firstCol;
        
        //print
        branches[i]->PrintCircuit(row, col);


        //move cursor and print -- to fill in the blank space cause by different between 2 branches
        MoveCursor(firstRow + totalPrintedHeight, firstCol + branches[i]->printedLength);
        for (int j = branches[i]->printedLength + 1; j <= printedLength; j++)
        {
            cout << "-";
        }

        //if the branches is not the last branches: make the vertical wire(to connect branches)
        if (i != length - 1)
        {
            for (int j = firstRow + totalPrintedHeight + 1; j < firstRow + totalPrintedHeight + branches[i]->printedHeight + 1; j++)
            {
                MoveCursor(j, firstCol);
                cout << "{";
                MoveCursor(j, firstCol + printedLength - 1);
                cout << "}";
            }
        }
        //new height
        totalPrintedHeight += branches[i]->printedHeight + 1;
    }
    //putting cursor at the end of the branches after finnish
    *row = firstRow;
    *col = firstCol + printedLength;
}