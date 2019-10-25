#pragma once
#include <fstream>
#include <string>
#include <iostream>

#include <vector>
using namespace std;

#define PUZZLEFILENAME "../puzzle1.txt"
#define SOLUTIONFILENAME "../puzzle_solution.txt"
//#define PUZZLESIZE 4

class File
{
public:

	void writeColumToFile(string filename, short* puzzlcolum);
	void writeMutiArrayToFile(string filename, short* puzzle, int PUZZLESIZE);
	void writeSingleArrayToFile(string filename, short* puzzle, bool singlePuzzle, int PUZZLESIZE);
	void writeArrayToFile(string filename, short* puzzle, int PUZZLESIZE);

	int readFile(string filename, vector<short*>& puzzlecontainer, int PUZZLESIZE);
	void readFilewithOutPush(string filename, vector<short*>& puzzlecontainer, bool showfile, int PUZZLESIZE);
	void fileEmpty(const string fileName);
};

