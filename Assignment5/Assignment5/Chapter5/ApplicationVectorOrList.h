#pragma once
#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt, double startRange, double endRange);

//Precondition: create a class of List
//Postoncondition: pass in an int as the datatype for the list private 
class ApplicationVectorOrList
{
private:
	//creating list of integers
	list<int> data;
public:

	//default constructor
	ApplicationVectorOrList();

	//member function 
	void addIntegerContainer(int value);
	void deleteIntegerContainer(int value);

	void displayIntegersContainer();
	map<int, int> repeatedFreq() const;

	void displayFreq();
	void mainMenu();
};

