//This program will tell users whether the integer value they enter is negative or positive, even or odd
//Check input value
//repeating the process until the user want to stop
//Hieu Hau
//CSC 110
//Professor: Davis Scott
//Program 3

#include <iostream>
#include <cctype>
using namespace std;

int getValue();
void testValue(int);

int main()
{
    //Declare input variables
    int x; //number entered by user
    char response; //input yes or no from the user

    do{
        x=getValue();
        testValue(x);
        do
        {
            cout<<"Would you like to enter another number? (Y or N): ";//Ask user try another number
            cin>>response;//read values
            cin.ignore(10000, '\n');
            response = toupper(response);
        } while (response!= 'Y'&& response!='N'); // Repeating the process if the user does not say Y or N

    }while (toupper(response)== 'Y');

        cout<<"OK. Goodbye"<<endl; // end the program when user say No

return 0;

}
//function get a number from user and checking for valid input
int getValue(){

    int x; //number entered by user
    char response; //input yes or no from the user
    bool inputValid;// flag for checking for input validation

    do {
        cout<< "Please, enter a number :"; //Ask the user for entering a number
        cin>> x;
        cin.ignore(10000, '\n'); //Clear remainder of line input
        if(cin)
        {
            inputValid =true;
        }
        else //if invalid, clear and reset fail state and clear input stream
        {
            inputValid =false;
            cout<<"Input must be an integer!"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (!inputValid);
return x;
}
//function to test the input value
void testValue(int x){

        if (x>=0)
            cout<< x << " is positive"<<endl;//If condition is true then print the following

        else
            cout<< x << " is negative"<<endl;//If condition is false then print the following

        if (x%2==0)
            cout<< x << " is even"<<endl; //If condition is true then print the following

        else
            cout<< x << " is odd"<<endl;//If condition is false then print the following

}



