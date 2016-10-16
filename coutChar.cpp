//------------------------------------------------------------------------
// CSC 201 - Computer Science I
// Name: Madeline Navarro
// Version: 1.0
// Date: 9/19/2016
// Inputs: Output file name
// Outputs: Output file with number of characters
// Description: Given an input file "append.txt", this program counts the
//              number of characters in the file and adds a line beneath
//              the file that tells how many characters are in the file.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inData("list.txt");
    ofstream outData;

    outData.open("list(1).txt");

    char c;
    int count=0;

    if (inData && outData)
    {
        while (inData.get(c))
        {
            outData << c;
            count++;
        }
    }
    else
    {
        cout << "Invalid file.";
        return 0;
    }

    cout << "The number of characters in the input file are " << count;

    outData << "\nThe number of characters in this file are " << count;

    inData.close();
    outData.close();
}
