#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_continuous_subset(vector<int> marble_values, int target)
{
    int left, right;
    left = right = 0;

    int current_sum = marble_values[0];
    while (current_sum < target && right <= marble_values.size() - 1)
    {
        if (current_sum == target)
            break;
        right++;
        current_sum += marble_values[right];
    }

    while (current_sum < target && left <= marble_values.size() - 1)
    {
        if (current_sum == target)
            break;
        int old_left = left;
        left++;
        current_sum -= marble_values[old_left];
    }

    if (current_sum == target)
        cout << "true" << endl;
    else
    {
        cout << "false" << endl;
        return;
    }

    for (int i = left; i <= right; i++)
        cout << marble_values[i] << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int marbles, target;
    cin >> marbles >> target;

    vector<int> marble_values(marbles);
    int n;
    for (int i = 0; i < n; i++)
    {
        cin >> n;
        marble_values[i] = n;
    }

    print_continuous_subset(marble_values, target);
    return 0;
}