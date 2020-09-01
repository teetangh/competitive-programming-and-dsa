// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int arr_size, rotation;
    cin >> arr_size >> rotation;
    vector<int> vec(arr_size);
    for (int i = 0; i < arr_size; i++)
        cin >> vec[i];

    vector<int> vec2;
    int i;
    for (i = rotation; i < vec.size(); i++)
        vec2.emplace_back(vec[i]);
    for (i = 0; i < rotation; i++)
        vec2.emplace_back(vec[i]);

    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << " ";
}
