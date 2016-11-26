// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddEntry.h"
#include "Print.h"
#include "Search.h"

using namespace std;
/* MainMenu
Ask user to select an option, and process the information from the file according to user's choice
inData is passed by reference (in/out), filename is passed by value (in)
*/
void MainMenu(entryType singleEntry[], int& bookSize, string filename)
{
    char menuOption;

    do {
        cout << endl;
        cout << "Select an option..." << endl;
        cout << "(A)dd entry, (P)rint, (S)earch, (U)pdate, (D)elete, e(X)it: ";
        cin >> menuOption;
        menuOption = toupper(menuOption);

        switch (menuOption) {
            case 'A':
                AddEntry(singleEntry, bookSize, filename);
                break;
            case 'P':
                PrintAddressBook(singleEntry, bookSize);
                break;
            case 'S':
                SearchMenu(singleEntry, bookSize, 'S', filename);
                break;
            case 'U':
                SearchMenu(singleEntry, bookSize, 'U', filename);
                break;
            case 'D':
                SearchMenu(singleEntry, bookSize, 'D', filename);
            case 'X':
                cout << "Ok. Goodbye!";
                break;
            default:
                cout << "Invalid option selected!" << endl;
                break;
        }

        // Clear file fail state and return to beginning
//        inData.clear();
//        inData.seekg(0);

    } while (menuOption != 'X');
}

