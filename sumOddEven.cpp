/*
 * Sum the odd and even numbers, respectively, from 1 to a given upperbound.
 * Also compute the absolute difference.
 * (SumOddEven.cpp)
 */
#include <iostream>   // Needed to use IO functions
using namespace std;

int main() {
   int sumOdd  = 0; // For accumulating odd numbers, init to 0
   int sumEven = 0; // For accumulating even numbers, init to 0
   int upperbound;  // Sum from 1 to this upperbound
   int absDiff;     // The absolute difference between the two sums

   // Prompt user for an upperbound
   cout << "Enter the upperbound: ";
   cin >> upperbound;

   // Use a while-loop to repeatedly add 1, 2, 3,..., to the upperbound
   int number = 1;
   while (number <= upperbound) {
      if (number % 2 == 0) {  // Even number
         sumEven += number;   // Add number into sumEven
      } else {                // Odd number
         sumOdd += number;    // Add number into sumOdd
      }
      ++number; // increment number by 1
   }

   // Compute the absolute difference between the two sums
   if (sumOdd > sumEven) {
      absDiff = sumOdd - sumEven;
   } else {
      absDiff = sumEven - sumOdd;
   }

   // Print the results
   cout << "The sum of odd numbers is " << sumOdd << endl;
   cout << "The sum of even numbers is " << sumEven << endl;
   cout << "The absolute difference is " << absDiff << endl;

   return 0;
}
