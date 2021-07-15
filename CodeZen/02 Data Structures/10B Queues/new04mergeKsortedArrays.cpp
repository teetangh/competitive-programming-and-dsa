#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    priority_queue<int> pq;

    for (auto ele : input)
    {
        for (int i = 0; i < ele->size(); i++)
        {
            pq.push(ele[i]);
        }
    }

    stack<int> s;
    while (!pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        s.push(temp);
    }

    vector<int> temp_output;
    while (!s.empty())
    {
        int temp2 = s.top();
        s.pop();
        temp_output.push_back(temp2);
    }

    return temp_output;
}

int main()
{

    int k;
    cin >> k;
    vector<vector<int> *> input;
    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }
        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    return 0;
}
