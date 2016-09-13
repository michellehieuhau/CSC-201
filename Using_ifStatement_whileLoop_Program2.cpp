
//This program will tell users whether the integer value they enter is negative or positive, even or odd, repeating the process until the user want to stop
//Hieu Hau
//CSC 110
//Professor: Davis Scott
//Program 2

#include <iostream>

using namespace std;
int main()
{
    //Declare variables
    int x;
    char ch;

    cout<< "Please, enter a number (integers only):"; //Ask the user for entering a number
    cin>> x;

    if ((x>=0) && (x%2==0)) //check the boolean condition-to test for positive and even number.
    {
        cout<< x << " is positive"<<endl; //Display result to user
        cout<< x << " is even"<<endl;
    }
    else if ((x>=0) && (x%2==1)) //Test to check for negative and even number.
    {
        cout<< x << " is positive"<<endl;//If else if condition is true then print this
        cout<< x << " is odd"<<endl;
    }
    else if ((x<0) && (x%2==0)) //Test to check for negative and odd number.
    {
        cout<< x << " is negative"<<endl; //If else if condition is true then print this
        cout<< x << " is even"<<endl;
    }
    else // Test check for positive and odd number
    {
        cout<< x << " is negative"<<endl; //If none of the conditions is true then print this
        cout<< x << " is odd"<<endl;
    }

   cout<<"Would you like to enter another number? (Y or N): ";//Ask user try another number
   cin>>ch;
   // Loop test for answer Yes or No
    while (ch== 'Y'|| ch=='y') // Repeating the process if the user say yes
    {
        cout<< "Please, enter a number (integers only):";
        cin>> x;
        if ((x>=0) && (x%2==0)) //check the boolean condition-to test for positive and even number.
    {
        cout<< x << " is positive"<<endl; //Display result to user
        cout<< x << " is even"<<endl;
    }
    else if ((x>=0) && (x%2==1)) //Test to check for negative and even number.
    {
        cout<< x << " is positive"<<endl;//If else if condition is true then print this
        cout<< x << " is odd"<<endl;
    }
    else if ((x<0) && (x%2==0)) //Test to check for negative and odd number.
    {
        cout<< x << " is negative"<<endl; //If else if condition is true then print this
        cout<< x << " is even"<<endl;
    }
    else // Test check for positive and odd number
    {
        cout<< x << " is negative"<<endl; //If none of the conditions is true then print this
        cout<< x << " is odd"<<endl;
    }
       cout<<"Would you like to enter another number? (Y or N): ";
       cin>>ch;
    }

    cout<<"OK. Goodbye"<<endl; // end the program when user say No

return 0;

}






