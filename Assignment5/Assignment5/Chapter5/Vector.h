#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include"Student.h"
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt, double startRange, double endRange);

//Precondition: create a class of Vector
//Postoncondition: pass in the student class in my private vector
class Vector
{
private:
	vector<Student> data;
public: 

	//default constructor 
	Vector();

	void clearData();
	void resizeData();
	void reserveData();
	void readFromFile(string& fileName);

	void closeFile(string& filename);
	void popBackElement();
	void printFrontElement();
	void printBackElement();
	void lookForIndex();

	//member function to get the memory address and manipulate
	void beginIterator();
	void endIterator();
	void beginEndIterator();

	void reverseBeginIterator();
	void reverseEndIterator();
	void reverseBeginAndEndIterator();

	void eraseIterator();
	void eraseRangeIterator();
	void insertIterator();

	void swapVector();
	void sortVector();
	void mainMenu();
};
