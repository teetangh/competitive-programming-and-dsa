#include <iostream>
// #include "solution.h"
using namespace std;

/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/

using namespace std;
void minLengthWord(char input[], char output[])
{

    // Write your code here
    int tempCount = 0;
    int tempPointer = 0;

    int mintempCount = 99999;
    int mintempPointer = 0;

    int i, j;
    for (i = 0; input[i] != '\0'; i++)
    {
        // cout << "debug1" << endl;
        tempPointer = i;

        for (j = i + 1; input[j] != ' ' && input[j] != '\0'; j++)
        {
            // cout << "debug2" << endl;
            tempCount++;
        }

        if (tempCount < mintempCount)
        {
            // cout << "debug3" << endl;
            mintempCount = tempCount;
            mintempPointer = tempPointer;
            // cout << input[mintempPointer] << endl;
        }
        tempCount = 0;

        i = j;
    }

    // cout << input[mintempPointer] << endl;
    // cout << mintempCount << endl;
    // cout << input[mintempPointer] << endl;

    int newCount = 0;
    for (i = mintempPointer; newCount <= mintempCount; i++, newCount++)
    {
        output[i - mintempPointer] = input[i];
        // cout << output[i - mintempPointer];
    }
}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << "in main" << endl;
    cout << output << endl;
}
