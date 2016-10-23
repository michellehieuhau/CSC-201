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
// done by Robert, takes user inputs for new information appended to the file and stores them into struct data type variables
void AddRecord(entryType& userRecord)
{
    string userPhoneNumber;     //local variable

    cout << "Please input some information for a new entry to the Address Book." << endl;       //user prompts
    cout << "Please enter a name for the new entry: " << endl;
    cout << "Input in the format of Title, First Name, Middle Initial, Last Name, ... please include all commas." << endl;
    getline(cin, userRecord.name.firstName,',');       //stores user inputs into struct variables
    getline(cin, userRecord.name.lastName,'\n');

    cout << endl;
    cout << "Please enter a phone number: " << endl;        //user prompts
    cout << "Enter the phone number in the format of (XXX) XXX-XXXX " << endl;
    getline(cin, userPhoneNumber,'\n');         //puts phone number all into one string
    stringstream(userPhoneNumber.substr(userPhoneNumber.find('(')+1 , userPhoneNumber.find(')'))) >> userRecord.phone.areaCode;     //took the code from above in the GetPhone function and
	stringstream(userPhoneNumber.substr(userPhoneNumber.find(')')+1 , userPhoneNumber.find('-'))) >> userRecord.phone.prefix;       //applied it to extracting the information put into the local variable for phone #
	stringstream(userPhoneNumber.substr(userPhoneNumber.find('-')+1))>> userRecord.phone.number;                                    //and placing it into the struct data type variables

    cout << endl;
    cout << "Please enter an address: " << endl;        //user prompts
    cout << "Input in the format of Street, City, State, Zipcode ... please include all commas." << endl;
    getline(cin, userRecord.address.street,',');        //stores user inputs into struct variables
    getline(cin, userRecord.address.city,',');
    getline(cin, userRecord.address.state,',');
    getline(cin, userRecord.address.zip,'\n');

    cout << endl;
    cout << "Please enter social media information: " << endl;      //user prompts
    cout << "Enter social media information in the format of email, facebook, twitter ... please include all commas." << endl;
    getline(cin, userRecord.media.email,',');       //stores user inputs into struct variables
    getline(cin, userRecord.media.facebook,',');
    getline(cin, userRecord.media.twitter,'\n');

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
