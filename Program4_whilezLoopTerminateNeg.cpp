//Write a program that reads a list of double-precision grades from the keyboard into an array named grade.
//The grades are counted as they're entered and entry should be terminated when a negative value has been entered.
//After all grades have been input, the program should display the sum and average of the grades.
//Optional feature: The grades should be listed with an asterisk (*) placed in front of each grade that is below the average.)
//HIEU HAU
//05/04/2016
//Professor: Davis Scott

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Prototype declarations
double getGrades(double grades[]);
void PrintArray(const double grades[], int totalGrades, double average);
double sumArray(const double grades[], int totalGrades);
double getaverage(const double grades[],int totalGrades, double sum);

const int ARRAY_SIZE=150;//Declare Array size-hold up to 150

int main()
{
    //Declare variables
    double grades[ARRAY_SIZE];
    double sum=0;
    double average;
    int totalGrades=getGrades(grades);

    sum= sumArray(grades,totalGrades);
    cout<< "SUM of the grades is: "<<sum<<endl;

    average=getaverage(grades, totalGrades,sum);
    cout<< "AVERAGE of the grades is: "<<average<<endl;

    PrintArray(grades,totalGrades,average);
    cout<<endl;

    return 0;
}

//User enters grades
//post:grades are assigned
double getGrades(double grades[])
{
    int totalGrades=0;
    double val;
    cout<< "This application will calculate sum of your grades and determine the average."<<endl;
    cout<< "Input your grades. Enter a negative number to terminate the entry."<<endl;
    cout<< "Enter a grade: ";
    cin>> val;

    while (val>0)//Loop test negative input to terminate entry
   {
        grades[totalGrades] = val;
        totalGrades++;
        cout<< "Enter a grade: ";
        cin>> val;
   }

 return totalGrades;
}

//Print grades
//Pre: grades are assigned
//Post: grades are printed
//The grades should be listed with an asterisk (*) placed in front of each grade that is below the average
void PrintArray(const double grades[], int totalGrades,double average)
{
    cout<< "The grades entered are:"<<endl;
    for (int i=0; i<totalGrades;i++)
    {
        if (grades[i]<average)
            cout<< "Grade " <<i+1<< ":*"<< grades[i]<<endl;
        else
            cout<< "Grade " <<i+1<<": "<< grades[i]<<endl;

    }
}

//Calculate Sum
//Pre: grades are assigned
//Post: sum=addition of total of all grades entered and not include negative number
double sumArray(const double grades[], int totalGrades )
{
    double sum=0;
    for (int i=0; i<totalGrades; i++)
    {
        sum=sum+ grades[i];
    }
return sum;
}

//Determine Average
//Pre: grades are assigned
//Post: average=(sum / number of all grades entered) and not include negative number
double getaverage(const double grades[],int totalGrades, double sum)
{
    double average;
    for (int i=0;i<totalGrades;i++)
    {
        average=sum/totalGrades;
    }
 return average;
}

