#include <iostream>
#include <string.h>
using namespace std;

// input - given string
// Update in the given input itself. No need to return or prik anything

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

void reverseEachWord(char input[])
{
    // Write your code here
    int n = length(input);
    int i, j, k;
    char temp;
    for (i = 0; input[i] != '\0';)
    {
        for (j = i; input[j] != '\0'; j++)
        {
            // std::cout << "@ i " << i << " j " << j << " k " << k << " \n ";
            if (input[j] == ' ')
                break;
        }
        for (k = i; k < ((j + i) / 2); k++)
        {
            // std::cout << "$ i " << i << " j " << j << " k " << k << " \n ";
            temp = input[k];
            input[k] = input[i + j - k - 1];
            input[i + j - k - 1] = temp;
        }
        i = j + 1;
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// emocleW ot gnidoC sajniN
// Sample Input 2:
// Give proper names to variables and functions
// Sample Output 2:
// eviG reporp seman ot selbairav dna snoitcnuf