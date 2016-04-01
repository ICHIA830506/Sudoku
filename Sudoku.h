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
	void change();
	void changeNum(int a,int b);//fun.4
	void changeRow(int a,int b);//fun.5
	void changeCol(int a,int b);//fun.6
	void rotate(int n);//fun.7
	void flip(int n);//fun.8
	void transform();//fun.9
	
	vector<int> getBoard();
	void setAns(int A);
	int getAns();
	
	static const int sudokuSize = 81;
	static const int Size = 9;
	
	private:
	
	int map[sudokuSize];
	int count[sudokuSize];
	int Found;	
	bool tag[sudokuSize][Size];
	
	
	
	
	
};
