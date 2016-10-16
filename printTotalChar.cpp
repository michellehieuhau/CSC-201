//********************************************************************************************************
// CSC 201 - Computer Science I
// Developed by Hieu Hau
// Version: 1.0.1
// Date: 10/1/2016
// Inputs:
//          Output file name
// Outputs:
//          Output file with number of characters
// Description: Given an input file "list.txt", this program counts the
//              number of characters in the file and adds a line beneath
//              the file that tells how many characters are in the file.
//********************************************************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //some compilers need to include this header in order to use exit(1)

using namespace std;

int main()
{
	//Declaring File streams
	ifstream inFile;
	inFile.open ("list.txt"); // open the list file
							 //	inFile.open(list.c_str()); another way to open the list file
	//Check for error
	if (inFile.fail())  //nameoftheobject.fail() funtion check to see file exist
	{
		cerr << "Error opening file"<<endl; //instead  of using cout , we can use cerr for error message
		exit(1);
	}


	char item;
	int count =0;

	//Read a file until you've reach the end -using while loop.
	//This print out the numbers of item in the list file

	while (!inFile.eof()) // using not operator ! object.eof() end of file function
	{
	    inFile>>item;//access the object
		count++ ;
	}
	cout<<count<<" characters found"<<endl;

	// Close files so wont cause error
    inFile.close();

    //Declaring File streams

	ofstream outFile; //open
	outFile.open("list.txt");

	outFile<<endl<<"The number of characters in this file are "<<count;

	outFile.close();


	return 0;
}
