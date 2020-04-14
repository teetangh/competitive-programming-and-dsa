#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>

void PairSum(int *input, int n)
{
    unordered_map<int, int> table;

    for (int i = 0; i < n; i++)
        table[input[i]]++;

    for (int i = 0; i < n; i++)
    //for(auto it = table.begin() ; it != table.end() ; it++)
    {
        int curr = input[i];
        int curr_freq = table[curr];
        int freq_of_pair = table[(-1) * (curr)];

        for (int j = 0; j < (curr_freq * freq_of_pair); j++)
        //while(table[it->first] > 0 && table[-(it->first)] > 0)
        {
            if (input[i] < 0)
                cout << input[i] << " " << -1 * input[i] << endl;
            else
                cout << -1 * input[i] << " " << input[i] << endl;

            /*if(it->first < -(it->first))
                cout<<(it->first)<<" "<< (-(it->first))<<endl;
            else
                cout<<(-(it->first))<<" "<<(it->first)<<endl;
         	table[it->first]--;
            table[(-(it->first))]--;
            */
        }
        table[curr] = 0;
        table[(-1) * (curr)] = 0;
    }
}

// void PairSum(int *input, int n)
// {
//     unordered_map<int,int> table;

//     for(int i = 0 ; i < n ; i++)
//         table[input[i]]++;

//     for(auto it = table.begin() ; it != table.end() ; it++)
//     {
//         while(table[it->first] > 0 && table[-(it->first)] > 0)
//         {
//             if(it->first < -(it->first))
//                 cout<<(it->first)<<" "<< (-(it->first))<<endl;
//             else
//                 cout<<(-(it->first))<<" "<<(it->first)<<endl;
//          	table[it->first]--;
//             table[(-(it->first))]--;
//         }
//     }

// }

int main()
{
    int n;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    PairSum(arr, n);
    return 0;
}