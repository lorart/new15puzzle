#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "file.h"
#include <vector>
using namespace std;

#define PUZZLEFILENAME "../puzzle1.txt"
#define SOLUTIONFILENAME "../puzzle_solution.txt"
//#define PUZZLESIZE 4


class Puzzlefunciton :public File //***inheritance
{
public:
	//inline
	inline  void printPuzzle(short* puzzle, int puzzlesize);
	void enterManually(int PUZZLESIZE);
	void createRandomArray(int PUZZLESIZE);
	void CheckOnePuzzle(vector<short*>& puzzlecontainer, int PUZZLESIZE);
	void CheckAllPuzzle(vector<short*>& puzzlecontainer);
	int checkRow(short* puzzle, int PUZZLESIZE);
	int checkColumn(short* temparry, int PUZZLESIZE);
	int checkReverseRow(short* temparry, int PUZZLESIZE);
	int checkReverseColum(short* temparry, int PUZZLESIZE);
	

};


