#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

int returnPermutations(string input, string output[])
{
    /* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
