// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddressBook.h"

using namespace std;
/* WriteRecord
Append new input data from the user to the address book
outData is passed by reference (in/out), userRecord is passed by value (out)
*/
void WriteRecord(ofstream& outData, entryType singleEntry[], int newData)
{
    outData << endl << singleEntry[newData].name.firstName << ", " << singleEntry[newData].name.lastName
            << ", " << singleEntry[newData].phone.areaCode << " "
            << singleEntry[newData].phone.prefix << " "
            << singleEntry[newData].phone.number << endl;

    outData << singleEntry[newData].address.street << ", " << singleEntry[newData].address.city
             << ", " << singleEntry[newData].address.state << ", " << singleEntry[newData].address.zip << endl ; // space after record output

    outData << singleEntry[newData].socialmedia.email << ", " << singleEntry[newData].socialmedia.facebook
                << ", " << singleEntry[newData].socialmedia.twitter;
}

void WriteFile(ofstream& outData, entryType singleEntry[], int newData)
{
    outData << singleEntry[newData].name.firstName << ", " << singleEntry[newData].name.lastName
            << ", " << singleEntry[newData].phone.areaCode << " "
            << singleEntry[newData].phone.prefix << " "
            << singleEntry[newData].phone.number << endl;

    outData << singleEntry[newData].address.street << ", " << singleEntry[newData].address.city
             << "," << singleEntry[newData].address.state << ", " << singleEntry[newData].address.zip << endl ; // space after record output

    outData << singleEntry[newData].socialmedia.email << ", " << singleEntry[newData].socialmedia.facebook
                << ", " << singleEntry[newData].socialmedia.twitter;

}

