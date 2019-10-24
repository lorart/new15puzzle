#include "math.h"
//**Lambda number*(number-1)*...*1
long Math::factorial(int number)
{
	long temp;
	if (number == 0 || number == 1) {
		temp = 1;
	}
	else {
		temp = number * factorial(number - 1);
	}
	return temp;
}

long  Math::PossibleContiousRow(int puzzlesize, int continousnum)
{
	long ContiousRow = continousnum * factorial(puzzlesize * puzzlesize - puzzlesize - 1) / 2 * (puzzlesize - 1);
	return ContiousRow;
}


int Math::getContinousNumber(short* sortarry,int puzzlesize)
{
	int continousnum = 0;
	for (int i = 1; i < (puzzlesize* puzzlesize-puzzlesize); i++)
	{
		
		if ((sortarry[i] + puzzlesize - 1) == sortarry[i + puzzlesize - 1]) {
			continousnum++;
		}
	}
	cout << "continousnum= " << continousnum << endl;
	return continousnum;
}

short* Math::bubblesort(short* temparry,int PUZZLESIZE)
{
	short *sortarry= new short[PUZZLESIZE* PUZZLESIZE];
	for (int i = 0; i < PUZZLESIZE* PUZZLESIZE; i++)
	{
		sortarry[i] = temparry[i];
	}
	for (int i = 0; i < PUZZLESIZE* PUZZLESIZE; i++) {
		for (int j = 0; j < PUZZLESIZE * PUZZLESIZE - i - 1; j++) {
			if (sortarry[j] > sortarry[j + 1]) {
				int t = sortarry[j];
				sortarry[j] = sortarry[j + 1];
				sortarry[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < PUZZLESIZE * PUZZLESIZE; i++)
	{
		cout << sortarry[i] << endl;
	}
	return sortarry;
}
