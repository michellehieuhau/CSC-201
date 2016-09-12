//Hieu Hau
//Program 1
//Professor:
//******************************************************************
// Chessboard program
// This program prints a chessboard pattern that is built up from
// basic strings of white and black characters.
//******************************************************************
#include <iostream>
#include <string>

using namespace std;

const string BLACK = "########"; // Define a line of a black square
const string WHITE = "        "; // Define a line of a white square

int main ()
{
    int count =0; // number for deciding which row to be printed
    for (int row=0; row< 8; row++)// number of rows in a chess board
    {
        if (count==0)
        {
            for (int square=0; square<5;square++)// square size row under each other
            {
                for (int col=0;col<4;col++) //number of columns in chess board
                {
                    cout<<WHITE<<BLACK;
                }
            cout<<endl;
            }
        }
        else
        {
            for (int square=0; square<5;square++)
            {
                for (int col=0;col<4;col++)
                {
                    cout<<BLACK<<WHITE;
                }
            cout<<endl;
            }
        }
        count++;
        if (count==2)
        count =0;
    }
return 0;
}



