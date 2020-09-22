#include <iostream>
// #include "solution.h"
// using namespace std;

#include <iostream>
#include <string>
using namespace std;

void printHelperFunction(string input, string output)
{
    char leftRecursion, rightRecursion;

    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    leftRecursion = 'a' + (input[0] - 48) - 1;

    bool flag = false;
    if (input[1] != '\0')
    {
        rightRecursion = 'a' + (10 * (input[0] - 48) + (input[1] - 48)) - 1;
        if (rightRecursion >= 'a' && rightRecursion <= 'z')
            flag = true;
    }

    printHelperFunction(input.substr(1), output + leftRecursion);
    string output2 = output + rightRecursion;
    if (flag == true)
    {
        printHelperFunction(input.substr(2), output2);
    }
}

void printAllPossibleCodes(string input)
{
    string output = "";
    printHelperFunction(input, output);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
