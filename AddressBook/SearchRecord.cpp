
#include <iostream>
#include <fstream>
#include <sstream>
#include "AddressBook.h"
#include "GetRecord.h"
#include "PrintRecord.h"
#include "ValidRecord.h"

using namespace std;

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Record with searched first name
// Asks user for first name, searches for records with given name
void SearchFirstName(ifstream& inData)
{
    string searchName;
    entryType record;
    string normalSearchName, normalFirstName;
    char choice;
    bool found = false;

	do
	{
		cout << "Enter first name to search for: ";
    	getline(cin, searchName);
	} while (!ValidName(searchName));

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

    // Loop through all records in the file
    while (GetRecord(inData, record))
	{
        normalFirstName = NormalizeString(record.name.firstName);   // Convert retrieved string to all uppercase

        if (normalFirstName == normalSearchName) { // Requested name matches
            PrintRecord(record);
            cout << "Is this the correct entry? (Y/N) ";
            cin >> choice;
            cin.ignore(100, '\n');
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
        }
    }

    // Matching name was found before the end of the file
    if (inData && found){
        cout << "Record found: " << endl;
        PrintRecord(record);
        cout << endl;
    }
    else if (!found)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Record with searched last name
// Asks user for last name, searches for records with given name
void SearchLastName(ifstream& inData)
{
    string searchName;
    entryType record;
    string normalSearchName, normalName;
    char choice;
    bool found = false;

	do
	{
		cout << "Enter last name to search for: ";
    	getline(cin, searchName);
	} while (!ValidName(searchName));

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

    // Loop through all records in the file
    while (GetRecord(inData, record))
	{
        normalName = NormalizeString(record.name.lastName);   // Convert retrieved string to all uppercase

        if (normalName == normalSearchName) { // Requested name matches
            PrintRecord(record);
            cout << "Is this the correct entry? (Y/N) ";
            cin >> choice;
            cin.ignore(100, '\n');
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
        }
    }

    // Matching name was found before the end of the file
    if (inData && found){
        cout << "Record found: " << endl;
        PrintRecord(record);
        cout << endl;
    }
    else if (!found)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Record with searched address
// Asks user for address, searches for records with given address
void SearchAddress(ifstream& inData)
{
    entryType record;
    AddressType searchAddress;
    AddressType normalSearchAddress;
    AddressType normalAddress;
    char choice;
    bool found = false;

	do
	{
		cout << "Enter street address to search for: ";
	    getline(cin, searchAddress.street);
	    cout << "Enter city: ";
	    getline(cin, searchAddress.city);
	    cout << "Enter state: ";
	    getline(cin, searchAddress.state);
	    cout << "Enter zip code: ";
	    getline(cin, searchAddress.zip);
	} while (!ValidAddress(searchAddress));

    normalSearchAddress.street = NormalizeString(searchAddress.street);     // Convert name to all uppercase
    normalSearchAddress.city = NormalizeString(searchAddress.city);
    normalSearchAddress.state = NormalizeString(searchAddress.state);
    normalSearchAddress.zip = NormalizeString(searchAddress.zip);

    // Loop through all records in the file
    while (GetRecord(inData, record))
	{
		normalAddress.street = NormalizeString(record.address.street);
        normalAddress.city = NormalizeString(record.address.city);
        normalAddress.state = NormalizeString(record.address.state);
        normalAddress.zip = NormalizeString(record.address.zip);

		// Requested name matches
        if (normalAddress.zip==normalSearchAddress.zip && normalAddress.state==normalSearchAddress.state &&
            normalAddress.city==normalSearchAddress.city && normalAddress.street==normalSearchAddress.street)
		{
            PrintRecord(record);
            cout << "Is this the correct entry? (Y/N) ";
            cin >> choice;
            cin.ignore(100, '\n');
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
        }
    }

    // Matching name was found before the end of the file
    if (inData && found){
        cout << "Record found: " << endl;
        PrintRecord(record);
        cout << endl;
    }
    else if (!found)   // End of file. Name not found.
    {
        cout << searchAddress.street << ", "
             << searchAddress.city << ", "
             << searchAddress.state << ", "
             << searchAddress.zip << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Record with searched phone number
// Asks user for phone number, searches for records with given phone number
void SearchPhone(ifstream& inData)
{
    string searchName;
    entryType record;
    int normalName;
    int normalSearchName;
    int sum;
    char choice;
    bool found = false;

	// Ask for phone until valid
	do
	{
		cout << "Enter phone number to search for in the format (XXX) XXX-XXXX: ";
    	getline(cin, searchName);
	} while (!ValidPhone(searchName));

	// Convert input string to integer
	stringstream(searchName.substr(searchName.find('(')+1,searchName.find(')'))) >> sum;
	normalSearchName = sum*10000000;
	stringstream(searchName.substr(searchName.find(')')+1,searchName.find('-'))) >> sum;
	normalSearchName += sum*10000;
	stringstream(searchName.substr(searchName.find('-')+1))>> sum;
	normalSearchName += sum;

    // Loop through all records in the file
    while (GetRecord(inData, record))
	{
		// Convert file phone string to integer
		normalName = record.phone.areaCode*10000000 + record.phone.prefix*10000 + record.phone.number;
        if (normalName == normalSearchName) { // Requested name matches
            PrintRecord(record);
            cout << "Is this the correct entry? (Y/N) ";
            cin >> choice;
            cin.ignore(100, '\n');
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
        }
    }

    // Matching name was found before the end of the file
    if (inData && found){
        cout << "Record found: " << endl;
        PrintRecord(record);
        cout << endl;
    }
    else if (!found)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Record with searched email, facebook, or twitter
// Asks user which social media to search, asks for social media to search for,
// searches for records with given social media input
void SearchSocialMedia(ifstream& inData)
{
    string searchName;
    entryType record;
    string normalSearchName, normalName;
    char choice;
    bool found = false;

	char mediaOption;

	do
	{
        cout << endl;
        cout << "Enter social media type... " << endl;
        cout << "(E)mail, (F)acebook, (T)witter, e(X)it: ";
        cin >> mediaOption;
        cin.ignore(100, '\n');
        mediaOption = toupper(mediaOption);

		switch (mediaOption) // Type of media to search for
		{
			case 'E':
				do
				{
					cout << "Enter email to search for: ";
			    	getline(cin, searchName);
				} while (!ValidMedia(searchName, mediaOption));

			    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

			    // Loop through all records in the file
			    while (GetRecord(inData, record))
				{
			        normalName = NormalizeString(record.media.email);   // Convert retrieved string to all uppercase

			        if (normalName == normalSearchName) { // Requested name matches
			            PrintRecord(record);
			            cout << "Is this the correct entry? (Y/N) ";
			            cin >> choice;
			            cin.ignore(100, '\n');
			            choice = toupper(choice);
			            cout << endl;

			            if (choice == 'Y') {
			                found = true;
			                break;
			            }
			        }
			    }
				break;
			case 'F':
				do
				{
					cout << "Enter facebook user to search for: ";
			    	getline(cin, searchName);
				} while (!ValidMedia(searchName, mediaOption));

			    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

			    // Loop through all records in the file
			    while (GetRecord(inData, record))
				{
			        normalName = NormalizeString(record.media.facebook);   // Convert retrieved string to all uppercase

			        if (normalName == normalSearchName) // Requested name matches
			        {
			            PrintRecord(record);
			            cout << "Is this the correct entry? (Y/N) ";
			            cin >> choice;
			            cin.ignore(100, '\n');
			            choice = toupper(choice);
			            cout << endl;

			            if (choice == 'Y') {
			                found = true;
			                break;
			            }
			        }
			    }
				break;
			case 'T':
				do
				{
					cout << "Enter twitter user to search for: ";
			    	getline(cin, searchName);
				} while (!ValidMedia(searchName, mediaOption));

			    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

			    // Loop through all records in the file
			    while (GetRecord(inData, record))
				{
			        normalName = NormalizeString(record.media.twitter);   // Convert retrieved string to all uppercase

			        if (normalName == normalSearchName) // Requested name matches4
			        {
			            PrintRecord(record);
			            cout << "Is this the correct entry? (Y/N) ";
			            cin >> choice;
			            cin.ignore(100, '\n');
			            choice = toupper(choice);
			            cout << endl;

			            if (choice == 'Y')
						{
			                found = true;
			                break;
			            }
			        }
			    }
				break;
			case 'X':
				return;
			default:
				cout << "Invalid option selected!" << endl;
				mediaOption='x';
				break;
		}
	} while (mediaOption=='x');

    // Matching name was found before the end of the file
    if (inData && found)
	{
        cout << "Record found: " << endl;
        PrintRecord(record);
        cout << endl;
    }
    else if (!found)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    // Clear file fail state and return to beginning
    inData.clear();
    inData.seekg(0);
}
