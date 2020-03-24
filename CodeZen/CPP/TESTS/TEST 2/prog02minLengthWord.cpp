#include <iostream>
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
    cout << output << endl;
}
