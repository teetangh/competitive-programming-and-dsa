#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> removeDuplicates2(vector<int> input)
{
    vector<int> result;
    sort(input.begin(), input.end());

    // Since array out of bounds for input[i-1]
    result.push_back(input[0]);

    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] != input[i - 1])
            result.push_back(input[i]);
    }

    return result;
}

vector<int> removeDuplicates(vector<int> input)
{
    set<int> s;
    vector<int> result;

    for (int i = 0; i < input.size(); i++)
    {
        if (s.find(input[i]) == s.end())
        {
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < input.size(); i++)
        cin >> input[i];

    vector<int> output = removeDuplicates(input);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << endl;
    vector<int> output2 = removeDuplicates2(input);
    for (int i = 0; i < output2.size(); i++)
        cout << output2[i] << " ";
    return 0;
}
