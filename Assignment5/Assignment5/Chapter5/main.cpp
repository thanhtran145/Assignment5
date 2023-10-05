// Name: Thanh Tran
// Date: 09/20/2023
// Desciption: Chapter 4 - Assignments 4

//Credit:
//Joe Bryant& Erik Santana 
//Saul Merino & John Kim 
//Otoniel Torres Bernal
//Christian Hernandez

#include<iostream>
#include"input (1).h"
#include"Vector.h"
#include"List.h"
#include"ApplicationVectorOrList.h"
using namespace std;

// Function Prototypes
void vector_menu();
void list_menu();
void application_menu();

// Main Function
int main()
{
	// Main Menu and Options
	do
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 5: Vector and List Container by Thanh Tran(9/28/2023)";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1> Vector container";
		cout << "\n\t\t2> List container";
		cout << "\n\t\t3> Application using Vector and/or List container";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 3))
		{
		case 0: exit(1); break;
		case 1: vector_menu(); break;
		case 2: list_menu(); break;
		case 3: application_menu(); break;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//Precondition: NA
//Postcondition: call the sub-menu
void vector_menu() 
{
	Vector menu;
	menu.mainMenu();
}

//Precondition: NA
//Postcondition: call the sub-menu
void list_menu() 
{
	List menu;
	menu.mainMenu();
}

//Precondition: NA
//Postcondition: call the sub-menu
void application_menu() 
{
	ApplicationVectorOrList menu;
	menu.mainMenu();
}
