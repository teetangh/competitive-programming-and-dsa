// Includes
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

class worker
{
public:
    int Ti;
    int Xi;
    int Yi;
};

bool custom(const worker &w1, const worker &w2)
{
    if (w1.Ti < w2.Ti)
        return true;
    else
    {
        double profit1 = w1.Yi / w1.Xi;
        double profit2 = w2.Yi / w2.Xi;
        if (profit1 < profit2)
            return true;
        else if (profit1 == profit2)
            return w1.Yi > w2.Yi;
        else
            return false;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N, D;
    cin >> N >> D;

    vector<worker> painters(N);

    for (int i = 0; i < N; i++)
        cin >> painters[i].Ti >> painters[i].Xi >> painters[i].Yi;

    sort(painters.begin(), painters.end(), custom);

    int time = 0;

    while(true)
    {
        if(painters[i].Ti <= time)

        time++;
    }

}
