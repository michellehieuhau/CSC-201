#include <iostream>
#include <string>
#include <cctype>
#include "AddressBook.h"

using namespace std;

//---------------------------------------------------------------------------
// Inputs: String
// Outputs: Trimmed string
// Remove spaces from start and end of string
void TrimSpaces(string& str)
{
    int index;

    index = str.find_first_not_of(" \t");
    str.erase(0, index);

    index = str.find_last_not_of(" \t");
    if (string::npos != index)
        str.erase(index + 1);
}

//---------------------------------------------------------------------------
// Inputs: String
// Outputs: Capitalized string
// Convert string to all uppercase
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

//---------------------------------------------------------------------------
// Inputs: Name
// Outputs: Validity of name
// Check name for all letters
bool ValidName(string searchName)
{
	for (int i=0; i<searchName.length(); i++)
		if (!isalpha(searchName[i]))
		{
			cout << "Invalid name. Please enter a proper name.\n";
			return false;
		}
	return true;
}

//---------------------------------------------------------------------------
// Inputs: Address
// Outputs: Validity of address
// Address has at least one char
// City is all letters and spaces
// State is two letters
// Zip code is all numbers
bool ValidAddress(AddressType searchAddress)
{
	int letter = 0;
	for (int i=0; i<searchAddress.street.length(); i++)
	{
		if (isalpha(searchAddress.street[i]))
			letter++;
	}
	if (letter==0)
	{
		cout << "Invalid address. Please enter at least a street.\n";
		return false;
	}

	for (int i=0; i<searchAddress.city.length(); i++)
		if (!isalpha(searchAddress.city[i]) && !isspace(searchAddress.city[i]))
		{
			cout << "Invalid city. Please enter a proper city name.\n";
			return false;
		}

	if (searchAddress.state.length() != 2)
	{
		cout << "Invalid state. Please enter a two letter state abbreviation.\n";
		return false;
	}
	for (int i=0; i<searchAddress.state.length(); i++)
		if (!isalpha(searchAddress.state[i]))
		{
			cout << "Invalid state. Please enter a proper state abbreviation.\n";
			return false;
		}

	for (int i=0; i<searchAddress.zip.length(); i++)
		if (!isdigit(searchAddress.zip[i]))
		{
			cout << "Invalid zip code. Please enter a proper zip code.\n";
			return false;
		}
	return true;
}

//---------------------------------------------------------------------------
// Inputs: Phone number
// Outputs: Validity of phone number
// Phone must (XXX) XXX-XXXX and X is a number
bool ValidPhone(string searchPhone)
{
	if (searchPhone.length() != 14 || searchPhone[9]!='-' ||
		searchPhone[0]!='(' || searchPhone[4]!=')' || searchPhone[5]!=' ')
	{
		cout << "Invalid phone number. Please enter in the proper form.\n";
		return false;
	}
	// Check rest of input is only numbers
	for (int i=0; i < 14; i++)
	{
		if (i==0 || i==4 || i==5 || i==9)
			continue;
		if (!isdigit(searchPhone[i]))
		{
			cout << "Invalid phone number. Please enter numbers.\n";
			return false;
		}
	}
	return true;
}

//---------------------------------------------------------------------------
// Inputs: Social media string, Social media type
// Outputs: Validity of social media
// If email, must have at least one '@' and '.' each
// If facebook, must be letters or '.', and greater than 5 char
// If twitter, must be letters or numbers or '_', and less than 15 char
bool ValidMedia(string searchMedia, char choice)
{
	int at=0, dot=0;
	switch (choice)
	{
		case 'E':
			for (int i=0; i<searchMedia.size(); i++)
			{
				if (searchMedia[i]=='@')
					at++;
				if (searchMedia[i]=='.')
					dot++;
			}
			if (at!=1 || dot!=1)
			{
				cout << "Invalid email. Please enter proper email address.\n";
				return false;
			}
			break;
		case 'F':
			if (searchMedia.size()<5)
			{
				cout << "Invalid facebook username. Please enter a proper username length.\n";
				return false;
			}
			for (int i=0; i<searchMedia.size(); i++)
				if (searchMedia[i]!='.' && !(isalpha(searchMedia[i])))
				{
					cout << "Invalid facebook username. Please enter a proper username.\n";
					return false;
				}
			break;
		case 'T':
			if (searchMedia.size()>15)
			{
				cout << "Invalid twitter username. Please enter a proper username length.\n";
				return false;
			}
			for (int i=0; i<searchMedia.size(); i++)
				if (!isalnum(searchMedia[i]) && searchMedia[i]!='_')
				{
					cout << "Invalid twitter username. Please enter a proper username.\n";
					return false;
				}
			break;
	}
	return true;
}
