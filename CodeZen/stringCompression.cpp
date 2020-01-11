#include <iostream>
// #include "solution.h"
using namespace std;
// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

void stringCompression(char input[])
{
    int i, j, k;
    int count = 0;
    for (i = 0; input[i] != '\0';)
    {
        if (input[i] != input[i + 1])
        {
            i++;
        }
        else
            while (input[i] == input[i + 1])
            {
                for (j = i; input[j] == input[i] && input[j] != '\0'; j++)
                {
                    ++count;
                    input[j] = input[j + 1];
                }
                cout << count << " ";
                input[i + 1] = count;
                count = 0;
                i = i + 2;
            }
    }
}
int main()
{
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}
