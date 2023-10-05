#pragma once
#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<algorithm>
#include"Student.h"
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt, double startRange, double endRange);

//Precondition: create a class of List
//Postcondition: pass in the student class in my private list
class List
{
private:
	list<Student> data;
public:

	//default constructor
	List();

	// Public functions
	void clearData();
	void resizedData();
	void readFromFilePushFront(string& fileName);
	void popFrontElement();
	void printFrontElement();

	void readFromFilePushBack(string& fileName);
	void closeFile(string& filename);
	void popBackElement();
	void printBackElement();

	//member functions to get and manipulate the memory address 
	void beginIterator();
	void endIterator();
	void beginEndIterator();

	void reverseBeginIterator();
	void reverseEndIterator();
	void reverseBeginAndEndIterator();

	void eraseIterator();
	void eraseRangeIterator();
	void insertIterator();

	void swapList();
	void sortList();
	void mainMenu();
};

