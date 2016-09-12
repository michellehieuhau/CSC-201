#include <iostream>
#include <cmath>	       // Access power function
#include <iomanip>		// Access manipulators

using namespace std;

float CalcPayments(float,int);
void PrintPaymentInfo(float payment);

const float LOAN_AMOUNT = 50000.00;  // Amount of loan
const float YEARLY_INTEREST = 0.0524;// Yearly interest
const int NUMBER_OF_YEARS = 7;	    // Number of years

int main()
{
    // Local variables
    float monthlyInterest;	// Monthly interest rate
    int numberOfPayments;  // Total number of payments
    float payment;	       // Monthly payment

    payment = CalcPayments(monthlyInterest, numberOfPayments);

    return 0;
}

float CalcPayments(float monthlyInterest, int numberOfPayments){
    float payment;	       // Monthly payment

   // Calculate values
    monthlyInterest = YEARLY_INTEREST / 12;

    numberOfPayments = NUMBER_OF_YEARS * 12;

    payment =(LOAN_AMOUNT *
        pow(monthlyInterest + 1, numberOfPayments)
        * monthlyInterest)/(pow(monthlyInterest + 1,
        numberOfPayments) - 1);

    PrintPaymentInfo(payment);

    return payment;
}

void PrintPaymentInfo(float payment){
// Output results
    cout << fixed << setprecision(2)
         << "For a loan amount of "
         << LOAN_AMOUNT  << " with an interest rate of "
         << YEARLY_INTEREST << " and a "
         << NUMBER_OF_YEARS
         << " year mortgage, " << endl;
    cout << " your monthly payments are $" << payment
         << "." << endl;
}
