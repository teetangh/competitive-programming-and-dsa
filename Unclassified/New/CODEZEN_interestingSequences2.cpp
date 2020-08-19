#include <bits/stdc++.h>
using namespace std;

int cost(int n, int k, int l, vector<int> v1)
{
    int count = 0;
    if (std::equal(v1.begin() + 1, v1.end(), v1.begin()))
    {
        return 0;
    }
    int max_element = *max_element(v1.begin(), v1.end());
    int min_element = *min_element(v1.begin(), v1.end());
    int cost_range = max_element - min_element + 1;
    int increasing = 0;
    int decreasing = 0;
    for (int i = min_element; i <= max_element; i++)
    {
    }
}

int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    cost(n, k, l, v1);
    // Write your code here
}