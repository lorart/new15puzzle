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
	unsigned long long factorial(int number);
	unsigned long long  PossibleContiousRow(int continousnum, int puzzlesize);
	virtual unsigned long long getContinousNumber(short* sortarry, int puzzlesize);
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

