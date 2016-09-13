//This program asks users to enter 10 numbers and display them as 2 arrays.
//Calculate sum of each array and compare if two arrays contain equivalent elements
//HIEU HAU
//04/24/2016
//Professor: Davis Scott

#include <iostream>
#include <cstdlib>

using namespace std;
//Prototype declarations
void InitArray(float someArray[], const int ARRAY_SIZE);
void PrintArray(const float someArray[] ,int ARRAY_SIZE);
void sumArray(float someArray[],  const int ARRAY_SIZE, float& sum);
bool CompareArrays( const float array1[],const float array2[],  int ARRAY_SIZE);

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
    cout<< "Array 1 is:"<< '{';
    PrintArray(array1, ARRAY_SIZE);
    cout << '}'<<endl;
    //Sum of the array 1's values
    cout<< "Sum of array 1 is:"<< sum1<<endl;
    //Print out the array 2
    cout<< "Array 2 is:"<< '{';
    PrintArray(array2, ARRAY_SIZE);
    cout << '}'<< endl;
    //Sum of the array 2's values
    cout<< "Sum of array 2 is:"<< sum2<<endl;

    //Compare 2 array whether or not they are the same
    if(CompareArrays(array1,array2,ARRAY_SIZE))
    {
        cout<< "Two arrays have the same numbers"<<endl;
    }
    else
        cout<< "Two arrays have different numbers"<<endl;

return 0;
}
//user enters numbers
//pre:numbers are float
//post:5 float numbers of each array
void InitArray(float someArray[],const int ARRAY_SIZE)
{

    for(int m=0; m<ARRAY_SIZE; m++)
    {
    cout<< "Enter No."<<m+1<< ":";
    cin>> someArray[m];
    }
}
// Print out the contents of an array
// Pre: Valid array and number of elements in the array
// Post: Prints array contents
void PrintArray( const float someArray[] , const int ARRAY_SIZE)
{
    for (int m=0; m<ARRAY_SIZE;m++)
    {
          cout<< someArray[m]<< " ";
    }
}
//Calculate Sum
void sumArray(float someArray[], const int ARRAY_SIZE, float& sum)
{
     for(int m=0; m<ARRAY_SIZE; m++)
    {
        sum+=someArray[m];
    }

}

// Compares if two arrays contain equivalent elements and returns true or false
// Pre: Both arrays contain the same number of elements,that number is in the third parameter
// Post: Returns true if the arrays are equal, false otherwise
bool CompareArrays( const float array1[],const float array2[],  const int ARRAY_SIZE)
{
    bool sameVal= true;
    for(int m=0;m<ARRAY_SIZE;m++)
    {
        if (array1[m]==array2[m])
        {
            sameVal=true;
        }
        else
            sameVal=false;
    }
return sameVal;
}


