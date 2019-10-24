#include "file.h"
void File::writeColumToFile(string filename, short* puzzlcolum) {
	//check ok
	ofstream puzzlefile;

	puzzlefile.open(filename, ios::app);
	cout << "writing to file" << endl;

	puzzlefile << "row=" << puzzlcolum[0] << "\n" << endl;
	puzzlefile << "column= " << puzzlcolum[1] << "\n" << endl;
	puzzlefile << "reverse row=" << puzzlcolum[2] << "\n" << endl;
	puzzlefile << "reverse column=" << puzzlcolum[3] << "\n" << endl;
	puzzlefile << "\n" << endl;

	puzzlefile << "\n" << endl;
	puzzlefile.close();
};

void File::writeSingleArrayToFile(string filename, short* puzzle, bool singlePuzzle, int PUZZLESIZE)
{//check ok
	ofstream puzzlefile;

	puzzlefile.open(filename, ios::app);
	//cout << "writing to file" << endl;
	if (singlePuzzle == 1) {
		puzzlefile << "[single puzzle]" << endl;
	}
	else {
		puzzlefile << "[all possible puzzle]" << endl;
	}
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		for (int j = 0; j < PUZZLESIZE; j++) {
			puzzlefile << puzzle[i * PUZZLESIZE + j] << "  ";
		//	cout <<"puzzle[i * PUZZLESIZE + j]"<< puzzle[i * PUZZLESIZE + j] << endl;
			
		}
		puzzlefile << "\n" << endl;
	}
	puzzlefile << "\n" << endl;
	puzzlefile.close();
}

void File::writeArrayToFile(string filename, short* puzzle, int PUZZLESIZE)
{
	//test ok
	ofstream puzzlefile;

	puzzlefile.open(filename, ios::app);
	//cout << "writing to file" << endl;
	for (int i = 0; i < PUZZLESIZE; i++)
	{
		for (int j = 0; j < PUZZLESIZE; j++) {
			puzzlefile << puzzle[i * PUZZLESIZE + j] << "  ";
		}
		puzzlefile << "\n" << endl;
	}
	
	puzzlefile << "\n" << endl;
	puzzlefile.close();
}
//**overload
int File::readFile(string filename, vector<short*>& puzzlecontainer, int PUZZLESIZE) {

	ifstream puzzlefile;

	puzzlefile.open(filename, ios::in);
	if (!puzzlefile.is_open()) {
		cout << "there is no FILE" << endl;
		return 1;
	}
	else{ int ch; 
	ch = puzzlefile.get();
	if (puzzlefile.eof())
	{
		cout << "blank file" << endl;
		return 1;
	}
	
	else {
		int puzzlenumber= ch-48;
		cout << "puzzle number =" << puzzlenumber << endl;
		
		//puzzlefile >> puzzlenumber;
		//vector
		for (int k = 0; k < puzzlenumber; k++)
		{
			short* p = new short[PUZZLESIZE * PUZZLESIZE];
			//puzzlecontiner.push_back(&p);
			puzzlecontainer.push_back(p);
			for (int i = 0; i < PUZZLESIZE; i++)
			{
				for (int j = 0; j < PUZZLESIZE; j++) {

					puzzlefile >> p[i * PUZZLESIZE + j];
					//	cout<< "puzzle number =" << p[i* PUZZLESIZE+ j] << endl;
				}
			}

		}

		//cout << "read file" << endl;
		//cout << "puzzle number =" << puzzlenumber << endl;
		for (int i = 0; i < puzzlenumber; i++)
		{
			//cout << "puzzlecontainer=" << (puzzlecontainer[i])[0];

			for (int j = 0; j < (PUZZLESIZE * PUZZLESIZE); j++) {
				if ((j % PUZZLESIZE) == 0) { cout << "\n" << endl; }
				cout << (puzzlecontainer[i])[j] << " ";

			}


			cout << "\n" << endl;
		}
	}
	}

	puzzlefile.close();
	
	return 0;
}
void File::readFilewithOutPush(string filename, vector<short*>& puzzlecontainer, bool showfile, int PUZZLESIZE) {

	ifstream puzzlefile;

	puzzlefile.open(filename, ios::in);
	if (!puzzlefile.is_open()) {
		cout << "there is no TXT" << endl;
	}
	else {
		int puzzlenumber;
		puzzlefile >> puzzlenumber;
		//vector
		for (int k = 0; k < puzzlenumber; k++)
		{
			short* p = new short[PUZZLESIZE * PUZZLESIZE];
			//puzzlecontiner.push_back(&p);
			puzzlecontainer.push_back(p);
			for (int i = 0; i < PUZZLESIZE; i++)
			{
				for (int j = 0; j < PUZZLESIZE; j++) {

					puzzlefile >> p[i * PUZZLESIZE + j];
					//	cout<< "puzzle number =" << p[i* PUZZLESIZE+ j] << endl;
				}
			}

		}

		//cout << "read file" << endl;
		if (showfile == 1) {
			cout << "puzzle number =" << puzzlenumber << endl;
			for (int i = 0; i < puzzlenumber; i++)
			{
				//cout << "puzzlecontainer=" << (puzzlecontainer[i])[0];

				for (int j = 0; j < (PUZZLESIZE * PUZZLESIZE); j++) {
					if ((j % PUZZLESIZE) == 0) { cout << "\n" << endl; }
					cout << (puzzlecontainer[i])[j] << " ";

				}


				cout << "\n" << endl;
			}
		}
	}

	puzzlefile.close();
}
void File::fileEmpty(const string fileName)
{
	fstream file(fileName, ios::out);

}

