#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "puzzle.h"
#include "math.h"
#include "file.h"
#include <time.h> 
using namespace std;

#define PUZZLEFILENAME "../puzzle1.txt"
#define SOLUTIONFILENAME "../puzzle_solution.txt"

int PUZZLESIZE=3;

vector<short*> puzzlecontainer;


File file;
Puzzlefunciton puzzlefunction;
Math math;

int puzzlemenu();
int menu();


int menu() {
	while (1) {

		cout << "-------------------------------------\n"<<endl;
		cout << "\tWelcome to 15-puzzle\n\tPlease enter number to choose menu\n" << endl; 
		cout << "-------------------------------------\n" << endl; 
		cout << "\t1.Show(Open) the file\n" << endl; 
		cout << "\t2.Enter the puzzle number  manually\n" << endl; 
		cout << "\t3.Enter the puzzle number though file\n" << endl; 
		cout << "\t4.Random puzzle number\n" << endl; 
		cout << "\t5.Rechoose the puzzlesize\n" << endl;
		cout << "\t[Enter 0 to exit]\n" << endl; 
		cout << "-------------------------------------\n" << endl;
		int input;
		cin >> input;
		if (cin.fail()) {
			cout << "not a number,please try again" << endl;

			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (input < 0 || input>5) {
				cout << "Please input from 0~5" << endl;
			}
			else {

				switch (input)
				{
				case 0://exit
				//	cout << "see you" << endl;
					exit(0);
					break;

				case 1://Show(Open) the file
					file.readFile(PUZZLEFILENAME, puzzlecontainer, PUZZLESIZE);
					break;
				case 2://Enter the puzzle number  manually
					file.fileEmpty(PUZZLEFILENAME);
					puzzlecontainer.clear();
					puzzlefunction.enterManually(PUZZLESIZE);
					if(!file.readFile(PUZZLEFILENAME, puzzlecontainer, PUZZLESIZE))
					{
						puzzlemenu();//show puzzlemenu
					}
					

					break;
				case 3://Enter the puzzle number though file
					

					if (!file.readFile(PUZZLEFILENAME, puzzlecontainer, PUZZLESIZE))
					{
						puzzlemenu();//show puzzlemenu
					}


					break;

				case 4:
				{//random puzzle number 
					file.fileEmpty(PUZZLEFILENAME);
					puzzlecontainer.clear();
					cout << "please enter how many  random puzzle you need" << endl;
					int temp;
					cin >> temp;

					ofstream puzzlefile;
					puzzlefile.open(PUZZLEFILENAME, ios::app);
					puzzlefile << temp;
					puzzlefile << "\n";
					puzzlefile.close();
					for (int i = 0; i < temp; i++)
					{
						puzzlefunction.createRandomArray(PUZZLESIZE);
					}
					file.readFilewithOutPush(PUZZLEFILENAME, puzzlecontainer, 0, PUZZLESIZE);

					puzzlemenu();//show puzzlemenu

					break;
				}
				case 5://rechoose the puzzle size
					return 0;
					break;


				break;
				default:
					break;
				}

			}
		}
	}
}

int puzzlemenu() {
	while (1) {
		cout << "------------------------------------------------------------------------ " << endl;
		cout << "\t* [press 1] *identify*       row,column in this [single] puzzle *" << endl;
		cout << "\t* [press 2] *cousework 1/2*  show how many row,column in [all pussible] puzzle *" << endl;
		cout << "\t* [Enter 0 to return] *" << endl;
		cout << "------------------------------------------------------------------------ " << endl;

		
		int input;
		cin >> input;
		if (cin.fail()) {
			cout << "*error input" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
		
				if (input >= 1 || input < 3) {

					switch (input) {
					case 0:
							return 0;
							break;

					case 1:
						cout << "Check " << endl;
						puzzlefunction.CheckOnePuzzle(puzzlecontainer, PUZZLESIZE);
						break;

					case 2:
						puzzlefunction.CheckAllPuzzle(puzzlecontainer, PUZZLESIZE);
						//puzzlefunction.CheckAllPuzzle(puzzlecontainer, PUZZLESIZE);
						break;
					
					}

				}
				else {
					cout << "error input" << endl;

				}
			
		}
	}
}
int puzzlesizemenu() {
	while (1) {
		cout << "------------------------------------------------------------------------ " << endl;
		cout << "\t*Welcome to 15-puzzle *" << endl;
		cout << "\t* please enter the puzzle size *" << endl;
		cout << "\t* you can choose the  puzzle size from 2~4 *" << endl;
		cout << "\t[Enter 0 to exit]\n" << endl;
		cout << "------------------------------------------------------------------------ " << endl;
	
		file.fileEmpty(PUZZLEFILENAME);//prevent miss reading
		file.fileEmpty(SOLUTIONFILENAME);//prevent miss reading

		int input;
		cin >> input;
		if (cin.fail()) {
			cout << "*error input" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (input == 0) {
			//	cout << "see you" << endl;
				exit(0);
			}
			else {
				if (input >= 2 || input <= 4) {
					PUZZLESIZE = input;
					menu();
				}


				else {
					cout << "error input" << endl;

				}
			}
		}
	}
}

int main()
{
	time_t t;
	srand((unsigned)time(&t));
	
	puzzlesizemenu();
	//menu();
	vector<short*>::iterator iter = puzzlecontainer.begin();
	for (; iter != puzzlecontainer.end(); iter++)
	{
		delete[](*iter);
	}


}

