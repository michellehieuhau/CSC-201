// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddressBook.h"

using namespace std;

/* NormalizeString
 Convert passed string to all upper case and return result
 string variable str is passed by value (in)
 */
string NormalizeString(string str)
{
    string nString = str;
    unsigned int i;

    for (i = 0; i < str.size(); i++)
    {
        nString[i] = toupper(str[i]);
    }

    return nString;
}

/* TrimSpaces
 Remove any leading or trailing spaces from given string
 string variable str is passed by value (in)
 */
void TrimSpaces(string& str)
{
    unsigned int index;

    index = str.find_first_not_of(" \t");
    str.erase(0, index);

    index = str.find_last_not_of(" \t");
    if (string::npos != index)
        str.erase(index + 1);
}

// **Not used**
/* PurgeLines
Read and discard a specified number of lines from a given file
inData is passed by reference (in/out), numLines is passed by value (in)
*/
void PurgeLines(ifstream& inData, int numLines)
{
    string buffer;

    for (int i = 0; i < numLines; i++)
        getline(inData, buffer, '\n');
}
