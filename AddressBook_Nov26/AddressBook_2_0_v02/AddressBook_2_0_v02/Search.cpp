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

using namespace std;

// Debug flag added for easy trouble shooting during dev.
bool DebugS = false;


void SearchMenu(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    char searchOption;

    do {
        cout << endl;
        cout << "Enter how you want to search... " << endl;
        cout << "(F)irst name, (L)ast name, (A)ddress, (P)hone, (S)(ocial Media), e(X)it: ";
        cin >> searchOption;
        searchOption = toupper(searchOption);

        switch (searchOption) {
            case 'F':
                SearchFirstName(singleEntry, bookSize , UpdateorDelete, filename);
                break;
            case 'L':
                SearchLastName(singleEntry, bookSize, UpdateorDelete, filename);
                break;
            case 'A':
                SearchAddress(singleEntry, bookSize, UpdateorDelete, filename);
                break;
            case 'P':
                SearchPhone(singleEntry, bookSize, UpdateorDelete, filename);
                break;
            case 'S':
                SearchSocialMedia(singleEntry, bookSize, UpdateorDelete, filename);
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }

    } while (searchOption != 'X');
}

/* SearchFirstName
 Searches passed file stream for a first name read from the user
inData is passed by reference (in/out)
*/
void SearchFirstName(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    string searchName;
    entryType userRecord;
    string normalSearchName, normalFirstName;
    char choice;
    bool found = false;
    bool more = false;

    cout << "Enter first name to search for: ";
    cin >> searchName;

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase
    int bookEntry=0;
    // Loop through all records in the file
    while (bookEntry < bookSize){

        normalFirstName = NormalizeString(singleEntry[bookEntry].name.firstName);   // Convert retrieved string to all uppercase

        if (normalFirstName == normalSearchName) { // Requested name matches
            PrintRecord(singleEntry, bookEntry);
            cout << "Look for More with same first name (M), Or is this the correct entry? (Y/N)";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
            // Added more flag to remove not found Message when looking for more than one entry
            if (choice == 'M'){
                more = true;
            }

        }
        bookEntry++;
    }
        // Matching name was found before the end of the file
    if (bookEntry < bookSize){
        cout << "Record found: " << endl;
        PrintRecord(singleEntry, bookEntry);
        cout << endl;
    }
    else if (!found && more != true)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }

    if (found == true &&(UpdateorDelete == 'U' || UpdateorDelete == 'D')){
            if (UpdateorDelete == 'U'){
                Update(singleEntry, bookSize, bookEntry, 'F', filename);
            }
            else if (UpdateorDelete == 'D'){
                RmEntry(singleEntry, bookSize, bookEntry, filename);    //Add call to Delete function
                }
    }       // Add option to update or delete entry here

    // Clear file fail state and return to beginning
  //  inData.clear();
  //  inData.seekg(0);
}

/* SearchLastName
 Searches passed file stream for a last name read from the user
inData is passed by reference (in/out)
*/
void SearchLastName(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    string searchName;
    entryType userRecord;
    string normalSearchName, normalLastName;
    char choice;
    bool found = false;
    bool more = false;

    cout << "Enter last name to search for: ";
    cin >> searchName;

    normalSearchName = NormalizeString(searchName);     // Convert name to all uppercase

    int bookEntry=0;
    // Loop through all records in the file
    while (bookEntry < bookSize){

        normalLastName = NormalizeString(singleEntry[bookEntry].name.lastName);   // Convert retrieved string to all uppercase

        if (normalLastName == normalSearchName) { // Requested name matches
            PrintRecord(singleEntry, bookEntry);
            cout << "Look for More with same last name (M), Or is this the correct entry? (Y/N)";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
            // Added more flag to remove not found Message when looking for more than one entry
            if (choice == 'M'){
                more = true;
            }
        }
        bookEntry++;
    }

    // Matching name was found before the end of the file
    if (bookEntry < bookSize){
        cout << "Record found: " << endl;
        PrintRecord(singleEntry, bookEntry);
        cout << endl;
    }
    else if (!found && more != true)   // End of file. Name not found.
    {
        cout << searchName << " not found!" << endl << endl;
    }
    if (found == true &&(UpdateorDelete == 'U' || UpdateorDelete == 'D')){
            if (UpdateorDelete == 'U'){
                Update(singleEntry, bookSize, bookEntry, 'L', filename);
            }
            else if (UpdateorDelete == 'D'){
                RmEntry(singleEntry, bookSize, bookEntry, filename);    //Add call to Delete function
                }
    }       // Add option to update or delete entry here

    // Clear file fail state and return to beginning
 //   inData.clear();
  //  inData.seekg(0);
}

/* SearchAddress
 Searches passed file stream for an address read from the user
inData is passed by reference (in/out)
*/
void SearchAddress(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    string searchAddress;
    entryType userRecord;
    string normalSearchAddress, normalAddress;
    char choice;
    bool found = false;
    bool more = false;

    cout << "Enter street name to search for: ";
    cin.ignore(10000,'\n');
    getline(cin, searchAddress);

    normalSearchAddress = NormalizeString(searchAddress);     // Convert name to all uppercase

    int bookEntry=0;
    // Loop through all records in the file
    while (bookEntry < bookSize){

        normalAddress = NormalizeString(singleEntry[bookEntry].address.street);   // Convert retrieved string to all uppercase

        if (normalAddress == normalSearchAddress) { // Requested name matches
            PrintRecord(singleEntry, bookEntry);
            cout << "Look for More with same Street (M), Or is this the correct entry? (Y/N)";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
            // Added more flag to remove not found Message when looking for more than one entry
            if (choice == 'M'){
                more = true;
            }


        }
        bookEntry++;
    }

    // Matching name was found before the end of the file
    if (bookEntry < bookSize){
        cout << "Record found: " << endl;
        PrintRecord(singleEntry, bookEntry);
        cout << endl;
    }
    else if (!found && more != true)   // End of file. Name not found.
    {
        cout << searchAddress << " not found!" << endl << endl;
    }
    if (found == true && (UpdateorDelete == 'U' || UpdateorDelete == 'D' )){
                    if (UpdateorDelete == 'U'){
                        Update(singleEntry, bookSize, bookEntry, 'A', filename);
                    }
                    else if (UpdateorDelete == 'D'){
                        RmEntry(singleEntry, bookSize, bookEntry, filename);    //Add call to Delete function
                        }
    }       // Add option to update or delete entry here

    // Clear file fail state and return to beginning
//    inData.clear();
//    inData.seekg(0);
}

/* SearchPhone
 Searches passed file stream for a phone number read from the user
inData is passed by reference (in/out)
*/
void SearchPhone(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    int SearchPhone_areaCode;
    int SearchPhone_prefix;
    int SearchPhone_number;
    entryType userRecord;
    //string normalSearchPhone, normalPhone;
    char choice;
    bool found = false;
    bool more = false;

    cout << "Enter phone number to search for ( in 123 456 7891 format):";
    //cin.ignore(10000,'\n');
    cin >> SearchPhone_areaCode >> SearchPhone_prefix >> SearchPhone_number;

    //normalSearchAddress = NormalizeString(searchAddress);     // Convert name to all uppercase

    int bookEntry=0;
    // Loop through all records in the file
    while (bookEntry < bookSize){

        //normalAddress = NormalizeString(userRecord.address.street);   // Convert retrieved string to all uppercase

        if (singleEntry[bookEntry].phone.areaCode == SearchPhone_areaCode && singleEntry[bookEntry].phone.prefix == SearchPhone_prefix && singleEntry[bookEntry].phone.number == SearchPhone_number) { // Requested name matches
            PrintRecord(singleEntry, bookEntry);
            cout << "Look for More with same phone number (M), Or is this the correct entry? (Y/N)";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;

            if (choice == 'Y') {
                found = true;
                break;
            }
            // Added more flag to remove not found Message when looking for more than one entry
            if (choice == 'M'){
                more = true;
            }

        }
        bookEntry++;
    }

    // Matching name was found before the end of the file
    if (bookEntry < bookSize){
        cout << "Record found: " << endl;
        PrintRecord(singleEntry, bookEntry);
        cout << endl;
    }
    else if (!found && more != true)   // End of file. Name not found.
    {
        cout << SearchPhone_areaCode << "-" << SearchPhone_prefix << "-" << SearchPhone_number << " not found!" << endl << endl;
    }
    if (found == true && (UpdateorDelete == 'U' || UpdateorDelete == 'D' )){
                        if (UpdateorDelete == 'U'){
                            Update(singleEntry, bookSize, bookEntry, 'P', filename);
                        }
                        else if (UpdateorDelete == 'D'){
                            RmEntry(singleEntry, bookSize, bookEntry, filename);    //Add call to Delete function
                        }
    }       // Add option to update or delete entry here
    // Clear file fail state and return to beginning
//    inData.clear();
//    inData.seekg(0);
}

/* SearchSocialMedia
 Searches passed file stream for a social media account read from the user
inData is passed by reference (in/out)
*/
void SearchSocialMedia(entryType singleEntry[], int& bookSize, char UpdateorDelete, string filename)
{
    string searchSocialM;
    string normalsearchChoice;
    entryType userRecord;
    string normalSearchSocialM, normalSocialM;
    char choice;
    bool found = false;
    bool more = false;

    int bookEntry=0;
    cout << endl << "What would you like to Search for, (E)mail, (F)acebook, or (T)witter, e(X)it: ";
    cin >> choice;
        choice = toupper(choice);

        switch (choice) {
            case 'E':{
                cout << "Enter Email name to search for: ";
                cin.ignore(10000,'\n');
                getline(cin, searchSocialM);

                normalSearchSocialM = NormalizeString(searchSocialM);     // Convert name to all uppercase

                // Loop through all records in the file
                while (bookEntry < bookSize){

                normalSocialM = NormalizeString(singleEntry[bookEntry].socialmedia.email);   // Convert retrieved string to all uppercase

                if (DebugS){
                    cout << "Debug-SearchSocialMedia-#1" << endl;
                    cout << "normalSocialM: " << normalSocialM << endl;
                    cout << "normalSearchSocialM " << normalSearchSocialM << endl;
                }

                if (normalSocialM == normalSearchSocialM) { // Requested name matches
                    PrintRecord(singleEntry, bookEntry);
                    cout << "Look for More with same Email (M), Or is this the correct entry? (Y/N)";
                    cin >> choice;
                    choice = toupper(choice);
                    cout << endl;

                    if (choice == 'Y') {
                        found = true;
                        break;
                    }
                    // Added more flag to remove not found Message when looking for more than one entry
                    if (choice == 'M'){
                    more = true;
                    }


                }
                bookEntry++;
            }

            // Matching name was found before the end of the file
            if (bookEntry < bookSize){
                cout << "Record found: " << endl;
                PrintRecord(singleEntry, bookEntry);
                cout << endl;
            }
            else if (!found && more != true)   // End of file. Name not found.
            {
                cout << searchSocialM << " not found!" << endl << endl;
            }
            if (found == true && (UpdateorDelete == 'U' || UpdateorDelete == 'D' )){
                        if (UpdateorDelete == 'U'){
                            Update(singleEntry, bookSize, bookEntry, 'E', filename);
                        }
                        else if (UpdateorDelete == 'D'){
                            RmEntry(singleEntry, bookSize, bookEntry, filename);   //Add call to Delete function
                        }
            }       // Add option to update or delete entry here

            // Clear file fail state and return to beginning
 //           inData.clear();
//            inData.seekg(0);
            }
                break;
            case 'F':{
                cout << "Enter Facebook name to search for: ";
                cin.ignore(10000,'\n');
                getline(cin, searchSocialM);

                normalSearchSocialM = NormalizeString(searchSocialM);     // Convert name to all uppercase

                // Loop through all records in the file
                while (bookEntry < bookSize){

                normalSocialM = NormalizeString(singleEntry[bookEntry].socialmedia.facebook);   // Convert retrieved string to all uppercase

                if (DebugS){
                    cout << "Debug-SearchSocialMedia-#2" << endl;
                    cout << "normalSocialM: " << normalSocialM << endl;
                    cout << "normalSearchSocialM " << normalSearchSocialM << endl;
                }

                if (normalSocialM == normalSearchSocialM) { // Requested name matches
                    PrintRecord(singleEntry, bookEntry);
                    cout << "Look for More with same Facebook (M), Or is this the correct entry? (Y/N)";
                    cin >> choice;
                    choice = toupper(choice);
                    cout << endl;

                    if (choice == 'Y') {
                        found = true;
                        break;
                    }
                    // Added more flag to remove not found Message when looking for more than one entry
                    if (choice == 'M'){
                    more = true;
                    }

                }
                bookEntry++;
            }

            // Matching name was found before the end of the file
            if (bookEntry < bookSize){
                cout << "Record found: " << endl;
                PrintRecord(singleEntry, bookEntry);
                cout << endl;
            }
            else if (!found && more != true)   // End of file. Name not found.
            {
                cout << searchSocialM << " not found!" << endl << endl;
            }
            if (found == true && (UpdateorDelete == 'U' || UpdateorDelete == 'D' )){
                        if (UpdateorDelete == 'U'){
                            Update(singleEntry, bookSize, bookEntry, 'C', filename);
                        }
                        else if (UpdateorDelete == 'D'){
                            RmEntry(singleEntry, bookSize, bookEntry, filename);
                        }
            }       // Add option to update or delete entry here

            // Clear file fail state and return to beginning
//            inData.clear();
//            inData.seekg(0);

            }
                break;
            case 'T':{
            cout << "Enter Twitter name to search for: ";
                cin.ignore(10000,'\n');
                getline(cin, searchSocialM);

                normalSearchSocialM = NormalizeString(searchSocialM);     // Convert name to all uppercase

                // Loop through all records in the file
                while (bookEntry < bookSize){

                normalSocialM = NormalizeString(singleEntry[bookEntry].socialmedia.twitter);   // Convert retrieved string to all uppercase

                if (DebugS){
                    cout << "Debug-SearchSocialMedia-#1" << endl;
                    cout << "normalSocialM: " << normalSocialM << endl;
                    cout << "normalSearchSocialM " << normalSearchSocialM << endl;
                }

                if (normalSocialM == normalSearchSocialM) { // Requested name matches
                    PrintRecord(singleEntry, bookEntry);
                    cout << "Look for More with same Twitter (M), Or is this the correct entry? (Y/N)";
                    cin >> choice;
                    choice = toupper(choice);
                    cout << endl;

                    if (choice == 'Y') {
                        found = true;
                        break;
                    }
                    // Added more flag to remove not found Message when looking for more than one entry
                    if (choice == 'M'){
                    more = true;
                    }


                }
                bookEntry++;
            }

            // Matching name was found before the end of the file
            if (bookEntry < bookSize){
                cout << "Record found: " << endl;
                PrintRecord(singleEntry, bookEntry);
                cout << endl;
            }
            else if (!found && more != true)   // End of file. Name not found.
            {
                cout << searchSocialM << " not found!" << endl << endl;
            }
            if (found == true && (UpdateorDelete == 'U' || UpdateorDelete == 'D' )){
                        if (UpdateorDelete == 'U'){
                            Update(singleEntry, bookSize, bookEntry, 'T', filename);
                        }
                        else if (UpdateorDelete == 'D'){
                             RmEntry(singleEntry, bookSize, bookEntry, filename);   //Add call to Delete function
                        }
            }       // Add option to update or delete entry here
            // Clear file fail state and return to beginning
 //           inData.clear();
 //           inData.seekg(0);
            }
                break;
            case 'X':
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }
}

