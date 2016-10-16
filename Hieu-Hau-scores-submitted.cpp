//Student: Hieu Hau
//Grade Calculator
//Version: 1.0.1
//Date: 10/11/2016
//****************************************************************************************
//This programs computes grades from a given file
//              and print out as a percentage (round up nearest whole number),
//              each student's grade(up to 5 decimal places)
//              and evaluate the result based on the grade.
//****************************************************************************************
#include <iostream> //Header for I/O
#include <fstream>      //Header for access file I/O function
#include <cmath>            //Header for ceil() function
#include <iomanip>              //Header for manipulators
#include <cstdlib>                  //Header for exit()

using namespace std;

void PrintLastName(string);
void PrintPercentage(double, double);

int main()
{
    //Declaring input variables
    string lastName;
 	double score, Total_Score;

    //Declaring File streams
	ifstream inFile;
	inFile.open ("scores.txt"); // open the scores.txt file

	//Check for existing file
	if (!inFile)
	{
		cerr << "File does not exist"<<endl;
		exit(1);
	}


    //loop to continue get all information in the input file to the end of file
    while (!inFile.eof())
    {   inFile>>lastName>>score>>Total_Score;

        PrintLastName(lastName); //call the function to print out student's last name

        PrintPercentage(score,Total_Score); //call the function to out student's percentage,grade,and evaluation

    }

   inFile.close();//Closing streams

return 0;
}
//****************************************************************************************
//Print last name function
//Inputs: lastName
//Outputs: lastName
//****************************************************************************************
void PrintLastName(string lastName)
{
    cout<<lastName<<" ";
}
//****************************************************************************************
//Computing grades and printing out grades and percentages function
//Inputs: students' score, total score
//Outputs: Percentage, grade, and evaluation
//****************************************************************************************
void PrintPercentage(double score, double Total_Score)
{
    double grade;
    int percentage;

    string evaluation;
    //Compute grade and grade percentage
    grade=score/Total_Score;
    percentage=ceil(grade*100);//ceil() round up to the nearest whole number

    //Conditions to display the evaluation based on student's grades
    if (percentage>90)
        evaluation="Excellent";
    else if (percentage>80)
        evaluation="Well Done";
    else if (percentage>70)
        evaluation="Good";
    else if (percentage>=60)
        evaluation="Need Improvement";
    else
        evaluation="Fail";
    //Print out the grade percentage (rounded up to the nearest whole number)
    //and student's grade (5 decimal places)
    cout<< percentage<<"% "
            <<fixed<<setprecision(5)<<grade<<" "
                <<evaluation<<endl;

}
