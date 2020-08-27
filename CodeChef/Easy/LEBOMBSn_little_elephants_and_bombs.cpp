#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

typedef long long int lli;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

lli safe_buildings(string bomb_array, lli buildings)
{
    // if (stoi(bomb_array) || 0 == 0)
    //     return buildings;

    bool flag_all_0 = true;
    for (lli i = 0; i < bomb_array.size(); i++)
    {
        if (bomb_array[i] == '1')
        {
            flag_all_0 = false;
            break;
        }
    }
    if (flag_all_0 == true)
        return buildings;

    vector<bool> safe_buildings(bomb_array.size());

    if (bomb_array[0] != '1' && bomb_array[1] != '1')
        safe_buildings[0] = true;

    if (bomb_array[bomb_array.size() - 2] != '1' && bomb_array[bomb_array.size() - 1] != '1')
        safe_buildings[safe_buildings.size() - 1] = true;

    for (lli i = 1; i < bomb_array.size() - 1; i++)
    {
        if (bomb_array[i - 1] != '1' && bomb_array[i] != '1' && bomb_array[i + 1] != '1')
            safe_buildings[i] = true;
    }

    lli count = 0;
    for (lli i = 0; i < safe_buildings.size(); i++)
    {
        if (safe_buildings[i] == true)
            count++;
    }

    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    lli test_cases;
    cin >> test_cases;

    string temp;
    while (test_cases--)
    {
        lli buildings;
        cin >> buildings;
        string bomb_array;
        cin >> bomb_array;
        cout << safe_buildings(bomb_array, buildings) << endl;
    }
}
