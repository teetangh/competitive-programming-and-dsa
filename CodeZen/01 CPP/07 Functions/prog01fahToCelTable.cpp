#include <iostream>
using namespace std;
// #include "Solution.h"

void printTable(int start, int end, int step)
{
    int c;
    for (int i = start; i <= end; i = i + step)
    {
        c = ((i - 32) * ((float)5 / 9));
        cout << i << "\t" << c << endl;
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;

    printTable(start, end, step);
}
// Sample Input 1:
// 0 
// 100 
// 20
// Sample Output 1:
// 0   -17
// 20  -6
// 40  4
// 60  15
// 80  26
// 100 37
// Sample Input 2:
// 120 
// 200 
// 40
// Sample Output 2:
// 120 48
// 160 71
// 200 93
// Explanation for Sample Output 2 :
// Start value is 120, end value is 200 and step size is 40. Therefore, the values we need to convert are 120, 120 + 40 = 160, and 160 + 40 = 200. 
// The formula for converting Fahrenheit to Celsius is:
// Celsius Value = (5/9)*(Fahrenheit Value - 32)  
// Plugging 120 into the formula, the celsius value will be (5 / 9)*(120 - 32) => (5 / 9) * 88 => (5 * 88) / 9 => 440 / 9 => 48.88
// But we'll only print 48 because we are only interested in the integral part of the value.