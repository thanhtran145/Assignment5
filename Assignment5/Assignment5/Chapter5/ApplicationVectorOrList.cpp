#include "ApplicationVectorOrList.h"

//*********************************** Constructor ***********************************//

// Default constructor
ApplicationVectorOrList::ApplicationVectorOrList(){}

//Precondition: an int value
//Postcondition: push back the values for every integer that was entered
void ApplicationVectorOrList::addIntegerContainer(int value){
    data.push_back(value);
    cout << "\n";
    system("pause");
    system("cls");
}

//Precondition: an int value
//Postcondition: check if it does not equal to the end, for loop through it and then erase the value
void ApplicationVectorOrList::deleteIntegerContainer(int value)
{
    //find the position, first getting the range from beginning to end
    //3rd argu has the value we are looking for to delete

    auto it = find(data.begin(), data.end(), value);

    // if statement cheking if its not at the end of the array(elements), keep checking
    if (it != data.end()) 
    {
        // loop through the container then use if statement to check if the it is equal to the element equals, if equal then erase it
        for (auto it = data.begin(); it != data.end();) 
        {
            //if the it is equal to the element
            if (*it == value) 
            {
                it = data.erase(it);
            }
            else 
            {
                ++it;
            }
        }
        cout << "\n\t\t" << value << " will be removed from the list.";
    }
    else 
    {
        cout << "\n\t\tlist does not contain " << value<<".";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return (display) the input integers 
void ApplicationVectorOrList::displayIntegersContainer()
{
    //check if list is empty, if empty, send a warning
    if (data.empty()) 
    {
        cout << "\n\t\tcontainer: empty\n\n";
        system("pause");
        system("cls");
        return;
    }
    cout << "\n\t\tcontainer: ";
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: a map that can get the frequency
//Postcondition: return the frequency
map<int, int> ApplicationVectorOrList::repeatedFreq() const
{
    //using map to get the key(value)
    map<int, int> repeated;

    //print the data values(going to be sorted)
    for (double i : data) 
    {
        //.count() is checking if it exits in the map container
        if (repeated.count(i)) 
        {
            //increment the number if seen more than ones
            repeated.at(i)++;
        }
        else 
        {
            //using .emplace to check if the value exits
            repeated.emplace(i, 1);
        }
    }
    return repeated;
}

//Precondition: displaying the information
//Postcondition: display the frequency
void ApplicationVectorOrList::displayFreq()
{
    //calling the repeatedFreq() functions to get how many times the number repeated
    map<int, int> display = repeatedFreq();
    for (auto& words : display) {
        //set the key to the value first is the key then second the value
        cout << "\n\t\t\t" << words.first << "\t" << words.second;
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: display the menu
void ApplicationVectorOrList::mainMenu()
{
	system("cls");
	char option;
	do 
    {
        beginning:
        cout << "\n\t3> Application using Vector and/or List container";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> Add an integer";
        cout << "\n\t\tB> Delete an integer";
        cout << "\n\t\tC> Display input integers";
        cout << "\n\t\tD> Display frequencies of integers";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        option = inputChar("\t\tOption: ", static_cast<std::string>("ABCD0"));

        switch (toupper(option)) 
        {
            case 'A': 
            {
                int value = inputInteger("\n\t\tAdd an integer: ");
                addIntegerContainer(value);
            }
                break;
            case 'B': 
            {
                int value = inputInteger("\n\t\tDelete an integer: ");
                deleteIntegerContainer(value);
            }
                break;
            case 'C': 
            {
                displayIntegersContainer();
            }
                break;
            case 'D': 
            {
                //check if list is empty, if empty, send a warning
                if (data.empty()) 
                {
                    cout << "\n\t\tcontainer: empty\n\n";
                    system("pause");
                    system("cls");
                    goto beginning;
                }
                cout << "\n\t\tcontainer: ";
                displayFreq();
            }
                break;
            case '0': 
            {
                return;
            }
        }
	} while (true);
}
