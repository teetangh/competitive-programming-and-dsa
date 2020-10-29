#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int sumOfSubstrings(string n)
{
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = sumOfSubstrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
