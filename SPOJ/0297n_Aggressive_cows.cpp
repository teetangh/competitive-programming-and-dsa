#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int calculate_minimum_distance(vector<pair<int, bool>> platform_numbers, int cows)
{
    if (cows > platform_numbers.size())
    {
        cout << "error" << endl;
        return -1;
    }

    sort(platform_numbers.begin(), platform_numbers.end());

    // int minimum_distance = 0;
    // for (int i = 0; i < platform_numbers.size() - 1; i++)
    //     for (int j = i; j < platform_numbers.size(); j++)
    //         minimum_distance = abs(platform_numbers[i] - platform_numbers[j]);

    int low = 0;
    int high = platform_numbers.size() - 1;

    int old_mid, new_mid;

    int iterations = cows - 2;
    platform_numbers[0].second = true;
    platform_numbers[platform_numbers.size() - 1].second = true;

    while (iterations--)
    {
        old_mid = new_mid;
        new_mid = (low + high) / 2;

        
    }

    int minimum_distance = new_mid - old_mid;

    return minimum_distance;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    int platforms, cows;

    queue<int> mq;

    while (test_cases--)
    {
        cin >> platforms >> cows;

        vector<pair<int, bool>> platform_numbers;

        int n;
        while (platforms--)
        {
            cin >> n;
            platform_numbers.push_back(std::make_pair(n, false));
        }
        int current_platform_minimum_distance = calculate_minimum_distance(platform_numbers, cows);
        mq.push(current_platform_minimum_distance);
    }
    while (!mq.empty())
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }
    return 0;
}
