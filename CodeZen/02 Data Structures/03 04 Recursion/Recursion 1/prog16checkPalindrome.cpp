#include <iostream>
// #include "solution.h"
using namespace std;

using namespace std;
int length(char input[])
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool checkPalindrome(char input[])
{
    // Write your code here
    int n = length(input);
    if (n == 2 && (input[0] == input[1]))
        return true;
    else if (n == 1)
        return true;

    char *temp = new char[n - 2];

    for (int i = 1; i <= n - 2; i++)
        temp[i - 1] = input[i];

    if (input[0] == input[n - 1])
    {
        // for (int j = 0 ; temp[j]!= '\0' ; j ++)
        //     cout<<temp[j];
        // cout<<endl;
        return checkPalindrome(temp);
    }
    else
        return false;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
