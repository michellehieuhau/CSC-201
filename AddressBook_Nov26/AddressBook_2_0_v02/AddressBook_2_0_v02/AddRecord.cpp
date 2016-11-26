// ***Hoa Nguyen***
// reviewed by Hoa Nguyen
#include <iostream>
#include <fstream>
#include "AddressBook.h"

using namespace std;
/* AddRecord
function allow user to input new information into the file
entryType userRecord is passed by reference (in/out)
*/
void AddRecord(entryType singleEntry[], int newData)
{
    cin.ignore(100, '\n');
    cout << "Enter first name: ";
    cin >> singleEntry[newData].name.firstName;
    cout << "Enter last name: ";
    cin >> singleEntry[newData].name.lastName;
    cout << "Now for the address, please..." << endl;
    cout << "Enter the number and street name: ";
    cin.ignore(100, '\n');
    getline(cin,singleEntry[newData].address.street);
    cout << "Enter the city: ";
    getline(cin,singleEntry[newData].address.city);
    cout << "Enter name of the state: ";
    cin >> singleEntry[newData].address.state;
    cout << "Enter zip code: ";
    cin >> singleEntry[newData].address.zip;
    cout << "Enter Phone Number (in format of XXX XXX XXXX): ";
    cin >> singleEntry[newData].phone.areaCode >> singleEntry[newData].phone.prefix >> singleEntry[newData].phone.number;
    cout << "Enter email address: ";
    cin >> singleEntry[newData].socialmedia.email;
    cout << "Enter facebook account: ";
    cin >> singleEntry[newData].socialmedia.facebook;
    cout << "Enter twitter account: ";
    cin >> singleEntry[newData].socialmedia.twitter;
}

