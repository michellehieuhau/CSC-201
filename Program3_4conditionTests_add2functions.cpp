//This program will tell users whether the integer value they enter is negative or positive, even or odd
//Check input value, add 2 more functions besides main function
//repeating the process until the user want to stop
//Hieu Hau
//CSC 110-Program 3
//Professor: Davis Scott


#include <iostream>
#include <cctype>

using namespace std;
int getValue();
void testValue(int);

int main()
{
    //Declare variables
    int x; //number entered by user
    char response; //input yes or no from the user
    bool inputValid;// flag for checking for input validation

    x=getValue();// get input from int function
    testValue(x);// print value from void function

    do {
    cout<<"Would you like to enter another number? (Y/N): ";//Ask user try another number
    cin>>response;//read values
    cin.ignore(10000, '\n');
    response = toupper(response);

    } while (response!= 'Y'&& response!='N'); // Repeating the process if the user does not say Y or N

    // Loop test for answer Yes or No
    while (toupper(response)== 'Y') // Repeating the process if the user say yes
    {
        x=getValue();// get input from int function
        testValue(x);// print value from void function

        cout<<"Would you like to enter another number? (Y/N): ";
        cin>>response;
    }

    cout<<"OK. Goodbye"<<endl; // end the program when user say No

return 0;
}

//function to get value from users and pass the value to main function
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
void testValue(int x){

    if ((x>=0) && (x%2==0)) //check the boolean condition-to test for positive and even number.
    {
        cout<< x << " is positive"<<endl; //Display result to user
        cout<< x << " is even"<<endl;
    }
    else if ((x>=0) && (x%2==1)) //Test to check for positive and odd number.
    {
        cout<< x << " is positive"<<endl;//If else if condition is true then print this
        cout<< x << " is odd"<<endl;
    }
    else if ((x<0) && (x%2==0)) //Test to check for negative and even number.
    {
        cout<< x << " is negative"<<endl; //If else if condition is true then print this
        cout<< x << " is even"<<endl;
    }
    else // Test check for negative and odd number
    {
        cout<< x << " is negative"<<endl; //If none of the conditions is true then print this
        cout<< x << " is odd"<<endl;
    }
}




