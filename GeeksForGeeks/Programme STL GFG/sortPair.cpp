#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, char>> myVector;

    int num;
    cin >> num;

    int m;
    char n;
    for (int i = 0; i < num; i++)
    {
        cin >> m >> n;
        myVector.push_back(make_pair(m, n));
    }

    cout << "After Sorting" << endl;
    sort(myVector.begin(), myVector.end());

    for (auto &elm : myVector)
        cout << elm.first << " " << elm.second << endl;
}