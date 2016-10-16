#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void PrintLastName(string);
void PrintPercentage(int, int);

int main()
{
    ifstream inFile;
    string lastName;
    int stuScore;
    int totPoints;

    inFile.open("scores.txt");

    if (!inFile){
        cout << "File does not exist!";
        return -1;
    }
    else {
        inFile >> lastName >> stuScore >> totPoints;
        while (inFile){

            PrintLastName(lastName);

            PrintPercentage(stuScore, totPoints);

            inFile >> lastName >> stuScore >> totPoints;
        }
    }
    return 0;
}

void PrintLastName(string name){
    cout << name << " ";
}

void PrintPercentage(int score, int totPoints){
    float grade;
    int gradePercent;
    string message;

    grade = float(score) / float(totPoints);
    gradePercent = ceil(grade * 100);

    cout << gradePercent << "% ";
    cout << fixed << setprecision(5) << grade << " ";

    if (gradePercent > 90)
        message = "Excellent";
    else if (gradePercent > 80)
        message = "Well Done";
    else if (gradePercent > 70)
        message = "Good";
    else if (gradePercent > 60)
        message = "Need Improvement";
    else if (gradePercent < 50)
        message = "Fail";

    cout << message << endl;
}
