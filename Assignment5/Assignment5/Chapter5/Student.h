#pragma once
#include <iostream>
using namespace std;

// A class that contain a student information
class Student
{
private:
	string name;
	string gradeLevel;
	double GPA;
public:

	//default constructor
	Student();

	void setName(string newName);
	void setGradeLevel(string newGradeLevel);
	void setGPA(double newGPA);

	friend ostream& operator <<(ostream& outs, const Student& obj);
	friend bool operator ==(const Student& obj1, const Student& obj2);
	friend bool operator <(const Student& obj1, const Student& obj2);
};