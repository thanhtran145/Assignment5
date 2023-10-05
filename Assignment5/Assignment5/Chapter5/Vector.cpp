#include "Vector.h"

//********************************* Constructor *****************************//

// default constructor
Vector::Vector()
{
    Student defaultCon;
}

//Precondition: NA
//Postcondition: clear the data vector (make it empty)
void Vector::clearData()
{
    //check if vector is empty
    if (data.empty()) {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //clearing the data
    data.clear();
    cout << "\n\t\tThe vector has been cleared.";
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: requests to reserve vector capacity be at least enough to contain n elements. Reallocation happens if there is need of more space.
void Vector::reserveData() 
{
    int reserveCapacity = inputInteger("\n\t\tEnter the capacity(1..100): ", 1, 100);
    data.reserve(reserveCapacity);

    cout << "\n\t\tThe vector has been reserved " << reserveCapacity << " elements.";
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: resizes the container so that it contains n(n will be our output) elements.
void Vector::resizeData()
{
    int resizingVecSize = inputInteger("\n\t\tEnter the new size(1..100): ", 1, 100);

    //resizing the vector to hold this size
    data.resize(resizingVecSize);
    cout << "\n\t\tThe vector has been resized to " << resizingVecSize << " elements.";
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: a sring file name parameter
//Postcondition: use ifstream to read, open the text, push_back the information, then print it out 
void Vector::readFromFile(string& fileName)
{
    ifstream readFile;
    string theName, theGradeLevel, theGPA;
    Student newStudent;

    //open the file
    readFile.open(fileName);
    //while it is not the end of hte file

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

        //push back the elements you read (getting the setters)
        data.push_back(newStudent);
    }

    cout << "\n\t\tThe vector now has " << data.size() << " elements.\n\n";
    for (int i = 0; i < data.size(); i++) 
    {
        cout << "\t\t[" << i << "]: " << data[i] << endl;
    }

    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: a sring file name parameter
//Postcondition: close the file
void Vector::closeFile(string& filename)
{
    ifstream readFile;

    //open the file
    readFile.open(filename);

    //closing the file
    readFile.close();
}

//Precondition: NA
//Postcondition: check if data empty,if not popping back the last element using pop_back()
void Vector::popBackElement()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }

    cout << "\n\t\tElement, ["<<data.size() -1 <<"] : " << data.back() << ", has been removed from the vector.";

    //pop back the last element (removed)
    data.pop_back();
    cout << "\n\n\t\tThe vector now has " << data.size() << " elements.\n\n";

    // Display the values in the vector, already read the file
    for (int i = 0; i < data.size(); i++) 
    {
        cout << "\t\t[" << i << "]: " << data[i] << "\n";
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: check if empty first, if not then look for the front element, use .front()
void Vector::printFrontElement()
{
    //check if vector is empty
    if (data.empty())
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tThe element from the from of the vector: [0] " << data.front();
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: check if empty first, if not then look for the back element, use .back()
void Vector::printBackElement()
{
    //check if vector is empty
    if (data.empty())
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }

    cout << "\n\t\tThe element from the back of the vector: ["<<data.size()-1<<"] " << data.back();
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//postcondition: returns a reference to the element at position n in the vector
void Vector::lookForIndex()
{
    //check if vector is empty, if empty, send a warning
    if (data.empty()) {
        cout << "\n\t\tThe vector is empty.\n\n";

        system("pause");
        system("cls");
        return;
    }

    //get the range of the elements
    int index = data.size() - 1;
    cout << "\n\t\tEnter the index (0..." << index<< "): ";
    int option = inputInteger("", 0, index);

    cout << "\n\t\t\tvector.at(" << option << "): " << data[option];
    cout << "\n\t\t\tvector[" << option << "]: " << data[option];
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns an iterator pointing to the first element in the vector
void Vector::beginIterator()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }

    //getting the memory address of the first element and then pointing * to the value
    cout << "\n\t\tThe iterator referring to the first element: "<<&*data.begin() <<"("<< *data.begin()<<")";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns an iterator referring to the past-the-end element in the vector
void Vector::endIterator()
{
    //check if vector is empty, if empty, send a warning
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //getting the memory right after the last element
    Student* afterLastElement = data.data() + data.size();

    //getting the memeory address of the end
    cout << "\n\t\tThe iterator referring to the past-the-end element: " << afterLastElement;
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return iterator begin() and end() returns all elements in the vector
void Vector::beginEndIterator()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }
    cout << "\n\t\tUsing begin() and end(), the vector contains: ";

    //iterator that uses begin() and end()
    for (auto it = data.begin(); it != data.end(); ++it) 
    {
        cout << "\n\t\t\t"<< &*it<<" ("<< *it<<")";
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns a reverse iterator pointing to the last element in the vector
void Vector::reverseBeginIterator()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tThe reverse iterator pointing to the last element: " << &*data.rbegin() << "(" << *data.rbegin() << ")";
    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
void Vector::reverseEndIterator()
{
    //check if vector is empty
    if (data.empty()) {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    //calculate the address before the first element, - 1 so it can not get the front() elemen 
    Student* beforeFirstElement = &data.front() - 1; 

    //getting the reference of th end, have to get the previous element that is the end
    cout << "\n\t\tThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << beforeFirstElement;
    cout << "\n\n";

    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: use iterator rbegin() and rend() returns all elements in the vector
void Vector::reverseBeginAndEndIterator()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");
        system("cls");
        return;
    }

    cout << "\n\t\tUsing rbegin() and rend(), the vector contains reversed elements: ";

    //iterator that uses begin() and end() (memory address)
    for (auto it = data.rbegin(); it != data.rend(); ++it) 
    {
        cout << "\n\t\t\t" << &*it << " (" << *it << ")";
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return the removing from the vector a single element(using an iterator)
void Vector::eraseIterator()
{
    //check if vector is empty
    if (data.empty()) 
    {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }

    //start the iterator at beginning (the memory addresss)
    auto it = data.begin();

    if (it != data.end())
    {
        cout << "\n\t\tAn element after the begin iterator "<<&*it<< " has been removed.";
        //erase that single element
        data.erase(++it);
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return the removes from the vector a range of elements(using iterators)
void Vector::eraseRangeIterator()
{
    //check if vector is empty, if empty, send a warning
    if (data.empty()) {
        cout << "\n\t\tThe vector is empty.\n\n";
        system("pause");

        system("cls");
        return;
    }

    //start iterator at begin
    auto it = data.begin();
    auto it2 = prev(data.end());

    if (it != data.end()) 
    {
        cout << "\n\t\tAll elements starting at begin iterator " << &*it << " and going up to end iterator "<<&*it2<<" have been removed.";
        //erase the vector range (it = begin, it2 = end)
        data.erase(it,++it2);
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//precondition: NA
//postcondition: return an insert a new entry at the iterator.
void Vector::insertIterator()
{
    Student newStudentInformation;
    string newName;

    //check if vector is empty, if empty, then print the one thing in it 
    if (data.empty()) 
    {
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

        //insert it after the beginning, call the class function (setters) 
        //increment so it can be put after the beginning iterator
        data.insert(it, newStudentInformation);

        cout << "\n\t\tThe new element has been inserted after the begin iterator.";
        cout << "\n\n";
        system("pause");
        system("cls");
    }
    else 
    {
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

        //insert it after the beginning, call the class function (setters) 
        //increment so it can be put after the beginning iterator
        data.insert(++it, newStudentInformation);

        cout << "\n\t\tThe new element has been inserted after the begin iterator.";
        cout << "\n\n";
        system("pause");
        system("cls");
    }
}

//Precondition: NA
//Postcondition: return the content (exchange) of the container by another vector's content of the same type
void Vector::swapVector()
{
    //create a new vecotor that will hold the vector 1 data
    vector<Student> data2;

    cout << "\n\t\tvector (data2) is initially empty.";
    cout << "\n\n\t\tvector (data) is empty after swapped with vector (data2).";

    //swap the data, now data2 will have the data
    data.swap(data2);

    cout << "\n\n\t\tvector (data2) after swapped with vector (data).\n\n";

    // Display the values in the vector, already read the file
    for (int i = 0; i < data2.size(); i++) {
        cout << "\t\t[" << i << "]: " << data2[i] << endl;
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: return the vector in sorted
void Vector::sortVector()
{
    //check if vector is empty
    if (data.empty()) {
        cout << "\n\t\tThe vector is empty.\n\n";

        system("pause");
        system("cls");
        return;
    }

    //sort the data, by name
    sort(data.begin(), data.end());
    cout << "\n";

    for (int i = 0; i < data.size(); i++) 
    {
        cout << "\t\t[" << i << "]: " << data[i] << "\n";
    }

    cout << "\n\n";
    system("pause");
    system("cls");
}

//Precondition: NA
//Postcondition: display the main menu
void Vector::mainMenu()
{
	system("cls");

	char option;
    string readFileName = "input.dat";
    int index = 0;

	do 
    {
        cout << "\n\tVectors are sequence containers representing arrays that can change in size.\n";
        cout << "\n\t1> - Vector's member function";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
        cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
        cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
        cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
        cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
        cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
        cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
        cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
        cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
        cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector";
        cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
        cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
        cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first"
            "\n\t\t\t    element in the vector";
        cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
        cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
        cout << "\n\t\tP> erase(start_it, end_it) - Removes from the vector a range of elements(using iterators)";
        cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
        cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
        cout << "\n\t\tS> Sort - Sorts the vector.";
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
                reserveData();
            }
                break;
            case 'C': 
            {
                resizeData();
            }   
                break;
            case 'D': 
            {
                readFromFile(readFileName);
            }
                break;
            case 'E': 
            {
                popBackElement();
            }
                break;
            case 'F': 
            {
                printFrontElement();
            }
                break;
            case 'G': 
            {
                printBackElement();
            }
                break;
            case 'H': 
            {
                lookForIndex();
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
                swapVector();
            }
                break;
            case 'S': 
            {
                sortVector();
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
