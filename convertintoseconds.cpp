
#include <iostream>

using namespace std;
int main ()
{
    int days,weeks;
    int totalWeeks,dayRemain;
    cout<< "Enter days:";
    cin >>days;

    totalWeeks= days/7;
    dayRemain=days%7;
    cout<< "Total of weeks is "<< totalWeeks;
    cout<< "The number of days remaining are:"<<dayRemain;
return 0;
}
