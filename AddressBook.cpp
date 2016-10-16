// addressbook.cpp -- Implements a simple address book that will
// look up entries based on name, phone number, or address
// S. Davis, CSC201, 2/22/16

#include <iostream>
#include <fstream>
#include<cctype>

using namespace std;

void OpenFile(string, ifstream&);
bool GetRecord(ifstream&, string&, string&, string&, string&);
void PrintRecord(string, string, string, string);
void SearchFirstName(ifstream&);
void SearchLastName(ifstream&);
void SearchAddress(ifstream&);
void SearchPhone(ifstream&);
string NormalizeString(string);
void TrimSpaces(string&);
void PurgeLines(ifstream&, int);

int main()
{
    string firstName, lastName, address, phone;
    string filename;
    ifstream inData;
    char searchOption;

    OpenFile(filename, inData);

    do {
        cout << "Enter how you want to search... " << endl;
        cout << "(F)irst name, (L)ast name, (A)ddress, (P)hone, e(X)it: ";
        cin >> searchOption;
        cin.ignore(100,'\n');

        searchOption = toupper(searchOption);

        switch (searchOption) {
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
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }

    } while (searchOption != 'X');

    return 0;
}

void OpenFile(string filename, ifstream& inData)
{
    do {
        cout << "Enter file name to open: ";
        cin >> filename;

        inData.open(filename.c_str());

        if (!inData)
            cout << "File not found!" << endl;

    } while (!inData);
}

// Searches passed file stream for a first name read from the user
void SearchFirstName(ifstream& inData)
{
    string searchName;
    string firstName, lastName, phone, address;
    string normalSearchName, normalFirstName;

    cout << "Enter first name to search for: ";
    cin >> searchName;




          normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

            // Loop through all records in the file
            while (GetRecord(inData, firstName, lastName, phone, address)){

                normalFirstName = NormalizeString(firstName);   // Convert retrieved string to all uppercase

                if (normalFirstName == normalSearchName) // Requested name matches
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

// Searches passed file stream for a last name read from the user
void SearchLastName(ifstream& inData)
{
    string searchName;
    string firstName, lastName, phone, address;
    string normalSearchName, normalLastName;

    cout << "Enter last name to search for: ";
    cin >> searchName;

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

    // Loop through all records in the file
    while (GetRecord(inData, firstName, lastName, phone, address)){

        normalLastName = NormalizeString(lastName);   // Convert retrieved string to all uppercase

        if (normalLastName == normalSearchName) // Requested name matches
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

// Searches passed file stream for a address read from the user
void SearchAddress(ifstream& inData)
{
    string searchName;
    string firstName, lastName, phone, address;
    string normalSearchName, normalAddress;

    cout << "Enter Address to search for: ";
    getline(cin, searchName);

    normalSearchName = NormalizeString(searchName);  // Convert name to all uppercase

    // Loop through all records in the file
    while (GetRecord(inData, firstName, lastName, phone, address)){

        normalAddress = NormalizeString(address);   // Convert retrieved string to all uppercase

        if (normalAddress == normalSearchName) // Requested name matches
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

// Searches passed file stream for a phone number read from the user
void SearchPhone(ifstream& inData)
{
    string searchName;
    string firstName, lastName, phone, address;
    string normalSearchName, normalPhone;

    cout << "Enter phone number to search for: ";
    getline(cin, searchName);

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

    // Loop through all records in the file
    while (GetRecord(inData, firstName, lastName, phone, address)){

        normalPhone = NormalizeString(phone);   // Convert retrieved string to all uppercase

        if (normalPhone == normalSearchName) // Requested name matches
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

// Read all elements of an address book entry from a given file
// Return true if successful, false othewise (Based on stream state)
bool GetRecord(ifstream& inData,
               string& firstName, string& lastName,
               string& phone, string& address)
{

    getline(inData, firstName, ',');
    TrimSpaces(firstName);

    getline(inData, lastName, ',');
    TrimSpaces(lastName);

    getline(inData, phone, '\n');
    TrimSpaces(phone);

    getline(inData, address);
    TrimSpaces(address);

    return inData;
}

// Given all the elements of an address book entry, print the results
void PrintRecord(string firstName, string lastName,
                 string phone, string address)
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
}

// Convert passed string to all upper case and return result
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

// Remove any leading or trailing spaces from given string
void TrimSpaces(string& str)
{
    int index;

    index = str.find_first_not_of(" \t");
    str.erase(0, index);

    index = str.find_last_not_of(" \t");
    if (string::npos != index)
        str.erase(index + 1);
}

// **Not used**
// Read and discard a specified number of lines from a given file
void PurgeLines(ifstream& inData, int numLines)
{
    string buffer;

    for (int i = 0; i < numLines; i++)
        getline(inData, buffer, '\n');
}
