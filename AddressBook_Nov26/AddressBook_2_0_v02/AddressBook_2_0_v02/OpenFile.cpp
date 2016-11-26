// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/* OpenFile
Prompts user for a file name, check if file exists, if file does exist then open file
filename and inData are passed by reference (in/out)
*/
// Debug flag added for easy trouble shooting during dev.
bool DebugOpenFile = false;

void OpenFile(string& filename, ifstream& inData)
{
    do {
        cout << "Enter file name to open: ";  // test file is called "new"
        cin >> filename;

        inData.open(filename.c_str());

        if (!inData)
            cout << "File not found!" << endl;

        if (DebugOpenFile){
            if (inData)
                cout << "Debug-OpenFile-#1" << endl;
        }

    } while (!inData);
}
