#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_continuous_subset(vector<int> marble_values, int target)
{
    int left, right;
    left = right = 0;

    int current_sum = marble_values[0];

    while (left < marble_values.size() && right < marble_values.size())
    {
        if (current_sum == target)
            break;
        else if (current_sum < target)
        {
            right++;
            current_sum += marble_values[right];
        }
        else
        {
            int old_left = left;
            left++;
            current_sum -= marble_values[old_left];
        }
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
    for (int i = 0; i < marbles; i++)
    {
        cin >> n;
        marble_values[i] = n;
    }

    print_continuous_subset(marble_values, target);
    return 0;
}

// // Sample IO 1
// 8 600 
// 319 349 959 637 178 750 322 278


// true
// 322 278 

// // Sample IO 2
// 5 5
// 1 5 3 2 4

// true
// 5 