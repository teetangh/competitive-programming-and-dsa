#include <iostream>
// #include "solution.h"
using namespace std;

using namespace std;
char highestOccurringChar(char input[])
{
    // Write your code here
    int asciiTable[1000] = {0};
    int max = -99999;
    int maxIndex = -9999;
    for (int i = 0; input[i] != '\0'; i++)
    {
        asciiTable[(int)input[i]]++;
    }

    char ans;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (asciiTable[(int)input[i]] > max)
        {
            max = asciiTable[(int)input[i]];
            ans = input[i];
        }
    }
    return ans;
}
// using namespace std;

// bool isBefore(char []input , char i , char j )
// {

// }
// char highestOccurringChar(char input[]) {
//     // Write your code here
//     int asciiTable[1000]={0};
//     int max = -99999;
//     int maxIndex = -9999;
//     for(int i = 0 ; input [i] != '\0'; i ++)
//     {
//         asciiTable[(int)input[i]]++;
//     }

//     for(int i = 0 ; i < 1000 ; i++)
//     {
//         if(asciiTable[i] != 0 && asciiTable[i] >= max && input[asciiTable[i]] < input[asciiTable[maxIndex]])
//         {
//             max = asciiTable[i];
//             maxIndex = i;
//             cout<<maxIndex<<endl;
//             cout<<max<<endl;
//         }
//     }

//     return maxIndex + NULL;

// }

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    cout << highestOccurringChar(input) << endl;
}
// Sample Input 1:
// abdefgbabfba
// Sample Output 1:
// b
// Sample Input 2:
// xy
// Sample Output 2:
// x