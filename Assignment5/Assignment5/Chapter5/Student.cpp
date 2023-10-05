#include "Student.h"

//************************************** Constructor **********************************//

//Default constructor
Student::Student() : name("unknown"), gradeLevel("unknown"), GPA(0.0) {}

//************************************** Mutator ***************************************//

//Precondition: string name parameter
//Postcondition: set the name attribute
void Student::setName(string newName)
{
	name = newName;
}

//Precondition: string name parameter
//Postcondition: set the gradeLevel attribute
void Student::setGradeLevel(string newGradeLevel) 
{
	gradeLevel = newGradeLevel;
}

//Precondition: string name parameter
//Postcondition: set the GPA attribute
void Student::setGPA(double newGPA) 
{
	GPA = newGPA;
}

//*********************************** Overload Operator *********************************//

//Precondition: a ostream object and a Student object
//Postcondition: return an object that use for display 
ostream& operator <<(ostream& outs, const Student& obj) 
{
	outs << obj.name << ", " << obj.gradeLevel << ", " << obj.GPA;
	return outs;
}

//Precondition: 2 Student objects
//Postcondition: return true if equal, otherwise return false
bool operator ==(const Student& obj1, const Student& obj2) 
{
	if ((obj1.GPA == obj2.GPA) && (obj1.gradeLevel == obj2.gradeLevel) && (obj1.name == obj2.name))
		return true;
	else
		return false;
}

//Precondition: 2 Student objects
//Postcondition: return true if lesser than, otherwise return false
bool operator <(const Student& obj1, const Student& obj2) 
{
	if (obj1.name < obj2.name)
		return true;
	else
		return false;
}