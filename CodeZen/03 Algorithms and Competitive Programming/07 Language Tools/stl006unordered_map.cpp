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
    unordered_map<int, int> ump;

    for (int i = 0; i < 7; i++)
        ump[arr[i]] = ump[arr[i]] + 1; //  ump[arr[i]]++

    unordered_map<int, int>::iterator it;
    for (it = ump.begin(); it != ump.end(); it++)
        cout << it->first << " :" << it->second << endl;

    cout << endl;
    ump.erase(1);
    // unordered_map<int, int>::iterator it;
    for (it = ump.begin(); it != ump.end(); it++)
        cout << it->first << " :" << it->second << endl;
}
