#include <iostream>
#include "Sudoku.h"

using namespace std;


int main()
{	
    int A = 0;
    Sudoku su;
	su.giveQuestion();
	su.readIn();
	su.solve();
	su.change();
	return 0;	
}
