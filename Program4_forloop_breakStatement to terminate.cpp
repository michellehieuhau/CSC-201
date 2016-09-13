//Write a program that reads a list of double-precision grades from the keyboard into an array named grade.
//The grades are counted as they're entered and entry should be terminated when a negative value has been entered.
//After all grades have been input, the program should display the sum and average of the grades.
//Optional feature: The grades should be listed with an asterisk (*) placed in front of each grade that is below the average.
//HIEU HAU
//05/04/2016
//Professor: Davis Scott

#include <iostream>
#include <cstdlib>

using namespace std;
double getGrades(double[] );
void PrintArray(const double [], int ,double);
double sumArray(const double[] , int );
double getaverage(const double[],int,double);

const int ARRAY_SIZE=100;//Declare Array size-hold up to 150

int main()
{
    double grades[ARRAY_SIZE];
    double sum=0;
    double average;

    int totalGrades= getGrades(grades);


    sum= sumArray(grades,totalGrades);
    cout<< "SUM of the grades is: "<<sum<<endl;

    average=getaverage(grades, totalGrades,sum);
    cout<< "AVERAGE of the grades is: "<<average<<endl;

    PrintArray(grades,totalGrades,average);
    cout<<endl;

return 0;
}

//User enters grades
//pre:grades>0 and a negative number terminate the entry
//post:grades are assigned and a negative number stops the entrydouble getGrades(double grades[])
{
    int totalGrades;
    for (totalGrades=0;totalGrades<ARRAY_SIZE;totalGrades++)
   {
        double val;
        cout<< "Enter a grade: ";
        cin>> val;
         // test negative input to terminate entry
         if (val <0)
         {
             break;
         }

        grades[totalGrades] = val;
   }

 return totalGrades;
}
//Print grades
//Pre: grades are assigned and grades>0
//Post: grades are printed one each line and not include negative number.
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

double sumArray(const double grades[], int ARRAY_SIZE)

{
    double sum=0;
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        sum=sum+ grades[i];
    }
return sum;
}

//Determine Average
//Pre: grades are assigned and grades>0
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

