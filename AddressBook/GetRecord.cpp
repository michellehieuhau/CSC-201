
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "AddressBook.h"
#include "ValidRecord.h"

using namespace std;

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: First and last name
// Reads full name from file and stores in NameType
void GetName(ifstream& inData, NameType& userName)
{
    getline(inData, userName.firstName, ',');
    TrimSpaces(userName.firstName);

    getline(inData, userName.lastName, ',');
    TrimSpaces(userName.lastName);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Phone number
// Reads phone string from file and stores as integers in PhoneType
void GetPhone(ifstream& inData, PhoneType& userPhone)
{
	string ph;
	getline(inData, ph, '\n');
	// Convert phone string to integers
	stringstream(ph.substr(ph.find('(')+1,ph.find(')'))) >> userPhone.areaCode;
	stringstream(ph.substr(ph.find(')')+1,ph.find('-'))) >> userPhone.prefix;
	stringstream(ph.substr(ph.find('-')+1))>> userPhone.number;
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: State
// Reads state from file in AddressType
void GetState(ifstream& inData, AddressType& userAddress)
{
    getline(inData, userAddress.state, ',');
    TrimSpaces(userAddress.state);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Address
// Reads address line from file and stores in AddressType
void GetAddress(ifstream& inData, AddressType& userAddress)
{
    getline(inData, userAddress.street, ',');
    getline(inData, userAddress.city, ',');
    TrimSpaces(userAddress.city);
    GetState(inData, userAddress);
    getline(inData, userAddress.zip, '\n');
    TrimSpaces(userAddress.zip);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Email, Facebook, Twitter
// Reads social media from file and stores in MediaType
void GetSocialMedia(ifstream& inData, MediaType& userMedia)
{
	getline(inData, userMedia.email, ',');
	getline(inData, userMedia.facebook, ',');
    TrimSpaces(userMedia.facebook);
	getline(inData, userMedia.twitter, '\n');
    TrimSpaces(userMedia.twitter);
}

//---------------------------------------------------------------------------
// Inputs: Input file stream
// Outputs: Full record
// Gets a complete record from file and returns file state
bool GetRecord(ifstream& inData, entryType& userRecord)
{
	GetName(inData, userRecord.name);
	GetPhone(inData, userRecord.phone);
	GetAddress(inData, userRecord.address);
	GetSocialMedia(inData, userRecord.media);
    return inData;
}

