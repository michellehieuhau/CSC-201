// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddressBook.h"
#include "Get.h"
#include "Manip.h"

/* GetRecord
Read all elements of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userRecord are passed by reference (in/out)
*/
bool GetRecord(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    GetName(inData, singleEntry, bookEntry); // call GetName to update values from next entry
    GetPhone(inData, singleEntry, bookEntry); // call GetPhone to update values from next entry
    GetAddress(inData, singleEntry, bookEntry); // call GetAddress to update values from next entry
    GetSocialM(inData, singleEntry, bookEntry); // call to Get SocialM info added.
    return inData;
}
/* GetName
Read the person's name of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userName are passed by reference (in/out)
*/
void GetName(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    getline(inData, singleEntry[bookEntry].name.firstName, ',');
    TrimSpaces(singleEntry[bookEntry].name.firstName);

    getline(inData, singleEntry[bookEntry].name.lastName, ',');
    TrimSpaces(singleEntry[bookEntry].name.lastName);
}

/* GetPhone
Read the phone number of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userPhone are passed by reference (in/out)
*/
void GetPhone(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    string null_out; // null_out is for \n removal from stream.
    inData >> singleEntry[bookEntry].phone.areaCode;
    inData >> singleEntry[bookEntry].phone.prefix;
    inData >> singleEntry[bookEntry].phone.number;
    getline(inData, null_out,'\n');
}
/* GetAddress
Read the address of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userAddress are passed by reference (in/out)
*/
void GetAddress(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    getline(inData, singleEntry[bookEntry].address.street, ',');
    TrimSpaces(singleEntry[bookEntry].address.street);

    getline(inData, singleEntry[bookEntry].address.city, ',');
    TrimSpaces(singleEntry[bookEntry].address.city);

    GetState(inData, singleEntry, bookEntry);

    getline(inData, singleEntry[bookEntry].address.zip, '\n');
    TrimSpaces(singleEntry[bookEntry].address.zip);
}
/* GetState
Read name of the state within an address of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userAddress are passed by reference (in/out)
*/
void GetState(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    getline(inData, singleEntry[bookEntry].address.state, ',');
}

/* GetSocialM
Read all social media information of an address book entry from a given file, and return true if successful, false otherwise (Based on stream state)
inData and userSocial are passed by reference (in/out)
*/
void GetSocialM(ifstream& inData, entryType singleEntry[], int bookEntry)
{
    getline(inData, singleEntry[bookEntry].socialmedia.email, ',');
    TrimSpaces(singleEntry[bookEntry].socialmedia.email);

    getline(inData, singleEntry[bookEntry].socialmedia.facebook, ',');
    TrimSpaces(singleEntry[bookEntry].socialmedia.facebook);

    getline(inData, singleEntry[bookEntry].socialmedia.twitter, '\n');
    TrimSpaces(singleEntry[bookEntry].socialmedia.twitter);
}
/* GetTitle
Read user-defined data type of an address book entry from a given file, and return result if it fulfill the requirement
title is passed by value (in)
*/
string GetTitle(Title title)
{
    title = Mr;
    switch (title) {
        case Mr:
            return "Mr";
            break;
        case Mrs:
            return "Mrs";
            break;
        case Ms:
            return "Ms";
            break;
        case Dr:
            return "Dr";
            break;
        default:
            return "Invalid";
    }
}
