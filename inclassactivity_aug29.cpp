#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream inData;
ofstream outData;
const double PI = acos(-1.0);
float radius;
float circumference;
float area;
string fileName;

int main()
{
    cout << "Please input file name: ";
    cin >> fileName;
    ifstream inData(fileName.c_str());
    if (!inData.is_open())
    {
        cout << "File did not open properly.";
        return 1;
    }
    ofstream outData("outData.dat");

    inData >> radius;
    circumference = radius * 2 * PI;
    area = radius * radius * PI;

    cout << "For the first circle, the circumference is: "
         << circumference << " and the area is " << area << endl;

    outData << radius << " " << circumference << " " << area
            << endl;

    inData.close();
    outData.close();

    return 0;
}
