#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    char c;
    cin >> c;
    if (c >= 'A' && c <= 'Z')
        cout << "1";
    else if (c >= 'a' && c <= 'z')
        cout << "0";
    else
        cout << "-1";
}
// Input format :
// Single Character
// Output format :
// 1 or 0 or -1
// Constraints :
// Input can be any character
// Sample Input 1 :
// v
// Sample Output 1 :
// 0
// Sample Input 2 :
// V
// Sample Output 2 :
// 1
// Sample Input 3 :
// #
// Sample Output 3 :
// -1