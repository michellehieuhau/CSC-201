/* Test integer limits in <climits> header
The climits header (ported to C++ from C's limits.h) contains information about limits of integer type. For example,
*/
#include <iostream>
#include <climits>   // integer limits
using namespace std;

int main() {
   cout << "int max = " << INT_MAX << endl;
   cout << "int min = " << INT_MIN << endl;
   cout << "unsigned int max = " << UINT_MAX << endl;
   cout << "long long max = " << LLONG_MAX << endl;
   cout << "long long min = " << LLONG_MIN << endl;
   cout << "unsigned long long max = " << ULLONG_MAX << endl;
   cout << "Bits in char = " << CHAR_BIT << endl;
   cout << "char max = " << CHAR_MAX << endl;
   cout << "char min = " << CHAR_MIN << endl;
   cout << "signed char max = " << SCHAR_MAX << endl;
   cout << "signed char min = " << SCHAR_MIN << endl;
   cout << "unsigned char max = " << UCHAR_MAX << endl;
   return 0;
}
/*
*Header <cfloat>
Similarly, the cfloat header (ported from C's float.h) contain information
on limits for floating point numbers, such as minimum number of significant digits
 (FLT_DIG, DBL_DIG, LDBL_DIG for float, double and long double), number of bits for mantissa
 (FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG), maximum and minimum exponent values, etc.
 Try inspecting this header (search for cfloat under your compiler).
*Header <limits>
The climits and cfloat headers are ported over from C's limit.h and float.h. C++
added a new header called limits.

Outputs:
int max = 2147483647
int min = -2147483648
unsigned int max = 4294967295
long long max = 9223372036854775807
long long min = -9223372036854775808
unsigned long long max = 18446744073709551615
Bits in char = 8
char max = 127
char min = -128
signed char max = 127
signed char min = -128
unsigned char max = 255*/
