/*
 * Print Size of Fundamental Types (SizeofTypes.cpp).
 */
#include <iostream>
using namespace std;

int main() {
   cout << "sizeof(char) is " << sizeof(char) << " bytes " << endl;
   cout << "sizeof(short) is " << sizeof(short) << " bytes " << endl;
   cout << "sizeof(int) is " << sizeof(int) << " bytes " << endl;
   cout << "sizeof(long) is " << sizeof(long) << " bytes " << endl;
   cout << "sizeof(long long) is " << sizeof(long long) << " bytes " << endl;
   cout << "sizeof(float) is " << sizeof(float) << " bytes " << endl;
   cout << "sizeof(double) is " << sizeof(double) << " bytes " << endl;
   cout << "sizeof(long double) is " << sizeof(long double) << " bytes " << endl;
   cout << "sizeof(bool) is " << sizeof(bool) << " bytes " << endl;
   return 0;
}

/*outputs:
sizeof(char) is 1 bytes
sizeof(short) is 2 bytes
sizeof(int) is 4 bytes
sizeof(long) is 4 bytes
sizeof(long long) is 8 bytes
sizeof(float) is 4 bytes
sizeof(double) is 8 bytes
sizeof(long double) is 12 bytes
sizeof(bool) is 1 bytes
*/
