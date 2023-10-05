#include "List.h"

//************************************* Constructor *************************************//

//Defautl constructor
List::List()
{
	Student defaultCon;
}

//Precondition: NA
//Postcondition: clear the data list
void List::clearData()
{
    //check if list is empty, if empty, send a warning
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //clearing the data
    data.clear();
    cout << "\n\t\tThe list has been cleared.";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: resizes the container so that it contains n(n will be our output) elements.
void List::resizedData()
{
    int resizingVecSize = inputInteger("\n\t\tEnter the new size(1..100): ", 1, 100);
    //resizing the list to hold this size
    data.resize(resizingVecSize);
    cout << "\n\t\tThe list has been resized to " << resizingVecSize << " elements.";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: a string file name parameter
//Postcondition: use ifstream to read, open the text, push_front the information
void List::readFromFilePushFront(string& fileName)
{
    ifstream readFile;
    string theName, theGradeLevel, theGPA;
    Student newStudent;

    //open the file
    readFile.open(fileName);

    //while it is not the end of the file
    while (!readFile.fail()) 
    {
        //read until there is a comma encounter
        getline(readFile, theName, ',');
        newStudent.setName(theName);

        getline(readFile, theGradeLevel, ',');
        newStudent.setGradeLevel(theGradeLevel);

        getline(readFile, theGPA);
        newStudent.setGPA(stod(theGPA));

        //end of file, then don't push_back an extra element
        if (readFile.eof()) 
        {
            break;
        }
        //push front the elements you read (getting the setters)
        data.push_front(newStudent);
    }
    cout << "\n\t\tThe list now has " << data.size() << " elements.";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: check if data empty,if not popping back the front element using pop_front()
void List::popFrontElement()
{
    //check if list is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }
    cout << "\n\t\tFirst Element, ("<< data.front() << "), has been removed from the list.";

    //pop back the last element (removed)
    data.pop_front();
    cout << "\n\n\t\tThe list has " << data.size() << " elements.\n\n";

    // Display the values in the vector, already read the file
    for (auto& i : data) {
        cout << "\t\t" << i << " " << endl;
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: if empty first, if not then look for the front element, use .front()
void List::printFrontElement()
{
    //check if list is empty, if empty, send a warning
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }
    cout << "\n\t\tFirst element from the list is (" << data.front()<<").";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: a string file name parameter
//Postcondition: use ifstream to read, open the text, NOW push_back the information
void List::readFromFilePushBack(string& fileName)
{
    ifstream readFile;
    string theName, theGradeLevel, theGPA;
    Student newStudent;

    //open the file
    readFile.open(fileName);

    //while it is not the end of the file
    while (!readFile.fail()) 
    {
        //read until there is a comma encounter
        getline(readFile, theName, ',');
        newStudent.setName(theName);

        getline(readFile, theGradeLevel, ',');
        newStudent.setGradeLevel(theGradeLevel);

        getline(readFile, theGPA);
        newStudent.setGPA(stod(theGPA));

        //end of file, then don't push_back an extra element
        if (readFile.eof()) 
        {
            break;
        }

        //push front the elements you read (getting the setters)
        data.push_back(newStudent);
    }
    cout << "\n\t\tThe list now has " << data.size() << " elements.";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: a string file name parameter
//Postcondition: close the file
void List::closeFile(string& filename) 
{
    ifstream readFile;

    //open the file
    readFile.open(filename);

    //closing the file
    readFile.close();
}

//Precondition: NA
//Postcondition: check if empty first, if not then look for the back element, use .back()
void List::popBackElement()
{
    //check if list is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tFirst Element, (" << data.back() << "), has been removed from the list.";

    //pop back the last element (removed)
    data.pop_back();
    cout << "\n\n\t\tThe list has " << data.size() << " elements.\n\n";

    // Display the values in the vector, already read the file
    for (auto& i : data) 
    {
        cout << "\t\t" << i << " " << endl;
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: check if empty first, if not then look for the back element, use .back()
void List::printBackElement()
{
    //check if list is empty
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tLast element from the list is ("<< data.back()<<").";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns an iterator pointing to the first element in the list
void List::beginIterator()
{
    //check if list is empty, if empty, send a warning
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }
    //getting the memory address of the first element and then pointing * to the value
    cout << "\n\t\tThe iterator referring to the first element: " << &*data.begin() << "(" << *data.begin() << ")";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns an iterator referring to the past-the-end element in the vector
void List::endIterator()
{
    //check if list is empty, if empty, send a warning
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    auto it = data.end();

    //getting the memeory address of the end, have to get the previous element that is the end
    cout << "\n\t\tThe iterator referring to the past-the-end element: " << &it;
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return iterator begin() and end() returns all elements in the list
void List::beginEndIterator()
{
    //check if list is empty
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tUsing begin() and end(), the list contains: ";

    //iterator that uses begin() and end()
    for (auto it = data.begin(); it != data.end(); ++it) 
    {
        cout << "\n\t\t\t" << &*it << " (" << *it << ")";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns a reverse iterator pointing to the last element in the list
void List::reverseBeginIterator() 
{
    //check if list is empty
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tThe iterator referring the reverse first element: " << &*data.rbegin() << "(" << *data.rbegin() << ")";
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns a reverse iterator pointing to the theoretical element preceding the first element in the list
void List::reverseEndIterator() 
{
    //check if list is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    auto it = data.rend();

    //getting the reference of the end
    cout << "\n\t\tThe iterator referring to the reverse past-the-end element: " << &it;
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: use iterator rbegin() and rend() returns all elements in the list
void List::reverseBeginAndEndIterator() 
{
    //check if list is empty
    if (data.empty())
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tUsing rbegin() and rend(), the list contains reversed elements: ";

    //iterator that uses begin() and end() (memory address)
    for (auto it = data.rbegin(); it != data.rend(); ++it) \
    {
        cout << "\n\t\t\t" << &*it << " (" << *it << ")";
    }
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return the removing from the list a single element(using an iterator)
void List::eraseIterator() 
{
    //check if list is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //start the iterator at beginning (the memory addresss)
    auto it = data.begin();

    if (it != data.end()) 
    {
        cout << "\n\t\tAn element after the begin iterator " << &*it << " has been removed.";
        //erase that single element
        data.erase(it);
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}
//Precondition: NA
//Postcondition: return the removes from the list a range of elements(using iterators)
void List::eraseRangeIterator() 
{
    //check if vector is empty
    if (data.empty()) {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //start iterator at begin
    auto it = data.begin();
    auto it2 = prev(data.end());

    if (it != data.end()) 
    {
        cout << "\n\t\tAll elements starting at begin iterator " << &*it << " and going up to end iterator " << &*it2 << " have been removed.";
        //erase the vector range (it = begin, it2 = end)
        data.erase(it, ++it2);
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return an insert a new entry at the iterator.
void List::insertIterator() 
{
    Student newStudentInformation;
    string newName;

	cout << "\n\t\tEnter a new student name: ";
	getline(cin, newName);

	//call the setter to set the new name
	newStudentInformation.setName(newName);
	int newGradeLevel = inputInteger("\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);

	switch (newGradeLevel) 
    {
	    case 1: 
        {
		    newStudentInformation.setGradeLevel("Freshman");
	    }
		  break;
	    case 2: 
        {
		    newStudentInformation.setGradeLevel("Sophmore");
	    }
		  break;
	    case 3: 
        {
		    newStudentInformation.setGradeLevel("Junior");
	    }
		  break;
	    case 4: 
        {
		    newStudentInformation.setGradeLevel("Senior");
	    }
		     break;
	}

	double newGPA = inputDouble("\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);
	newStudentInformation.setGPA(newGPA);

	//start of the iterator
	auto it = data.begin();

	//insert it after the beginning
	data.insert(it, newStudentInformation);

	cout << "\n\t\tThe new element has been inserted after the begin iterator.";
	cout << "\n\n";
	system("pause");
	system("cls");
}

//Precondition: NA
//Postcondition: return the content (exchange) of the container by another list's content of the same type
void List::swapList() 
{
    //create a new list that will hold the list 1 data
    list<Student> data2;
    cout << "\n\t\tlist (data2) is initially empty.";
    cout << "\n\n\t\tlist (data) is empty after swapped with list (data2).";

    //swap the data, now data2 will have the data
    data.swap(data2);
    cout << "\n\n\t\tlist (data2) now has "<<data2.size()<<" element(s).\n\n";

    //display the values in the vector, already read the file
    for (auto& i : data2) 
    {
        cout << "\t\t" << i << " " << "\n";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return the list in sorted
void List::sortList() 
{
    //check if list is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe list is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tSorted list: ";
    //sort the data, by name
    data.sort();

    cout << "\n\n";
    for (auto& i : data) 
    {
        cout << "\t\t"<<&i<<" " << i << " " << "\n";
    }
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: display the menu
void List::mainMenu()
{
	system("cls");

	char option;
	string readFileName = "input.dat";
	int index = 0;

	do 
    {
        cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the.\n";
        cout << "\tsequence, and iteration in both directions.\n";
        cout << "\n\t2> - List container";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> clear() - Destroys all elements from the list";
        cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
        cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
        cout << "\n\t\tD> pop_front() - Deletes the first element";
        cout << "\n\t\tE> front() - Accesses the first element";
        cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
        cout << "\n\t\tG> pop_back() - Delete the last element";
        cout << "\n\t\tH> back() Accesses the last element";
        cout << "\n\t\tI> begin() - Returns an iterator refereing to the first element in the list";
        cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
        cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
        cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
        cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element"
            "\n\t\t\t     in the list";
        cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
        cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
        cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
        cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
        cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
        cout << "\n\t\tS> Sort - Sorts the list.";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        option = inputChar("\t\tOption: ", static_cast<std::string>("ABCDEFGHIJKLMNOPQRS0)"));

        switch (toupper(option)) 
        {
            case 'A': 
            {
                clearData();
            }
                break;
            case 'B': 
            {
                resizedData();
            }
                break;
            case 'C': 
            {
                readFromFilePushFront(readFileName);
            }
                break;
            case 'D': 
            {
                popFrontElement();
            }
                break;
            case 'E': 
            {
                printFrontElement();
            }
                break;
            case 'F': 
            {
                readFromFilePushBack(readFileName);
            }
                break;
            case 'G': 
            {
                popBackElement();
            }
                break;
            case 'H': 
            {
                printBackElement();
            }
                break;
            case 'I': 
            {
                beginIterator();
            }
                break;
            case 'J': 
            {
                endIterator();
            }
                break;
            case 'K': 
            {
                beginEndIterator();
            }
                break;
            case 'L': 
            {
                reverseBeginIterator();
            }
                break;
            case 'M': 
            {
                reverseEndIterator();
            }
                break;
            case 'N': 
            {
                reverseBeginAndEndIterator();
            }
                break;
            case 'O': 
            {
                eraseIterator();
            }
                break;
            case 'P': 
            {
                eraseRangeIterator();
            }
                break;
            case 'Q': 
            {
                insertIterator();
            }
                break;
            case 'R': 
            {
                swapList();
            }
                break;
            case 'S': 
            {
                sortList();
            }
                break;
            case '0': 
            {
            //closing the file
            closeFile(readFileName);
            return;
            }
        }
	} while (true);
}
