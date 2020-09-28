#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main()
{
    lli bulbs, first, second;
    cin >> bulbs >> first >> second;

    string status;
    cin >> status;

    lli zeroGroups = (status[0] == '0') ? 1 : 0;

    for (lli i = 0; status[i + 1] != '\0'; i++)
    {
        if (status[i] == '1' && status[i + 1] == '0')
        {
            zeroGroups++;
        }
    }

    lli answer;
    if (zeroGroups == 0)
        answer = 0;
    else if (zeroGroups > 0)
        answer = (zeroGroups - 1) * min(first, second) + second;

    // cout << zeroGroups<< endl;
    cout << answer << endl;

    return 0;
}
