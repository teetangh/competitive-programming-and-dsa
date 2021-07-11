// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> getRow(int A)
{

    if (A == 0)
        return std::vector<int>{1};
    else if (A == 1)
        return std::vector<int>{1, 1};
    else if (A == 2)
        return std::vector<int>{1, 2, 1};

    std::vector<int> v = getRow(A - 1);

    vector<int> tempVector(v);
    // tempVector.pop_back();

    for (int i = 1; i < v.size() - 1;)
    {
        if(v.size() % 2 != 0)
        {
            tempVector[i] = v[i] 
        }
        else{

        }
    }

    return tempVector;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        int num;
        cin >> num;
        vector<int> answer = getRow(num);
        cout << num << " of size " << answer.size() << " : ";
        for (auto ele : answer)
            cout << ele << " ";
        cout << endl;
    }
}
    