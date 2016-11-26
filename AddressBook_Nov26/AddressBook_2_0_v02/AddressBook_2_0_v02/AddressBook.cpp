// The AddressBook 2.0 - main.cpp
// Hoa Nguyen, Jason Creek, and Alexander Sigrist
// 11/19/2016
// CSC 201
// Version 2.3  program #5
// Program allows for adding data to a file related to, print the data from and search data in the address book
// Jason Creek : write the search function, finish missing code, debug, and refactor the program
// Hoa Nguyen : write the function for adding new data, add comments to and review the program

#include <iostream>             // for cin and cout
#include <fstream>              // for file I/O
#include "AddressBook.h"        // for all header  files
#include "OpenFile.h"
#include "MainMenu.h"
#include "AddEntry.h"
#include "WriteRecord.h"
#include "AddRecord.h"
#include "Print.h"
#include "Search.h"
#include "Get.h"
#include "Manip.h"

using namespace std;

int main()
{
    entryType singleEntry[20]; // type v 2.0
    //entryType userRecord;    // for structure type data
    string filename;         // for the input file name
    ifstream inData;         // for input file
    int bookSize = 0;       // used to track booksize


    OpenFile(filename, inData);  // test file is called "new"


    // Version 2.0 Get Data Jason Creek
    // Get data into array
    int bookEntry=0;
        while (GetRecord(inData, singleEntry, bookEntry)){
            bookEntry++;
        }
        bookSize = bookEntry;

    MainMenu(singleEntry, bookSize, filename);

    return 0;
}



