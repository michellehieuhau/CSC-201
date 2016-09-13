//Compute a car's miles per gallon and convert into metric system
//Hieu Hau
//CSC 110
//Instructor: Scott Davis
//Program 1
#include <iostream>
#include <iomanip> // for setw and setprecision
 using namespace std;

 const float ONE_GALLON_IN_LITERS = 3.7854;  //Declare constants
 const float ONE_MILES_IN_KILOMETERS = 1.609344;
 int main()
{
    float milesDriven; // Measured in miles
    float gallonsOfGasUsed; // Measured in gallons

    float milesDrivenInKm;
    float gallonOfGasUsedInLiters;

    float milesPerGallon;
    float kmPerL;

    cout << fixed << showpoint;
//Ask the user for the miles driven
    cout<< "How many miles have your driven? please enter here:";
    cin>> milesDriven;
//Ask the user for gallon of gas used
    cout<< "Enter the number of gallon of gasoline used:";
    cin>> gallonsOfGasUsed;
//convert into metric system
    milesDrivenInKm = milesDriven* ONE_MILES_IN_KILOMETERS;
    gallonOfGasUsedInLiters = gallonsOfGasUsed * ONE_GALLON_IN_LITERS;
// Show the conversion
    cout<< "Miles driven in Kilometers:"<< setw(8) << setprecision(2) << milesDrivenInKm<< endl;
    cout<< "Gallon of gasoline used in Liters:"<< setw(8) << setprecision(2) << gallonOfGasUsedInLiters << endl;

// Calculate miles per gallon
    milesPerGallon = int (milesDriven/gallonsOfGasUsed);
//Display result to user
    cout<< "Miles Per Gallon is:" << setw(8) << setprecision(0)<< milesPerGallon<< endl;
// calculate Km per liter
    kmPerL = int (milesDriven* ONE_MILES_IN_KILOMETERS)/(gallonsOfGasUsed * ONE_GALLON_IN_LITERS);
    cout<< "Kilometer Per Liter is:" << setw(8) << setprecision(0) << kmPerL<< endl;

return 0;

}

