
#include <iostream>
#include <fstream>
#include "AddressBook.h"
#include "GetRecord.h"

using namespace std;

//---------------------------------------------------------------------------
// Inputs: Record
// Outputs: Printed full record
// Prints all record elements
void PrintRecord(entryType userRecord)
{
    cout << "Name: " << userRecord.name.firstName << " " << userRecord.name.lastName << endl;

    cout << "Phone: " << "(" << userRecord.phone.areaCode << ") "
                      << userRecord.phone.prefix << "-"
                      << userRecord.phone.number << endl;

    cout << "Address: " << userRecord.address.street << ", "
                        << userRecord.address.city << ", "
                        << userRecord.address.state << ", "
                        << userRecord.address.zip << endl;

    cout << "Email: " << userRecord.media.email << endl
    	 << "Facebook: " << userRecord.media.facebook << endl
    	 << "Twitter: " << userRecord.media.twitter << endl;
}

//---------------------------------------------------------------------------
// Inputs: Record
// Outputs: Printed brief record
// Prints full name and social media
void PrintBriefRecord(entryType userRecord)
{
    cout << "Name: " << userRecord.name.firstName << " " << userRecord.name.lastName << endl;
    cout << "Email: " << userRecord.media.email << endl;
    cout << "Facebook: " << userRecord.media.facebook << endl;
    cout << "Twitter: " << userRecord.media.twitter << endl;
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Printed list of choice
// Asks user whether or not to print a brief list, prints user choice
void PrintAddressBook(ifstream& inData)
{
    entryType userRecord;
    char choice;

    cout << "Do you want to print a brief list? (Y/N) ";
    cin >> choice;
    cout << endl;

    if (choice == 'N' || 'n') // Full list
	{
        while (GetRecord(inData, userRecord))
	{
            PrintRecord(userRecord);
            cout << endl;
        }
    }
    else // Brief list
	{
        while (GetRecord(inData, userRecord))
	{
            PrintBriefRecord(userRecord);
            cout << endl;
        }
    }
}
