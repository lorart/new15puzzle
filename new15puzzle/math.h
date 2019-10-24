#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "file.h"
#include <vector>
//#define PUZZLESIZE 4
class Math
{
public:
	long factorial(int number);
	long PossibleContiousRow(int puzzlesize, int Continousnum);
	virtual int getContinousNumber(short* sortarry, int puzzlesize);
	short* bubblesort(short* temparry, int PUZZLESIZE);
	
};

//polymorphism
class TwoContinous :public Math
{
public:
	int getContinousNumber(int puzzlesize);
};

class ThreeContinous :public Math
{
public:

	int getContinousNumber(int puzzlesize);
};

