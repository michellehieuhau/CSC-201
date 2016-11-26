// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddressBook.h"
#include "Search.h"
#include "Manip.h"
#include "Get.h"
#include "Print.h"
#include "Update.h"
#include "WriteRecord.h"

using namespace std;

// Debug flag added for easy trouble shooting during dev.
//bool DebugS = false;


void Update(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    // updateOption;

    do {
        //cout << endl;
        //cout << "Enter how you want to search... " << endl;
        //cout << "(F)irst name, (L)ast name, (A)ddress, (P)hone, (S)(ocial Media), e(X)it: ";
        //cin >> updateOption;
        //updateOption = toupper(updateOption);

        switch (updateCode) {
            case 'F':
                UpdateFirstName(singleEntry, bookSize, bookEntry, updateCode, filename);
                updateCode = 'X';
                break;
            case 'L':
                UpdateLastName(singleEntry, bookSize, bookEntry, updateCode, filename);
                updateCode = 'X';
                break;
            case 'A':
                UpdateAddress(singleEntry, bookSize, bookEntry, updateCode, filename);
                updateCode = 'X';
                break;
            case 'P':
                UpdatePhone(singleEntry, bookSize, bookEntry, updateCode, filename);
                updateCode = 'X';
                break;
            case 'E':
            case 'C':
            case 'T':
                UpdateSocialMedia(singleEntry, bookSize, bookEntry, updateCode, filename);
                updateCode = 'X'; // update email
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                updateCode = 'X';
                break;
        }

    } while (updateCode != 'X');
}

void RmEntry(entryType singleEntry[], int& bookSize, int bookEntry, string filename){
//cout << "RMB" << bookSize << endl;
    char choice;
                string name;

                cout << " Verify that you would like to Delete the Recored listed." << endl << endl;

                cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

                cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

                cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

                cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
                cout << endl << "Enter (Y)es, or (N)o" << endl;
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y' ){
                    while (bookEntry < (bookSize -1)){
                        singleEntry[bookEntry] = singleEntry[(bookEntry+1)];
                        bookEntry++;
                    }
                    bookSize--;
                    bookEntry =0;
                    ofstream outData;
                    outData.open(filename.c_str());
                    while (bookEntry < bookSize){
                        WriteFile(outData, singleEntry, bookEntry);
                        cout << "Writeloop" << endl;
                        if (bookEntry < (bookSize-1)){
                        outData << endl;
                        }
                    bookEntry++;
                    }
                    bookSize = bookEntry;

                    // update Array with new entry
                    ifstream inData;         // for input file
                    inData.open(filename.c_str());

                    if (!inData)
                    cout << "File not found!" << endl;

                    int bookEntry = 0 ;
                    cout << "before loop" << endl;
                    while (GetRecord(inData, singleEntry, bookEntry)){
                        //PrintRecord(singleEntry);
                        cout << "in loop" << endl;
                        bookEntry++;
                    }


                }
                //cout << "RMA" << bookSize << endl;
}

/* SearchFirstName
 Searches passed file stream for a first name read from the user
inData is passed by reference (in/out)
*/
void UpdateFirstName(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    char choice;
    string name;

    cout << " Verify that you would like to update the Recored listed." << endl << endl;

    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

    cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

    cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

    cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
    cout << endl << "Enter (Y)es, or (N)o" << endl;
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y' ){
        cout << "Enter New First Name: ";
        cin >> name;
        singleEntry[bookEntry].name.firstName = name;
        ofstream outData;
        outData.open(filename.c_str());
        bookEntry = 0;
        while (bookEntry < bookSize){
            WriteFile(outData, singleEntry, bookEntry);
            cout << "Writeloop" << endl;
             if (bookEntry < (bookSize-1)){
                    outData << endl;
                }
            bookEntry++;
        }
        bookSize = bookEntry;


    }
}

/* SearchLastName
 Searches passed file stream for a last name read from the user
inData is passed by reference (in/out)
*/
void UpdateLastName(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    char choice;
    string name;

    cout << " Verify that you would like to update the Recored listed." << endl << endl;

    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

    cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

    cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

    cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
    cout << endl << "Enter (Y)es, or (N)o" << endl;
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y' ){
        cout << "Enter New Last Name: ";
        cin >> name;
        singleEntry[bookEntry].name.lastName = name;
        ofstream outData;
        outData.open(filename.c_str());
        bookEntry = 0;
        while (bookEntry < bookSize){
            WriteFile(outData, singleEntry, bookEntry);
            cout << "Writeloop" << endl;
                if (bookEntry < (bookSize-1)){
                    outData << endl;
                }
            bookEntry++;
        }
        bookSize = bookEntry;

    }
}

/* SearchAddress
 Searches passed file stream for an address read from the user
inData is passed by reference (in/out)
*/
void UpdateAddress(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    char choice;
    string name;

    cout << " Verify that you would like to update the Recored listed." << endl << endl;

    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

    cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

    cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

    cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
    cout << endl << "Enter (Y)es, or (N)o" << endl;
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y' ){
        cout << "Enter the number and street name: ";
        cin.ignore(100, '\n');
        getline(cin,singleEntry[bookEntry].address.street);
        cout << "Enter the city: ";
        getline(cin,singleEntry[bookEntry].address.city);
        cout << "Enter name of the state: ";
        cin >> singleEntry[bookEntry].address.state;
        cout << "Enter zip code: ";
        cin >> singleEntry[bookEntry].address.zip;
        ofstream outData;
        outData.open(filename.c_str());
        bookEntry = 0;
        while (bookEntry < bookSize){
            WriteFile(outData, singleEntry, bookEntry);

                if (bookEntry < (bookSize-1)){
                    outData << endl;
                }
            bookEntry++;
        }
        bookSize = bookEntry;

    }
}

/* SearchPhone
 Searches passed file stream for a phone number read from the user
inData is passed by reference (in/out)
*/
void UpdatePhone(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    char choice;
    string name;

    cout << " Verify that you would like to update the Recored listed." << endl << endl;

    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

    cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

    cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

    cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
    cout << endl << "Enter (Y)es, or (N)o" << endl;
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y' ){
        cout << "Enter Phone Number (in format of XXX XXX XXXX): ";
        cin >> singleEntry[bookEntry].phone.areaCode >> singleEntry[bookEntry].phone.prefix >> singleEntry[bookEntry].phone.number;
        ofstream outData;
        outData.open(filename.c_str());
        bookEntry = 0;
        while (bookEntry < bookSize){
            WriteFile(outData, singleEntry, bookEntry);

                if (bookEntry < (bookSize-1)){
                    outData << endl;
                }
            bookEntry++;
        }
        bookSize = bookEntry;

    }
}

/* SearchSocialMedia
 Searches passed file stream for a social media account read from the user
inData is passed by reference (in/out)
*/
void UpdateSocialMedia(entryType singleEntry[], int& bookSize, int bookEntry, char updateCode, string filename)
{
    string searchSocialM;
    string normalsearchChoice;
    entryType userRecord;
    string normalSearchSocialM, normalSocialM;

        switch (updateCode) {
            case 'E':{
                char choice;
                string name;

                cout << " Verify that you would like to update the Recored listed." << endl << endl;

                cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

                cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

                cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

                cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
                cout << endl << "Enter (Y)es, or (N)o" << endl;
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y' ){
                    cout << "Enter email address: ";
                    cin >> singleEntry[bookEntry].socialmedia.email;
                    ofstream outData;
                    outData.open(filename.c_str());
                    bookEntry = 0;
                    while (bookEntry < bookSize){
                        WriteFile(outData, singleEntry, bookEntry);

                        if (bookEntry < (bookSize-1)){
                        outData << endl;
                        }
                    bookEntry++;
                    }
                    bookSize = bookEntry;

                }
                break;
            }
            case 'C':{
                char choice;
                string name;

                cout << " Verify that you would like to update the Recored listed." << endl << endl;

                cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

                cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

                cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

                cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
                cout << endl << "Enter (Y)es, or (N)o" << endl;
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y' ){
                    cout << "Enter facebook account: ";
                    cin >> singleEntry[bookEntry].socialmedia.facebook;
                    ofstream outData;
                    outData.open(filename.c_str());
                    bookEntry = 0;
                    while (bookEntry < bookSize){
                        WriteFile(outData, singleEntry, bookEntry);

                        if (bookEntry < (bookSize-1)){
                        outData << endl;
                        }
                    bookEntry++;
                    }
                    bookSize = bookEntry;

                }
                break;
            }
            case 'T':{
            char choice;
                string name;

                cout << " Verify that you would like to update the Recored listed." << endl << endl;

                cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */singleEntry[bookEntry].name.firstName << " " << singleEntry[bookEntry].name.lastName << endl;

                cout << "Phone: " << "(" << singleEntry[bookEntry].phone.areaCode << ") "
                      << singleEntry[bookEntry].phone.prefix << "-"
                      << singleEntry[bookEntry].phone.number << endl;

                cout << "Address: " << singleEntry[bookEntry].address.street << " "
                        << singleEntry[bookEntry].address.city
                        << singleEntry[bookEntry].address.state << " "
                        << singleEntry[bookEntry].address.zip << endl;

                cout << "Social Media: " << "Email= " << singleEntry[bookEntry].socialmedia.email << " "
                             << "Facebook= " << singleEntry[bookEntry].socialmedia.facebook << " "
                             << "Twitter= " << singleEntry[bookEntry].socialmedia.twitter << endl << endl;
                cout << endl << "Enter (Y)es, or (N)o" << endl;
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y' ){
                    cout << "Enter twitter account: ";
                    cin >> singleEntry[bookEntry].socialmedia.twitter;
                    ofstream outData;
                    outData.open(filename.c_str());
                    bookEntry = 0;
                    while (bookEntry < bookSize){
                        WriteFile(outData, singleEntry, bookEntry);

                        if (bookEntry < (bookSize-1)){
                        outData << endl;
                        }
                    bookEntry++;
                    }
                    bookSize = bookEntry;

                }
                break;
            }
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }
}
