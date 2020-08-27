#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

void isSubsequence(string temp1, string temp2)
{
    vector<char> storage_vector;
    storage_vector.clear();

    string smallString, bigString;
    smallString.clear(), bigString.clear();

    if (temp1.size() <= temp2.size())
    {
        smallString = temp1;
        bigString = temp2;
    }
    else
    {
        smallString = temp2;
        bigString = temp1;
    }

    for (int i = 0; i < bigString.size(); i++)
        storage_vector.push_back(bigString[i]);

    vector<char>::iterator itr, prev_itr = storage_vector.begin();
    for (int i = 0; i < smallString.size(); i++)
    {

        itr = find(prev_itr, storage_vector.end(), smallString[i]);
        if (itr < storage_vector.end() && itr >= prev_itr)
        {
            storage_vector.erase(itr);
            prev_itr = itr;
        }

        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;
    string man, woman;
    while (test_cases--)
    {
        cin >> man >> woman;
        isSubsequence(man, woman);
        man.clear(), woman.clear();
    }

    return 0;
}
// // Sample IO
// 8
// john johanna
// ira ira
// kayla jayla
// jack jja
// nohj johanna
// z xyz
// aaa aaa
// kaushik ashik


// YES
// YES
// NO
// NO
// NO
// YES
// YES
// YES
