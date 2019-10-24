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

long  Math::PossibleContiousRow(int puzzlesize, int num)
{
	long ContiousRow = num * factorial(puzzlesize * puzzlesize - puzzlesize - 1) / 2 * (puzzlesize - 1);
	return ContiousRow;
}

int Math::getContinousNumber(int puzzlesize)
{
	return 0;
}
