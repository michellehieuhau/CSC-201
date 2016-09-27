
//This program will tell users whether the integer value they enter is negative or positive, even or odd
//Check input value
//repeating the process until the user want to stop
//Hieu Hau
//CSC 110
//Professor: Davis Scott
//Program 3

#include <iostream>
#include <cctype>

void printValue(int);//priting funtion prototype
void checkInputValue(int); //checking for valid input prototype
using namespace std;
bool inputValid;// flag for checking for input validation
int main()
{
    //Declare input variables
    int x; //number entered by user
    char response; //input yes or no from the user


    do
    {
        do
        {
            cout<< "Please, enter a number:"; //Ask the user for entering a number
            cin>> x;
            cin.ignore(10000, '\n');
            checkInputValue(x);

        } while (!inputValid);

        printValue(x);
        do
        {
            cout<<"Would you like to enter another number? (Y or N): ";//Ask user try another number
            cin>>response;//read values
            cin.ignore(10000, '\n');
            response = toupper(response);
        } while (response!= 'Y'&& response!='N'); // Repeating the process if the user does not say Y or N

    } while (toupper(response)== 'Y');
        cout<<"OK. Goodbye"<<endl; // end the program when user say No

return 0;

}
//checking for valid input
void checkInputValue(int x){

            if(cin)
                inputValid=true;
            else
            {
                inputValid= false;
                cout<<"Input must be an integer!"<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
}

void printValue(int x){

        if (x>=0)
            cout<< x << " is positive"<<endl;//If condition is true then print the following

        else
            cout<< x << " is negative"<<endl;//If condition is false then print the following

        if (x%2==0)
            cout<< x << " is even"<<endl; //If condition is true then print the following

        else
            cout<< x << " is odd"<<endl;//If condition is false then print the following

}



