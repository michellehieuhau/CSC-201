
//***********************************************************
// Group #3
// Date: 		10/23/16
// Version:     1.0
// Names: 		Robert Foxwell, Hieu Hau,
//				Edward Hopkins, Madeline Navarro
// Inputs: 		Search record, Updated record, New record
// Outputs: 	Records in address book
// Description: Allows user to access address book file to
//				search for a record, edit an existing record,
//				delete a record, or add a new record
//
//***********************************************************

#include <iostream>
#include <fstream>
#include "AddressBook.h"
#include "GetRecord.h"
#include "PrintRecord.h"
#include "SearchRecord.h"
#include "AddRecord.h"
#include "ValidRecord.h"

using namespace std;

void OpenFile(string&, ifstream&);	// Opens a valid file
void MainMenu(ifstream&, string);	// Menu options: Add, Print, Search
void SearchMenu(ifstream&);			// Menu options: First name, last name, address, phone, social media

int main()
{
	ifstream fin;
	string fname;

	OpenFile(fname, fin);

	MainMenu(fin, fname);

	return 0;
}

//---------------------------------------------------------------------------
// FILE AND MENUS
//---------------------------------------------------------------------------

// Inputs: None
// Outputs: Opened input file stream and file name
// Asks user for valid file name and opens file
void OpenFile(string& filename, ifstream& inData)
{
	// Ask for file until valid
    do {
        cout << "Enter file name to open: ";
        cin >> filename;

        inData.open(filename.c_str());

        if (!inData)
            cout << "File not found!" << endl;

    } while (!inData);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream, File name
// Outputs: Menu choice - Add, Print, Search
// Asks user what to do and calls corresponding function
void MainMenu(ifstream& inData, string filename)
{
    char menuOption;

    do {
        cout << endl;
        cout << "Select an option..." << endl;
        cout << "(A)dd entry, (P)rint, (S)earch, e(X)it: ";
        cin >> menuOption;
        cin.ignore(100, '\n');
        menuOption = toupper(menuOption);

        switch (menuOption)
		{
            case 'A':
                AddEntry(inData, filename);
                break;
            case 'P':
                PrintAddressBook(inData);
                break;
            case 'S':
                SearchMenu(inData);
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }

        // Clear file fail state and return to beginning
        inData.clear();
        inData.seekg(0);

    } while (menuOption != 'X');
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Search type choice - First name, Last name, Address, Phone, Social Media
// Asks user how to search and calls corresponding function
void SearchMenu(ifstream& inData)
{
	char searchOption;

	do
	{
        cout << endl;
        cout << "Enter how you want to search... " << endl;
        cout << "(F)irst name, (L)ast name, (A)ddress, (P)hone, (S)ocial Media, e(X)it: ";
        cin >> searchOption;
        cin.ignore(100, '\n');
        searchOption = toupper(searchOption);

		switch(searchOption)
		{
            case 'F':
                SearchFirstName(inData);
                break;
            case 'L':
                SearchLastName(inData);
                break;
            case 'A':
                SearchAddress(inData);
                break;
            case 'P':
                SearchPhone(inData);
                break;
            case 'S':
                SearchSocialMedia(inData);
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
		}
	} while (searchOption!='X');
}
