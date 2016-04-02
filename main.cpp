#include <iostream>
#include "Sudoku.h"

using namespace std;


int main()
{	
    Sudoku ss;
	ss.giveQuestion();
	ss.readIn();
	ss.solve();
	ss.transform();
	
	return 0;	
}
