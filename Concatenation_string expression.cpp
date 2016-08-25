//Hieu Hau
//Last update 08/25/2016
//practice concatenation, string expression

#include<iostream>
#include<string>
using namespace std;


int main()
{

   string firstName,lastName,fullName;
   // declare strings without initialization
   //guarantee that the variable will be initialized to an empty string(a string containing zero characters)
   string statement;
   string stat1= "Have";//without a space at the end
   string stat2= " good day"; //with a space before good
   const char exclaim= '!';

   cout<< "Enter your first name:";
   getline(cin, firstName); //read a whole line into the string name
   cout<< "Enter your last name:";
   getline(cin, lastName);

   fullName= firstName + lastName;
   statement= stat1;
   statement += ' '; //append a space between 2 strings by using += operator
   statement += "a" +stat2+ "," +fullName +exclaim;
   //At least one of the operands of the + operator must be a string variable or named string constant
   //--the other operand can be a string literal or a char variable, literal, or constant

   cout<< statement<<endl;

return 0;
}

