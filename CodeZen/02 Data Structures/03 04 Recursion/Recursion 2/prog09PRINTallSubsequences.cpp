#include <iostream>
using namespace std;

// Printing rather than returning
// 1. to save the exponential size of the 2^n array of strings
// 2. no need to return count
void print_subs(string input, string output)
{
    // Base Case
    // Print the result when the input length is 0f
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    // Recursive Call
    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output + input[0]);
}

int main()
{
    string input;
    cin >> input;

    string output = "";
    print_subs(input, output);
}