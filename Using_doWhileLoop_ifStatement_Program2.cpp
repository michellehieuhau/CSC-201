

//This program will tell users whether the integer value they enter is negative or positive, even or odd, repeating the process until the user want to stop
//Hieu Hau
//CSC 110
//Professor: Davis Scott
//Program 2

#include <iostream>

using namespace std;
int main()
{
    //Declare input variables
    int x;
    char ch;

    do
    {
        cout<< "Please, enter a number (integers only):"; //Ask the user for entering a number
        cin>> x;

        if (x>=0)
            cout<< x << " is positive"<<endl;//If condition is true then print the following

        else
            cout<< x << " is negative"<<endl;//If condition is false then print the following

        if (x%2==0)
            cout<< x << " is even"<<endl; //If condition is true then print the following

        else
            cout<< x << " is odd"<<endl;//If condition is false then print the following

        cout<<"Would you like to enter another number? (Y or N): ";//Ask user try another number

        cin>>ch;//read values
    }
    while (ch== 'Y'|| ch=='y'); // Repeating the process if the user say yes

        cout<<"OK. Goodbye"<<endl; // end the program when user say No

return 0;

}






