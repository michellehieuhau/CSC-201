//***********************************************************
// Group #3
// Date: 		9/28/16
// Version:     1.3
// Names: 		Jeremy, Madeline, Eddie, Hieu, Robert
// Inputs: 		Numbers
// Outputs: 	The median of numbers
// Description: This program finds the median of input
//				numbers and tells the user the median
//
//***********************************************************

#include <iostream>

bool checkInputValid(bool);		// Checks validity of input

using namespace std;

int main()
{
	// Declare variables and initialize number array
	float md, buffer;
	float num[10000];
	bool flag;
	int n;

	// Ask the user for amount of numbers
	do
	{
		cout << "Please enter how many numbers are to be input: ";
		cin >> n;
	} while (!checkInputValid(flag));

	// Continue asking user for input until valid
	for (int i=0; i<n; i++)
	{
		do
		{
			// Ask the user for a number until it is valid
			cout << "Enter #" << i+1 << ": ";
			cin >> num[i];
		} while (!checkInputValid(flag));
	}

	// Set the array in ascending order
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (num[i] < num[j])
			{
				buffer = num[i];
				num[i] = num[j];
				num[j] = buffer;
			}

	// Find the median of the numbers
	// If number of input is even, median is the average of the two middle numbers
	if (n%2 == 0)
		md = (num[n/2-1]+num[n/2])/2.;
	else
		md = num[n/2];

	cout << "Median: " << md;

	return 0;
}
//***********************************************************
// Check Input Validation Function
// Inputs: Console input
// Outputs: Validity of input
// Description: This function checks if the previous input is
// 		        valid or invalid and returns a boolean
//		        depending on the validity.

bool checkInputValid(bool flag)
{
    flag = cin;
    if (!flag)
    {
        cout << "Input invalid. Please enter a proper number." << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    return flag;
}
