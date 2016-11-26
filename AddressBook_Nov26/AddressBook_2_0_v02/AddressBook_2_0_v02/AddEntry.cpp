// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <fstream>
#include "AddRecord.h"
#include "WriteRecord.h"
#include "OpenFile.h"
#include "Get.h"

using namespace std;
/*AddEntry
function allows user to add new information into the addressbook
ifstream inData is passed by reference(in/out), string filename is passed by value (in)
*/
void AddEntry(entryType singleEntry[], int& bookSize, string filename)
{
    //entryType userRecord;      // structure type data
    ofstream outData;
    ifstream inData;         // for input file

    AddRecord(singleEntry, (bookSize+1));

//    inData.close();
    outData.open(filename.c_str(), fstream::app);   // appending new data to file

    WriteRecord(outData, singleEntry, (bookSize+1));
    outData.close();

    // update Array with new entry
    inData.open(filename.c_str());

        if (!inData)
            cout << "File not found!" << endl;

    int bookEntry = 0 ;

        while (GetRecord(inData, singleEntry, bookEntry)){

            bookEntry++;
        }
    bookSize = bookSize+1; // need to update booksize over all

}

