//Program that will get 2 numbers from users and ask them if they would like to add, subtract, multiply, or divide 2 numbers.
//The program should repeat until the user wants to exit.
//HIEU HAU
//CSC110-Calculator
//Professor : Davis Scott
//04/18/2016

#include <iostream>
#include <cctype>

using namespace std;

void getNums(float&, float&);
void getOperation(char&);
float calcResult(float, float, char);

int main()
{
    //Define variables
    float num1,num2,result;
    char operation, response= 'N';
    //Loop
    do
    {
        getNums(num1, num2); //Prompt user for two numbers
                        // OUT variables (pass by reference)
        getOperation(operation); //Get the operation to be performed from the user
                            //OUT variable (passed by reference)
        result= calcResult(num1, num2, operation); //Get result based on previous input
                                        // IN variable (pass by value)
    //Display result
    cout<<result<<endl;
        //ASk user if they want to repeat
        //Loop test if the user enters other than Y and N
        do
        {
            cout<<"Do you want to continue? (Y/N)";
            cin>>response;
            response= toupper(response);
        }while (response!= 'Y'&& response!='N');

    } while(response !='N');
    cout << "Have a nice day!";
    return 0;
}

void getNums(float& num1, float& num2){

    bool inputValid;// flag for checking for input validation
    //Loop test if the user enters invalid input
    do{
        cout<< "Please, enter two numbers:"; //Ask the user for entering a number
         cin>>num1>>num2;
        cin.ignore(10000, '\n'); //Clear remainder of line input

        if(cin)
            inputValid=true;
        else //if invalid, clear and reset fail state and clear input stream
        {
            inputValid= false;
            cout<<"Input must be numbers!"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!inputValid);

}

 void getOperation(char& operation){

    //Prompt user for the operation
     cout<<"Would you like to add, subtract, multiply or divide your input numbers:"<<endl;

    //Select operation based on user input
     cout <<"Enter (+)addition, (-)subtraction,(*)multiplication or (/)division:";
     cin>>operation;
     cin.ignore(10000,'\n');

    //Loop test if user enters an invalid operation
    while (operation!= '+' &&operation!= '-' &&operation!= '*' &&operation!= '/' )
    {
        cout<< "Invalid input. Must enter +,-,* or /:"<<endl;
        cin>> operation;
        cin.clear();
        cin.ignore(10000, '\n');
    }
 }

 float calcResult(float num1, float num2,char operation){

    float result;
    char response;

        switch (operation) //Perform operation based on user input
         {
            case '+' :
               result=num1+num2;
                break;
            case '-' :
                result=num1-num2;
                break;
            case '*' :
                result=num1*num2;
                break;
            case '/' :
                result=num1/num2;
                break;
            default :
                cout<< "Enter +,-,* or /:"<<endl;
         }

    return result;
 }



