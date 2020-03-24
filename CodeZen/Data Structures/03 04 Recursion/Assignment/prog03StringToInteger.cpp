#include <iostream>
// #include "solution.h"
using namespace std;

using namespace std;

int length(char input[])
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
        count++;
    return count;
}
int stringToNumber(char input[])
{
    int n = length(input);
    int smallAns;
    int powerof10 = 1;
    for (int i = 1; i < n; i++)
        powerof10 *= 10;
    if (n == 1)
    {
        smallAns = ((int)input[0] - 48);
        return smallAns;
    }

    else
    {
        smallAns = ((int)input[0] - 48);
        return (smallAns * powerof10) + stringToNumber(input + 1);
    }
}
// int stringToNumber(char input[]) {
//     // Write your code here

//     if(input[0] == '\0')
//         return
//     if(input[0]!='\0' && input[1]!='\0')
//     {
//         cout<<(int)(input[0] - 48);
//         stringToNumber(input+1);
//     }
//     else if(input[0]!='\0' && input[1] =='\0')
//     {
//         cout<<(int)(input[0] - 48);
//         cout<<'\0';
//     }
// }

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
