#include <iostream>
#include <vector>
#include <fstream>
#include "Sudoku.h"
using namespace std;
//----------------------------------------





int Sudoku::Ans = 0;
int Sudoku::cul = 0;
int Sudoku::map_tmp[81];

//----------------------------------------
Sudoku::Sudoku()
{
	for(int i=0; i<sudokuSize; ++i)
	{
		map[i] = 0;
	}
		
}
//----------------------------------------
Sudoku::Sudoku(vector<int> init_map, int A)
{
	cul++;
	for(int i=0; i<sudokuSize; ++i)
		map[i] = init_map[i];
	//
	for(int i=0;i<sudokuSize;++i)
	{
		count[i]=0;
		for(int j=0;j<Size;++j)
			tag[i][j] = 0;
	}
	Found = 0;
	setAns(A);
	solve();
}
//----------------------------------------
void Sudoku::giveQuestion()//fun.1
{
	ofstream out("SudokuBoard",ios::out);
	if(!out){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	out<<"0 3 0 8 4 2 0 6 1"<<endl
	   <<"0 4 2 6 1 5 3 0 0"<<endl
	   <<"0 0 6 7 9 3 8 0 4"<<endl
	   <<"7 2 5 4 3 0 0 0 9"<<endl
	   <<"6 0 0 1 0 7 0 3 2"<<endl
	   <<"0 1 4 0 2 8 7 5 0"<<endl
	   <<"2 7 3 5 0 1 9 0 8"<<endl
	   <<"4 6 0 0 8 0 0 0 5"<<endl
	   <<"0 8 0 2 0 4 6 1 0"<<endl;
}
//----------------------------------------
void Sudoku::readIn()//fun.2
{
	
	int sudoku_in[sudokuSize];
	
	ifstream in("SudokuBoard",ios::in);
	if(!in){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	for(int i=0;i<sudokuSize;++i)
	{
		in>>sudoku_in[i];
	}
	for(int i=0;i<sudokuSize;++i)
	{
		map[i] = sudoku_in[i];
	}
}


//----------------------------------------
void Sudoku::solve()//fun.3
{
	int DisNum_row, DisNum_column, DisNum_cell;
	int Blank_row, Blank_column, Blank_cell;
    int	BlankAddress_row, BlankAddress_column, BlankAddress_cell;

    for(int i=0;i<sudokuSize;++i)
	{
		if(map[i])
			Found++;
		else{
			for(int j=0;j<Size;++j)
			{
				DisNum_row = map[(i/Size)*Size+j];
				if(DisNum_row && !tag[i][DisNum_row-1])
				{
					count[i]++;
					tag[i][DisNum_row-1] = true;
				}
				DisNum_column = map[j*Size+i%Size];
				if(DisNum_column && !tag[i][DisNum_column-1])
				{
					count[i]++;
					tag[i][DisNum_column-1] = true;
				}
				DisNum_cell = map[((i/(Size*3))*3+j/3)*Size + ((i%Size)/3)*3+j%3];
				if(DisNum_cell && !tag[i][DisNum_cell-1])
				{
					count[i]++;
					tag[i][DisNum_cell-1] = true;
				}
			}
		}
	}
	
	for(int i=0;i<sudokuSize;++i)
	{
		if(!map[i] && count[i]==8)
		{
			count[i] = 0;
			Found++;
			for(int j=0;j<Size;++j)
			{
				if(!tag[i][j])
				{
					map[i] = j+1;
					for(int k=0;k<Size;++k)
					{
						Blank_row = map[(i/Size)*Size+k];
						BlankAddress_row = (i/Size)*Size+k;
						if(!Blank_row && !tag[BlankAddress_row][j])
						{
							count[BlankAddress_row]++;
							tag[BlankAddress_row][j] = true;
						}
						Blank_column = map[k*Size+i%Size];
						BlankAddress_column = k*Size+i%Size;
						if(!Blank_column && !tag[BlankAddress_column][j])
						{
							count[BlankAddress_column]++;
							tag[BlankAddress_column][j] = true;
						}
						Blank_cell = map[((i/(Size*3))*3+k/3)*Size+((i%Size)/3)*3+k%3];
						BlankAddress_cell = ((i/(Size*3))*3+k/3)*Size+((i%Size)/3)*3+k%3;
						if(!Blank_cell && !tag[BlankAddress_cell][j])
						{
							count[BlankAddress_cell]++;
							tag[BlankAddress_cell][j] = true;
						}
					}
				}
			}
			i = -1;	
		}  	
	}
	if(Found == 81)
	{
		setAns(Ans+1);
		if(Ans==1)
		{
			for(int i=0;i<sudokuSize;++i)
				map_tmp[i] = map[i];
		}
			
		if(Ans>1)
		{
			cout<<"2"<<endl;
		    exit(1);
		}
			
		
	}
		
	else
	{
		int Max,i_Max;
		Max = 0;
		i_Max = -1;
		for(int i=0;i<sudokuSize;++i)
		{
			if(count[i]>Max)
			{
				Max = count[i];
				i_Max = i;
			}
		}
		
		for(int j=0;j<Size;++j)
		{
			if(!tag[i_Max][j])
			{
				map[i_Max] = j+1;
				
				Sudoku *tmp = new Sudoku(getBoard(),getAns());
				cul--;
				delete tmp;
			}
		}
	}
	//cout << cul <<"CUL"<<endl;
	if (cul==0 && Ans ==0)
	{
		cout << getAns() <<endl;
		exit(1);
	}
	if (cul==0 && Ans ==1)
	{
		cout << getAns() <<endl;
		for(int j=0;j<sudokuSize;++j)
				map[j] = map_tmp[j];
		for(int i=0; i<sudokuSize; ++i)
		{			
			if(map[i]==0)
			{
				cout <<" ";
			}
			else{
				cout << map[i] << ' ';
			}
			if ((i+1)%9 ==0)
			{
				cout << endl;
			}
		}
		
	}

	
	cout << endl;
}

//----------------------------------------
void Sudoku::setMap(int set_map[])
{
	for(int i=0; i<sudokuSize; ++i)
		map[i] = set_map[i];
}
//----------------------------------------
int Sudoku::getElement(int index)
{
	return map[index];
}
//----------------------------------------
vector<int> Sudoku::getBoard()
{
	vector<int> out_map(sudokuSize);
	for(int i=0; i<sudokuSize; ++i)
	{
		out_map[i] = map[i];
	}
	return out_map;
}
//----------------------------------------
int Sudoku::getAns()
{
	return Ans;
}
//----------------------------------------
void Sudoku::setAns(int A)
{
	Ans = A;
}








//----------------------------------------
bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9]; // counters
	for(int i=0; i<9; ++i)
		arr_unity[i] = 0; // initialize
	for(int i=0; i<9; ++i)
		++arr_unity[arr[i]-1]; // count
	for(int i=0; i<9; ++i)
		if(arr_unity[i] != 1) // all element
	        return false; // must be 1
	return true;
}
//----------------------------------------
bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9) // check rows
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<9; ++i) // check columns
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<9; ++i) // check cells
	{
		for(int j=0; j<9; ++j)
		{
			location = 27*(i/3) + 3*(i%3)+9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	return true;
}


	
	
	
