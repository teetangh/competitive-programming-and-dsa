#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Write your code here
    float basic, hra, da, allow, pf;
    float totalSalary;
    char grade;

    cin >> basic >> grade;

    hra = (float)(0.2 * basic);
    da = (float)(0.5 * basic);

    if (grade == 'A')
        allow = 1700;
    else if (grade == 'B')
        allow = 1500;
    else
        allow = 1300;

    pf = (float)(0.11 * basic);
    totalSalary = (basic + hra + da + allow - pf);
    cout << (int)round(totalSalary);

    return 0;
}
// Sample Input 1 :
// 10000 A
// Sample Output 1 :
// 17600
// Sample Input 2 :
// 4567 B
// Sample Output 2 :
// 8762