#include <iostream>
#include <fstream>
#include <sstream>
#include "AddressBook.h"
#include "ValidRecord.h"

using namespace std;

//---------------------------------------------------------------------------
// Inputs: String
// Outputs: Normalized string
// Capitalizes first letter of each word in string and lowercases rest
void NormalizeRecord(string& userRecord)
{
	userRecord[0]=toupper(userRecord[0]);
	for (int i=1; i<userRecord.size(); i++)
	{
		userRecord[i]=tolower(userRecord[i]);
		if (isspace(userRecord[i-1]))
			userRecord[i]=toupper(userRecord[i]);
	}
}

//---------------------------------------------------------------------------
// Outputs: New record
// Asks user for new record elements
// Taking user inputs for new information appended to the file and stores them into struct data type variables
void AddRecord(entryType& userRecord)
{
    string userPhoneNumber;     //local variable

void AddRecord(entryType& userRecord)
{
	string phone;
	do
	{
		cout << "Enter first name: ";
		getline(cin, userRecord.name.firstName);
	} while (!ValidName(userRecord.name.firstName));
	NormalizeRecord(userRecord.name.firstName);
	
	do
	{
		cout << "Enter last name: ";
		getline(cin, userRecord.name.lastName);
	} while (!ValidName(userRecord.name.lastName));
	NormalizeRecord(userRecord.name.lastName);
	
	do
	{
		cout << "Enter street address: ";
		getline(cin, userRecord.address.street);
		cout << "Enter city: ";
		getline(cin, userRecord.address.city);
		cout << "Enter state: ";
		getline(cin, userRecord.address.state);
		userRecord.address.state = NormalizeString(userRecord.address.state);
		cout << "Enter zip code: ";
		getline(cin, userRecord.address.zip);
	} while (!ValidAddress(userRecord.address));
	NormalizeRecord(userRecord.address.street);
	NormalizeRecord(userRecord.address.city);
	NormalizeString(userRecord.address.state);
	
	do
	{
		cout << "Enter phone number in the form (XXX) XXX-XXXX: ";
		getline(cin, phone);
	} while (!ValidPhone(phone));
	
	stringstream(phone.substr(phone.find('(')+1,phone.find(')'))) >> userRecord.phone.areaCode;
	stringstream(phone.substr(phone.find(')')+1,phone.find('-'))) >> userRecord.phone.prefix;
	stringstream(phone.substr(phone.find('-')+1))>> userRecord.phone.number;
	
	do
	{
		cout << "Enter email address: ";
		cin >> userRecord.media.email;
	} while (!ValidMedia(userRecord.media.email, 'E'));
	
	do
	{
		cout << "Enter facebook username: ";
		cin >> userRecord.media.facebook;
	} while (!ValidMedia(userRecord.media.facebook, 'F'));

	
	do
	{
		cout << "Enter twitter username: ";
		cin >> userRecord.media.twitter;
	} while (!ValidMedia(userRecord.media.twitter, 'T'));
}

//---------------------------------------------------------------------------
// Inputs: Output file stream, new record
// Outputs: New record in file
// Writes given record into output file stream
void WriteRecord(ofstream& outData, entryType userRecord)
{
    outData << userRecord.name.title << ", " << userRecord.name.firstName << ", " << userRecord.name.middleInitial << ", " << userRecord.name.lastName;
    outData << "(" << userRecord.phone.areaCode << ") " << userRecord.phone.prefix << "-" << userRecord.phone.number << endl;
    outData << userRecord.address.street << ", " << userRecord.address.city << ", " << userRecord.address.state << ", " << userRecord.address.zip << endl;
    outData << userRecord.media.email << ", " << userRecord.media.facebook << ", " << userRecord.media.twitter << endl;
}


//---------------------------------------------------------------------------
// Inputs: Input file stream, File name
// Outputs: Added record to file
// Prompts user to input new record, writes new record to file
void AddEntry(ifstream& inData, string filename)
{
    entryType userRecord;
    ofstream outData;

	// Call to input new record
    AddRecord(userRecord);

	// Swap in and out file streams
    inData.close();
    outData.open(filename.c_str(), fstream::app);

	// Write new record to file
    WriteRecord(outData, userRecord);
    outData.close();

	// Reopen in file stream
    inData.open(filename.c_str());

}
