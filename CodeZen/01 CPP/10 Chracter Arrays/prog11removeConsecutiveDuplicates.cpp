#include <iostream>
// #include "solution.h"
using namespace std;

// input - given string
// You need to update in the input string itself. No need to return or print anything
int length(char input[])
{
    int i = 0;
    int count = 0;
    while (input[i] != '\0')
    {
        ++count;
        i++;
    }
    return count;
}

void removeConsecutiveDuplicates(char input[])
{
    // Write your code here
    int n = length(input);
    for (int i = 0; i < n; i++)
    {
        while (input[i] == input[i + 1] && input[i] != '\0')
        {
            for (int j = i; j < n; j++)
            {
                input[j] = input[j + 1];
            }
        }
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    removeConsecutiveDuplicates(input);
    cout << input << endl;
}
// Sample Input 1:
// aabccbaa
// Sample Output 1:
// abcba
// Sample Input 2:
// xxyyzxx
// Sample Output 2:
// xyzx