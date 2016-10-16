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

bool checkInputValue();
using namespace std;

int main ()
{
    //Declare input variables
    float n1,n2,n3,md;
    bool flag;

    // COntinute asking user for valid input
    do
    {

        //Ask the user for entering numbers
        cout<< "Please, enter three numbers:";
        cin>> n1>>n2>>n3;

        cin.ignore(10000, '\n');
    } while (!checkInputValue);

    // Find the order of the numbers to determine median
    // If the first number is less than the second: n1, n2
    // 		If the second number is less than the third: n1, n2, n3
    //		If the first number is less than the third: n2, n1, n3
    //		Otherwise: n2, n3, n1 or n3, n2, n1

    md = (n1<n2)? ((n2<n3)? n2: ((n1<n3)? n3:n1) ) : ((n1<n3)? n1: ((n2<n3)? n3:n2) );

    // Display median to user
  	cout << "Median: " << md;

    return 0;
}

//checking for valid input
bool checkInputValue(bool flag)
{

   flag=cin;
    if(!flag)
    {
        cout<<"Input must be numbers!"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return flag;

}


/*or can write validation function like this
bool checkInputValue(){

    if(cin)
        return true;
    else
    {
        cout<<"Input must be numbers!"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
}*/
