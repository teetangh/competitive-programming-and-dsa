// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<string> customSplit(string s, char delim)
{
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim))
        tokens.push_back(item);

    return tokens;
}

int scanRemaining(int minTokens, vector<string> tokens1, vector<string> tokens2)
{
    auto remainingTokens = (tokens1.size() > tokens2.size()) ? tokens1 : tokens2;

    for (int i = minTokens; i < remainingTokens.size(); i++)
    {
        for (int j = 0; j < remainingTokens[i].size(); j++)
            if (remainingTokens[i][j] != '0')
                return false;
    }

    return true;
}

int compareSection(string a, string b)
{
    int x, y;
    x = y = 0;

    string currA;
    string currB;

    bool leadZero = true;
    for (x = 0; a[x] != '\0'; x++)
    {
        if (a[x] == '0' && leadZero)
            continue;
        currA += a[x];
        leadZero = false;
    }

    leadZero = true;
    for (y = 0; b[y] != '\0'; y++)
    {
        if (b[y] == '0' && leadZero)
            continue;
        currB += b[y];
        leadZero = false;
    }

    if (currA.size() > currB.size())
        return 1;
    else if (currA.size() < currB.size())
        return -1;

    x = y = 0;
    while (currA[x] == currB[y])
    {
        if (currA[x] == '\0')
            return 0;
        x++, y++;
    }

    if (currA[x] > currB[y])
        return 1;
    else if (currA[x] < currB[y])
        return -1;

    return 0;
}

int compareVersion(string version1, string version2)
{
    vector<string> tokens1 = customSplit(version1, '.');
    vector<string> tokens2 = customSplit(version2, '.');

    int minTokens = min(tokens1.size(), tokens2.size());
    int maxTokens = max(tokens1.size(), tokens2.size());
    bool equalLengthTokens = (tokens1.size() == tokens2.size());

    for (int i = 0; i < maxTokens; i++)
    {
        auto currentSectionResult = compareSection(tokens1[i], tokens2[i]);
        if (currentSectionResult != 0)
            return currentSectionResult;

        else if (i == minTokens - 1 && !equalLengthTokens)
        {
            if (scanRemaining(minTokens, tokens1, tokens2))
                return 0;
            else
                return (tokens1.size() > tokens2.size()) ? 1 : -1;
        }
    }

    return 0;
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

    string version1, version2;
    while (tc--)
    {
        cin >> version1 >> version2;
        cout << version1 << " " << version2 << endl;
        cout << compareVersion(version1, version2) << endl;
        cout << endl;
    }
}
// // Sample IO
// 10


// 70809
// 9051

// 2
// 4

// 000.0000.00.1
// 000.00.1

// 01
// 1

// 4444371174137455
// 5.168

// 0000001
// 0001

// 1.0
// 1

// 1.0.0
// 1

// 23.12.3
// 23.125.66

// 123.45
// 12.345


// // OUTPTUT
// 70809 9051
// 1

// 2 4
// -1

// 000.0000.00.1 000.00.1
// -1

// 01 1
// 0

// 4444371174137455 5.168
// 1

// 0000001 0001
// 0

// 1.0 1
// 0

// 1.0.0 1
// 0

// 23.12.3 23.125.66
// -1

// 123.45 12.345
// 1
