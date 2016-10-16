// Reading a text file
// IMPORTANT: Please create your own example.txt file
// This example shows combining object construction and stream opening
// Uses getline to read data from the file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
	  // read the file line by line
    while ( getline (myfile,line) )
    {
	 // output each line to the terminal
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return 0;
}
