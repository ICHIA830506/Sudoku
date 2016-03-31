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
	void setMap(int set_map[]);
	int getElement(int index);
	vector<int> getBoard();//
	void setAns(int A);//
	int getAns();//
	bool isCorrect();
	
	static const int sudokuSize = 81;
	static const int Size = 9;
	
	private:
	
	bool checkUnity(int arr[]);
	int map[sudokuSize];
	
	int count[sudokuSize];
	int Found;	
	bool tag[sudokuSize][Size];
	
	
	
};
