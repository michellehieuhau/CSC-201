//This program that declares two arrays each holding five float values in the main function.
// The program should also have a function called InitArray that accepts two parameters,
//an array along with an array size, and sets values in the function by reading them from the user.
// Finally, the program should have a function named SumArray that takes an array as a parameter and
//returns the sum of all the elements in the array.
// Call the two functions from main and display the resulting sum.
//HIEU HAU
//4/25/2016

#include <iostream>
#include <cstdlib>

using namespace std;
//Prototype declarations
void InitArray(float someArray[], const int ARRAY_SIZE);
void sumArray(float someArray[],  const int ARRAY_SIZE, float& sum);

//Declare Array size
const int ARRAY_SIZE=5;

int main()
{
    //Declare variables and arrays
    float array1[ARRAY_SIZE];
    float array2[ARRAY_SIZE];
    float sum1=0, sum2=0;


    InitArray(array1,ARRAY_SIZE);
    InitArray(array2,ARRAY_SIZE);


    sumArray(array1,ARRAY_SIZE,sum1);
    sumArray(array2,ARRAY_SIZE,sum2);

      //Print out the array 1
    cout << "Array 1 is: "<<'{';
    for(int m=0;m<ARRAY_SIZE;m++)
    {
        cout<< array1[m]<< " ";
    }
    cout<< '}'<<endl;
     //Sum of the array 1's values
    cout<< "Sum of array 1 is:"<< sum1<<endl;

      //Print out the array 2
    cout<< "Array 2 is: "<<'{';

    for(int m=0;m<ARRAY_SIZE;m++)
    {
        cout<< array2[m]<< " ";
    }
    cout<< '}'<<endl;
     //Sum of the array 2's values
    cout<< "Sum of array 2 is:"<< sum2<<endl;
return 0;
}

//user enters numbers
//pre:numbers are float
//post:5 float numbers of each array
void InitArray(float someArray[], const int ARRAY_SIZE)
{
    int m;
    for(m=0; m<ARRAY_SIZE; m++)
    {
    cout<< "Enter No."<<m+1<< ":";
    cin>> someArray[m];
    }
}
//Calculate Sum
void sumArray(float someArray[],  const int ARRAY_SIZE, float& sum)
{
     int m;
     for(m=0; m<ARRAY_SIZE; m++)
    {
        sum+=someArray[m];
    }

}
