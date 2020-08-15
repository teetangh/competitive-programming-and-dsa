#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 4, 5, 6, 5};
    unordered_map<int, int> mp;

    for (int i = 0; i < 7; i++)
        mp[arr[i]] = mp[arr[i]] + 1; //  mp[arr[i]]++

    unordered_map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " :" << it->second << endl;

    cout << endl;
    mp.erase(1);
    // unordered_map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " :" << it->second << endl;
}
