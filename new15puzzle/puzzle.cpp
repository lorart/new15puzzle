#include "puzzle.h"
#include "file.h"
#include <time.h> 
using namespace std;



void Puzzlefunciton::printPuzzle(short* puzzle, int PUZZLESIZE) {
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		for (int j = 0; j < PUZZLESIZE; j++)
		{

			cout << puzzle[i* PUZZLESIZE+j] << ' ';
		}
		cout << '\n' << endl;
	}

};
void Puzzlefunciton::enterManually(int PUZZLESIZE) {
	cout << "* Please enter " << PUZZLESIZE * PUZZLESIZE - 1 << " numbers from 1-20.Do not enter one number twice *" << endl;;
	int vaildnumber = 0;

	short temp;
	short* temparry = new short[PUZZLESIZE * PUZZLESIZE];
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		for (int j = 0; j < PUZZLESIZE; j++)
		{
			temparry[i * PUZZLESIZE + j]=0;
		//	cout << temparry[i * PUZZLESIZE + j] << ' ';
		}
		//cout << '\n' << endl;
	}
	//short temparry[PUZZLESIZE * PUZZLESIZE] = { 0 };

	while (vaildnumber < PUZZLESIZE * PUZZLESIZE - 1)
	{
		bool checkrepet = 0;
		if (temparry[0] == 0) {

			//cout << "input first number" << endl;
			cin >> temp;
			if (cin.fail()) {
				cout << "not a number,please try again" << endl;
				//cin.sync();
				cin.clear();
				cin.ignore();
			}
			else {
				if (temp <= 20 && temp > 0) {
					temparry[0] = temp; vaildnumber++;
					//	cout << "" << temparry[0];
				}
				else {
					cout << "please input another number" << endl;
				}
			}

		}
		else {
			//	cout << "vaildnumber is" << vaildnumber <<endl;
			//	cout << "input next number" << endl;
			cin >> temp;
			if (cin.fail()) {
				cout << "not a number,please try again" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				for (int j = 0; j < vaildnumber; j++)
				{
					if (temp == temparry[j] || temp <= 0 || temp > 20) {
						checkrepet = 1;
					}
				}
				if (checkrepet == 0) { vaildnumber++; temparry[vaildnumber - 1] = temp; }
				else {
					cout << "please input another number" << endl;
				}
			}
		}
	}
	

	
	ofstream puzzlefile;
	puzzlefile.open(PUZZLEFILENAME, ios::app);
	puzzlefile << 1;
	puzzlefile << "\n";
	puzzlefile.close();
	writeArrayToFile(PUZZLEFILENAME, temparry,PUZZLESIZE);
	delete[] temparry;
	
}
void Puzzlefunciton::createRandomArray(int PUZZLESIZE) {
	
	
	int startramdom = 1;
	int endrandom = 20;
	int vaildnumber = 0;
	short temp;
	short* temparry = new short[PUZZLESIZE * PUZZLESIZE];
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		for (int j = 0; j < PUZZLESIZE; j++)
		{
			 temparry[i * PUZZLESIZE + j] = 0;
		}
	}

	while (vaildnumber < PUZZLESIZE * PUZZLESIZE - 1)
	{
		bool checkrepet = 0;
	
		temp = (short)((rand() % (endrandom - startramdom + 1)) + startramdom);
		for (int j = 0; j < vaildnumber; j++)
		{
			if (temp == temparry[j]) {
				checkrepet = 1;
			}
		}
		if (checkrepet == 0) { vaildnumber++; temparry[vaildnumber - 1] = temp; }
		else {}
	}
		
		printPuzzle(temparry, PUZZLESIZE);
		writeArrayToFile(PUZZLEFILENAME, temparry, PUZZLESIZE);
		cout << '\n' << endl;
		delete[] temparry;
	
}

//identify possible row and column
void Puzzlefunciton::CheckOnePuzzle(vector<short*>& puzzlecontainer, int PUZZLESIZE) {
	cout << "CheckOnePuzzle" << endl;
	//short temparry[PUZZLESIZE * PUZZLESIZE] = { NULL };
	short* temparry = new short[PUZZLESIZE * PUZZLESIZE];

	//cout << "puzzlecontiner.size()" << puzzlecontainer.size() << endl;
	for (int i = 0; i < puzzlecontainer.size(); i++)
	{

		//	cout << "puzzlecontainer=" << (puzzlecontainer[i])[0] << endl;
		for (int j = 0; j < PUZZLESIZE * PUZZLESIZE; j++)
		{
			if (j % PUZZLESIZE == 0) { cout << ' ' << endl; }
			temparry[j] = (puzzlecontainer[i])[j];
			cout << temparry[j] << ' ';
		}
		cout << "\n" << endl;

		cout << "row=:" << checkRow(temparry, PUZZLESIZE) << endl;
		cout << "Column=:" << checkColumn(temparry, PUZZLESIZE) << endl;
		cout << "ReverseRow:" << checkReverseRow(temparry, PUZZLESIZE) << endl;
		cout << "ReverseColum:" << checkReverseColum(temparry, PUZZLESIZE) << endl;

		short* checkpuzzlearry = new short[4];
		checkpuzzlearry[0] = checkRow(temparry, PUZZLESIZE);
		checkpuzzlearry[1] = checkColumn(temparry, PUZZLESIZE);
		checkpuzzlearry[2] = checkReverseRow(temparry, PUZZLESIZE);
		checkpuzzlearry[3] = checkReverseColum(temparry, PUZZLESIZE);


		cout << "2ReverseColum:" << CheckTwoThreePuzzle(puzzlecontainer[i], PUZZLESIZE, 2) << endl;
		//cout << "2ReverseColum:" << CheckTwoThreePuzzle(puzzlecontainer[i], PUZZLESIZE, 3) << endl;
	
		writeSingleArrayToFile(SOLUTIONFILENAME, temparry, 1,PUZZLESIZE);
		writeColumToFile(SOLUTIONFILENAME, checkpuzzlearry);





		cout << "\n" << endl;
		delete[] checkpuzzlearry;
	}
	delete[] temparry;
	
	
}

//identify all possible row and column
void Puzzlefunciton::CheckAllPuzzle(vector<short*>& puzzlecontainer, int PUZZLESIZE) {
	for (int i = 0; i < puzzlecontainer.size(); i++)
	{	
		int continousN= Math::getContinousNumber(Math::bubblesort(puzzlecontainer[i], PUZZLESIZE), PUZZLESIZE);
		//PossibleContiousRow(continousN, PUZZLESIZE);
		printPuzzle(puzzlecontainer[i], PUZZLESIZE);
	    cout <<"row ="<< Math::PossibleContiousRow(continousN, PUZZLESIZE)<<endl;
		cout << "column =" << Math::PossibleContiousRow(continousN, PUZZLESIZE) << endl;
		cout << "reverse row =" << Math::PossibleContiousRow(continousN, PUZZLESIZE) << endl;
		cout << "reverse colum=" << Math::PossibleContiousRow(continousN, PUZZLESIZE) << endl;
		cout << "\n" << endl;
		cout<<"(total for row & column, including reverse, in this configuration)" << endl;
		cout << "2 =" << 1 << endl;
		cout << "3 =" << 1 << endl;
		cout << "4 =" << 1<< endl;
		cout << "(total for row and column, including reverse, for all valid turns)" << endl;
		int TwocontinousN = TwoContinous::getContinousNumber(Math::bubblesort(puzzlecontainer[i], PUZZLESIZE), PUZZLESIZE);
		cout << "2 =" << Math::PossibleContiousRow(TwocontinousN, PUZZLESIZE) * 4 << endl;
		
		if(PUZZLESIZE>=3){
			int ThreecontinousN = ThreeContinous::getContinousNumber(Math::bubblesort(puzzlecontainer[i], PUZZLESIZE), PUZZLESIZE);
			cout << "3 =0" << Math::PossibleContiousRow(ThreecontinousN, PUZZLESIZE) * 4 << endl;
		}
		else { cout << "3 =0" << endl;
		}
		
		
		if (PUZZLESIZE>=4) {
			int FourcontinousN = FourContinous::getContinousNumber(Math::bubblesort(puzzlecontainer[i], PUZZLESIZE), PUZZLESIZE);
			cout << "4 =" << Math::PossibleContiousRow(FourcontinousN, PUZZLESIZE)*4 << endl;
		}
		else {
			cout << "4 =0" << endl;
		}




		writeSingleArrayToFile(SOLUTIONFILENAME, puzzlecontainer[i], 1, PUZZLESIZE);
		
	}

}


int Puzzlefunciton::CheckTwoThreePuzzle(short* temparry, int PUZZLESIZE, int num)
{
	int ContinousRow = 0;
	short** puzzle = new short* [PUZZLESIZE];
	for (int row = 0; row < PUZZLESIZE; row++)
	{
		puzzle[row] = new short[PUZZLESIZE];

	}


	for (int row1 = 0; row1 < (PUZZLESIZE); row1++)
	{
		for (int column1 = 0; column1 < (PUZZLESIZE); column1++) {
			puzzle[row1][column1] = temparry[row1 * (PUZZLESIZE)+column1];
			//cout << "puzzle[row][column]=" << puzzle[row1][column1] << "     row=" << row1 << " column=" << column1 << endl;
		}

	}

	//check ContinousRow
	for (int row = 0; row < (PUZZLESIZE - 1); row++)
	{
		for (int littlerow = 0; littlerow < (PUZZLESIZE - num + 1); littlerow++)
		{
			cout << "*" << endl;
			int check = 0;
			int position = littlerow;
			for (int column = 0; column < ( num - 1); column++)
			{
				cout << row << ' ' << column << ' ' << "puzzle[row][column] =" << puzzle[row][column] << endl;
				cout << row << ' ' << column + 1 << ' ' << "puzzle[row][column +1] =" << puzzle[row][column + 1] << endl;
				if (puzzle[row][column] == (puzzle[row][column + 1] - 1))
					check++;
				position++;
			}



				
				if (check == num - 1) {
					ContinousRow++;
				}
		}
		
			for (int littlerow = 0; littlerow < (PUZZLESIZE - num - 1); littlerow++) {

				{
					int check = 0;
					for (int column = 1; column < (num - 1); column++)
					{

						if (puzzle[row][column] == ((puzzle[row][column +1] -1)))
						
							check++;
						

						
						if (check == num - 1) {
							ContinousRow++;
						}

					}
				}
			}


			

		}

		return ContinousRow++;
	}
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		delete puzzle[i];
	}
	delete[] puzzle;
}
	



//***pointer to pointer
int Puzzlefunciton::checkRow(short* temparry, int PUZZLESIZE) {
	int unContinousRow = 0;

	short** puzzle = new short* [PUZZLESIZE];
	for (int row = 0; row < PUZZLESIZE; row++)
	{
		puzzle[row] = new short[PUZZLESIZE];

	}
	for (int row1 = 0; row1 < (PUZZLESIZE); row1++)
	{
		for (int column1 = 0; column1 < (PUZZLESIZE); column1++) {
			puzzle[row1][column1] = temparry[row1 * (PUZZLESIZE)+column1];
			//	cout << "puzzle[row][column]=" << puzzle[row1][column1] << "     row=" << row1 << " column=" << column1 << endl;
		}

	}

	//check ContinousRow
	for (int row = 0; row < (PUZZLESIZE); row++)
	{
		for (int column = 1; column < (PUZZLESIZE); column++)
		{
			bool ContinousrowCheck = 1;//1:is continous row 0:is not
			/*cout << "position= " << row << ' ' << column << endl;
			cout << "position-1= " << row << ' ' << column - 1 << endl;
			cout << "************puzzle[row][column]=" << puzzle[row][column] << endl;
			cout << "********(puzzle[row - 1][column]) = " << (puzzle[row ][column - 1]) << endl;*/
			if (puzzle[row][column] != ((puzzle[row][column - 1] + 1)))
			{
				ContinousrowCheck = 0;
				unContinousRow++;

				break;
			}

		}
	}
	//cout << "ContinousRow=" << (PUZZLESIZE - 1) - unContinousRow << endl;

	for (int i = 0; i < PUZZLESIZE; i++)
	{
		delete puzzle[i];
	}
	delete[] puzzle;
	return (PUZZLESIZE)-unContinousRow;
}

//***pointer to pointer
int Puzzlefunciton::checkColumn(short* temparry, int PUZZLESIZE)
{
	int unContinousColumn = 0;

	short** puzzle = new short* [PUZZLESIZE];
	for (int row = 0; row < PUZZLESIZE; row++)
	{
		puzzle[row] = new short[PUZZLESIZE];

	}
	for (int row1 = 0; row1 < (PUZZLESIZE); row1++)
	{
		for (int column1 = 0; column1 < (PUZZLESIZE); column1++) {
			puzzle[row1][column1] = temparry[row1 * (PUZZLESIZE)+column1];
			//	cout << "puzzle[row][column]=" << puzzle[row1][column1] << "     row=" << row1 << " column=" << column1 << endl;
		}

	}

	//check ContinousColumn
	for (int row = 0; row < (PUZZLESIZE); row++)
	{
		for (int column1 = 1; column1 < (PUZZLESIZE); column1++)
		{

			bool ContinousColumnCheck = 1;//1:is continous row 0:is not
			//cout << "position= " << column1 << ' ' << row << endl;
			//cout << "position-1= " << column1 - 1 << ' ' << row << endl;
			//cout << "************puzzle[row][column]=" << puzzle[column1][row] << endl;
			//cout << "********(puzzle[row - 1][column] ) = " << (puzzle[column1 - 1][row]) << endl;

			if (puzzle[column1][row] != ((puzzle[column1 - 1][row] + 1)))
			{
				ContinousColumnCheck = 0;
				unContinousColumn++;

				break;
			}

		}
	}
	//cout << "ContinousRow=" << (PUZZLESIZE - 1) - unContinousRow << endl;
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		delete puzzle[i];
	}
	delete[] puzzle;
	return (PUZZLESIZE)-unContinousColumn;
}

//***pointer to pointer
int Puzzlefunciton::checkReverseRow(short* temparry, int PUZZLESIZE)
{
	int unReverseContinousRow = 0;

	short** puzzle = new short* [PUZZLESIZE];
	for (int row = 0; row < PUZZLESIZE; row++)
	{
		puzzle[row] = new short[PUZZLESIZE];

	}
	for (int row1 = 0; row1 < (PUZZLESIZE); row1++)
	{
		for (int column1 = 0; column1 < (PUZZLESIZE); column1++) {
			puzzle[row1][column1] = temparry[row1 * (PUZZLESIZE)+column1];
			//	cout << "puzzle[row][column]=" << puzzle[row1][column1] << "     row=" << row1 << " column=" << column1 << endl;
		}

	}

	//check ReverseContinousRow
	for (int row = 0; row < (PUZZLESIZE); row++)
	{
		for (int column = 1; column < (PUZZLESIZE); column++)
		{
			bool ReverseContinousrowCheck = 1;//1:is continous row 0:is not
			/*cout << "position= " << row << ' ' << column << endl;
			cout << "position-1= " << row << ' ' << column - 1 << endl;
			cout << "************puzzle[row][column]=" << puzzle[row][column] << endl;
			cout << "********(puzzle[row - 1][column]) = " << (puzzle[row ][column - 1]) << endl;
			*/
			if ((puzzle[row][column] + 1) != ((puzzle[row][column - 1])))
			{
				ReverseContinousrowCheck = 0;
				unReverseContinousRow++;

				break;
			}

		}
	}
	//cout << "ContinousRow=" << (PUZZLESIZE - 1) - unContinousRow << endl;
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		delete[] puzzle[i];
	}
	delete[] puzzle;
	return (PUZZLESIZE)-unReverseContinousRow;

}

//***pointer to pointer
int Puzzlefunciton::checkReverseColum(short* temparry, int PUZZLESIZE)
{
	int unReverseColumn = 0;

	short** puzzle = new short* [PUZZLESIZE];
	for (int row = 0; row < PUZZLESIZE; row++)
	{
		puzzle[row] = new short[PUZZLESIZE];

	}
	for (int row1 = 0; row1 < (PUZZLESIZE); row1++)
	{
		for (int column1 = 0; column1 < (PUZZLESIZE); column1++) {
			puzzle[row1][column1] = temparry[row1 * (PUZZLESIZE)+column1];
			//	cout << "puzzle[row][column]=" << puzzle[row1][column1] << "     row=" << row1 << " column=" << column1 << endl;
		}

	}

	//check ContinousColumn
	for (int row = 0; row < (PUZZLESIZE); row++)
	{
		for (int column1 = 1; column1 < (PUZZLESIZE); column1++)
		{

			bool ReverseColumnCheck = 1;//1:is continous row 0:is not
			//cout << "position= " << column1 << ' ' << row << endl;
			//cout << "position-1= " << column1 - 1 << ' ' << row << endl;
			//cout << "************puzzle[row][column]=" << puzzle[column1][row] << endl;
			//cout << "********(puzzle[row - 1][column] ) = " << (puzzle[column1 - 1][row]) << endl;

			if ((puzzle[column1][row] + 1) != ((puzzle[column1 - 1][row])))
			{
				ReverseColumnCheck = 0;
				unReverseColumn++;

				break;
			}

		}
	}
	//cout << "ContinousRow=" << (PUZZLESIZE - 1) - unContinousRow << endl;
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		delete puzzle[i];
	}
	delete[] puzzle;
	return (PUZZLESIZE)-unReverseColumn;
}
