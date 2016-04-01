#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
	public:
	
	static int Ans;
	static int cul;
	static int map_tmp[81];	
	
	Sudoku();
	Sudoku(vector<int>,int);
    void giveQuestion();//fun.1
	void readIn();//fun.2
	void solve();//fun.3
	
	vector<int> getBoard();//
	void setAns(int A);//
	int getAns();//
	
	//
	void change();
	void changeNum(int a,int b);
	void changeRow(int a,int b);
	void changeCol(int a,int b);
	void rotate(int n);
	void flip(int n);
	//
	
	static const int sudokuSize = 81;
	static const int Size = 9;
	
	private:
	
	
	int map[sudokuSize];
	
	int count[sudokuSize];
	int Found;	
	bool tag[sudokuSize][Size];
	
	
	
	
	
};
