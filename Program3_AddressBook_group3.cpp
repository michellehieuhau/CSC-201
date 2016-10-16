//***********************************************************
// Group #3
// Date: 		10/6/16
// Version:     1.2
// Names: 		Jeremy, Madeline, Eddie, Hieu, Robert
// Inputs:		Entry lookup
// Outputs:		Record in address book that matches lookup
// Description:	This program allows a user to search for a
//				record in an address book by particular
//				categories (first name, last name, phone number,
//				address)
//
//***********************************************************

#include <iostream>
#include <fstream>

using namespace std;

void OpenFile(string, ifstream&);	// Opens file if available
bool GetRecord(ifstream&, string&, string&, string&, string&);	// Obtain record with given information
void PrintRecord(string, string, string, string);	// Prints out one record (name, phone, address)
string NormalizeString(string);	// Converts a string to uppercase
void TrimSpaces(string&);	// Remove leading and trailing spaces of a string
void PurgeLines(ifstream&, int);
void SearchRecord(ifstream&, string, char);	// Search for a record based on a given identifier
bool InvalidInput(string, char);	// Checks for invalid search

int main()
{
    string firstName, lastName, address, phone;
    string filename;
    ifstream inData;
    char searchOption;
    string searchFor;

    OpenFile(filename, inData);

	// Repeat asking for search identifier until told to exit
    do {
        cout << "Enter how you want to search... " << endl;
        cout << "(F)irst name, (L)ast name, (A)ddress, (P)hone, e(X)it: ";
        cin >> searchOption;

        // Remove newline character from input
        cin.ignore(100, '\n');
        searchOption = toupper(searchOption);

		// Search for record if chosen, otherwise end program
		switch (searchOption) {
            case 'F':
            	searchFor = "first name";
                SearchRecord(inData, searchFor, searchOption);
                break;
            case 'L':
                searchFor = "last name";
                SearchRecord(inData, searchFor, searchOption);
                break;
            case 'A':
                searchFor = "address";
                SearchRecord(inData, searchFor, searchOption);
                break;
            case 'P':
                searchFor = "phone number";
                SearchRecord(inData, searchFor, searchOption);
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }
    } while (searchOption != 'X');

    return 0;
}

//***********************************************************
// Open File Function
// Asks for a file name to open until existing file is entered
//***********************************************************
void OpenFile(string filename, ifstream& inData)
{
    do {
        cout << "Enter file name to open: ";//prompt user input
        cin >> filename;

        inData.open(filename.c_str());//open file by converting user input to c_string and using it as argument in .open function
        if (!inData)
            cout << "File not found!" << endl;

    } while (!inData);// Keeping repeating user prompt while ifstream
    //variable inData is not valid i.e. no valid input file associated with the variable
}

//*********************************************************************
// Search for Record Function
// Searches for a record in address book based on user choice of search
//*********************************************************************
void SearchRecord(ifstream& inData, string searchFor, char searchOption)
{
    string searchName;
    string firstName, lastName, phone, address;
    string normalSearchName, normalRecord;

	// Ask for proper option to search for until valid
	// If phone number, display proper input format
	do
	{
		cout << "Enter " << searchFor << " to search for: ";
		if (searchOption=='P')
			cout << "\rEnter " << searchFor << " to search for using "
				 << "(XXX) XXX-XXXX: ";
		getline(cin, searchName);
	} while (!InvalidInput(searchName, searchOption));

	normalSearchName = NormalizeString(searchName);

    // Loop through all records in the file
    // Set record to be compared
    while (GetRecord(inData, firstName, lastName, phone, address))
    {
    	switch (searchOption)
    	{
    		case 'F':
    			normalRecord = firstName;
    			break;
    		case 'L':
    			normalRecord = lastName;
    			break;
    		case 'A':
    			normalRecord = address;
    			break;
    		case 'P':
    			normalRecord = phone;
    			break;
		}
		// Convert retrieved string to all uppercase
        normalRecord = NormalizeString(normalRecord);

        if (normalRecord == normalSearchName) // Requested name matches
            break;
    }

    // Matching name was found before the end of the file
    if (inData){
        cout << "Record found: " << endl;
        PrintRecord(firstName, lastName, phone, address);
    }
    else    // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}

//*********************************************************************
// Get a Record Function
// Read all elements of an address book entry from a given file
// Return true if successful, false otherwise (Based on stream state)
//*********************************************************************
bool GetRecord(ifstream& inData,
               string& firstName, string& lastName,
               string& phone, string& address)
{

    getline(inData, firstName, ','); //read the first line and it stops when it reaches ','character
    TrimSpaces(firstName);

    getline(inData, lastName, ',');//read the first line and it stops when it reaches ','character
    TrimSpaces(lastName);

    getline(inData, phone, '\n');//read the first line and it stops when it reaches newline character
    TrimSpaces(phone);

    getline(inData, address);
    TrimSpaces(address);

    return inData;
}

//*********************************************************************
// Print a Record Function
// Given all the elements of an address book entry, print the results
//*********************************************************************
void PrintRecord(string firstName, string lastName,
                 string phone, string address)
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
}

//*********************************************************************
// Normalize String Function
// Convert passed string to all upper case and return result
//*********************************************************************
string NormalizeString(string str)
{
    string nString = str;
    int i;

    for (i = 0; i < str.size(); i++)
    {
        nString[i] = toupper(str[i]);
    }

    return nString;
}

//*********************************************************************
// Trim Spaces Function
// Remove any leading or trailing spaces from given string
//*********************************************************************
void TrimSpaces(string& str)
{
    int index;

    index = str.find_first_not_of(" \t");
    //Find absence of character in string
//Searches for the first character in the object which is not part of string and returns its position.
    str.erase(0, index);

    index = str.find_last_not_of(" \t");
    if (string::npos != index)
        str.erase(index + 1);
}

//*********************************************************************
// Purge Lines Function
// **Not used**
// Read and discard a specified number of lines from a given file
//*********************************************************************
void PurgeLines(ifstream& inData, int numLines)
{
    string buffer;

    for (int i = 0; i < numLines; i++)
        getline(inData, buffer, '\n');
}

//*********************************************************************
// Invalid Input Function
// Checks validity of input based on which search option was chosen
//*********************************************************************
bool InvalidInput(string searchName, char searchOption)
{
	int letter=0;
	switch (searchOption)
	{
		case 'F': case 'L':
			// Check input is only characters
			for (int i=0; i<searchName.length(); i++)
				if (!isalpha(searchName[i]))
				{
					cout << "Invalid name. Please enter a proper name.\n";
					return false;
				}
			break;
		case 'A':
			// Checks for use of at least one letter
			for (int i=0; i<searchName.length(); i++)
			{
				if (isalpha(searchName[i])) //isalpha() check the input is alphabetic
					letter++;
			}
			if (letter==0)//if the input has no letter
			{
				cout << "Invalid address. Please enter at least a street.\n";
				return false;
			}
			break;
		case 'P':
			// Check for proper punctuation of phone number
			if (searchName.length() != 14 || searchName[9]!='-' ||
				searchName[0]!='(' || searchName[4]!=')' || searchName[5]!=' ')
			{
				cout << "Invalid phone number. Please enter in the proper form.\n";
				return false;
			}
			// Check rest of input is only numbers
			for (int i=0; i < 14; i++)
			{
				if (i==0 || i==4 || i==5 || i==9)
					continue;
				if (!isdigit(searchName[i]))
				{
					cout << "Invalid phone number. Please enter numbers.\n";
					cin.ignore(100, '\n');
					return false;
				}
			}
			break;
	}
	return true;
}
