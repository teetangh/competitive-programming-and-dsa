#include <iostream>
#include <string>
using namespace std;

// Intro to Array of strings
// Check a picture for better clarity
int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    // determining the small string
    string smallString = input.substr(1);
    int smallOutputSize = subs(smallString, output);
    
    // Appending the first charcter of current iteration to the array of small strings
    for (int i = 0; i < smallOutputSize; i++)
        output[i + smallOutputSize] = input[0] + output[i];

    return 2 * smallOutputSize;
}

int main(int argc, char const *argv[])
{
    string input;
    cin >> input;

    string *output = new string[1000];
    int count = subs(input, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << endl;

    return 0;
}
