//******************************************************
// LeapYear program
// This program inputs a year and prints whether the year
// is a leap year or not
//if it is not a leap year, it will tell when the next leap year will be
//******************************************************
#include <iostream>		// Access output stream

using namespace std;       // Access cout, endl, cin

bool IsLeapYear(int);	// Prototype for subalgorithm

int main()
{
    int year;			// Year to be tested
    bool flag;

    cout << "Enter a year AD, for example, 1997."
         << endl;  		// Prompt for input
    cin >> year;      	// Read year

    if (IsLeapYear(year))      	// Test for leap year
        cout << year << " is a leap year."  << endl;
    else
        {
        cout << year << " is not a leap year."  << endl;
        flag=false;
        while(!flag)
            {
                year+=1;
                flag= IsLeapYear(year);
            }
        cout<< year<< " is the next leap year";

        }

    return 0;        // Indicates successful
					//  completion
}

bool IsLeapYear(int year)
// IsLeapYear returns true if year is a leap year and
// false otherwise
{
    if(year % 4 != 0)        // Is year not divisible by 4?
        return false;         // If so, can't be a leap year
    else if(year % 100 != 0) // Is year not a multiple of 100?
        return true;          // If so, is a leap year
    else if(year % 400 != 0) // Is year not a multiple of 400?
        return false;	     	// If so, then is not a leap year
    else
        return true;        	// Is a leap year
}
