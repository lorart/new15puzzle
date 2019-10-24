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
	long PossibleContiousRow(int puzzlesize, int num);
	virtual int getContinousNumber(int puzzlesize);
};

//polymorphism
class TwoContinous :public Math
{
public:
	long PossibleContiousRow(int puzzlesize, int num);
};

class ThreeContinous :public Math
{
public:

	long PossibleContiousRow(int puzzlesize);
};

