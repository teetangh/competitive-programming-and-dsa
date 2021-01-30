// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N, M;
    cin >> N >> M;

    vector<int> start_days(N);
    vector<int> end_days(N);
    int start, end;
    for (int i = 0; i < M; i++)
    {
        cin >> start >> end;

        start_days[start]++;
        end_days[end]++;
    }

    int Q;
    cin >> Q;
    vector<int> queries(Q);

    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    vector<int> boxes(1 + N, 0);
    vector<int> exact_boxes(1 + Q, 0);
    vector<int> atleast_boxes(1 + Q, 0);

    boxes[1] = start_days[1];
    for (int i = 2; i <= N; i++)
        boxes[i] = start_days[i] + boxes[i - 1] - end_days[i - 1];

    // for (auto &ele : boxes)
    //     cout << "DEBUG boxes " << ele << endl;

    for (int i = 1; i <= N; i++)
        exact_boxes[boxes[i]]++;

    // for (auto &ele : exact_boxes)
    //     cout << "DEBUG exact_boxes " << ele << endl;

    atleast_boxes[Q] = exact_boxes[Q];
    for (int i = Q - 1; i >= 0; i--)
        atleast_boxes[i] = exact_boxes[i] + atleast_boxes[i + 1];

    // for (auto &ele : atleast_boxes)
    //     cout << "DEBUG atleast_boxes " << ele << endl;

    for (int i = 0; i < Q; i++)
        cout << atleast_boxes[queries[i]] << endl;
}
